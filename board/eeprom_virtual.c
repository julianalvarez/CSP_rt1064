/*
 * eeprom_virtual.c
 *
 *  Created on: 7 feb. 2024
 *      Author: PLANTIUM
 */


/* Includes ------------------------------------------------------------------*/
#include "eeprom_virtual.h"
#include "sflash_W25Q32JV.h"
#include "can.h"

/* Defines -------------------------------------------------------------------*/
#define ADDRESS_INVALID         0xFFFFFFFF
#define MAX_NRO_OF_VAR          1024

/* Private typedef -----------------------------------------------------------*/
typedef struct EEPROM_PAGE_t {
    uint32_t pageStart;
    uint32_t pageEnd;
} EEPROM_PAGE;

typedef enum PAGE_STATUS_t {                /* Page status definitions */
    ERASED          = ((uint16_t)0xFFFF),   /* Page is empty */
    RECEIVE_DATA    = ((uint16_t)0xEEEF),   /* Page is marked to receive data */
    VALID_PAGE      = ((uint16_t)0xEEEE),   /* Page containing valid data */
    TO_DELETE       = ((uint16_t)0x0000),   /* Page should be descarded on next read */
} PAGE_STATUS;

/* Global variable used to store variable value in read sequence */
static uint32_t _nbOfVar;
static uint32_t _lastWriteAddress;

/* Easier access to eeprom pages definitions */
static const EEPROM_PAGE eepromPages[] = {{PAGE0_BASE_ADDRESS, PAGE0_END_ADDRESS},  //, PAGE0_ID},
                                          {PAGE1_BASE_ADDRESS, PAGE1_END_ADDRESS}}; //, PAGE1_ID}};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
__RAMFUNC(RAM2) static uint16_t      		EE_FindValidPage(void);
__RAMFUNC(RAM2) static EEPROM_RESULT 		EE_VerifyBlankPage(uint16_t sectorIdx);
__RAMFUNC(RAM2) static EEPROM_RESULT 		EE_PageTransfer(void);
__RAMFUNC(RAM2) static EEPROM_RESULT 		EE_VerifyValidPageFull(void);
__RAMFUNC(RAM2) static EEPROM_RESULT 		EE_VerifyPageFullWriteVariable(uint16_t destinationPage, uint16_t VirtAddress, uint16_t Data);

/**
  *   Restore the pages to a known good state in case of page's status
  *   corruption after a power loss.
  */
EEPROM_RESULT EE_Init(uint32_t nbOfVar)
{
    uint16_t validPage, secondaryPage;
    uint16_t validPageStatus;
    int32_t flashStatus;

    _lastWriteAddress = ADDRESS_INVALID;

    SFLASH_init();

    // Initialize static variable
    _nbOfVar = (nbOfVar > MAX_NRO_OF_VAR) ? MAX_NRO_OF_VAR : nbOfVar;
    validPage = EE_FindValidPage();

    // Verify eeprom is in valid state
    if (validPage > 1) {
        return EE_Format();
    } else {
        if (validPage == 0) {
            secondaryPage = 1;
        } else {
            secondaryPage = 0;
        }

        if (EE_VerifyBlankPage(secondaryPage) != RESULT_OK) {
            flashStatus = Erase_FLASH(eepromPages[secondaryPage].pageStart,PAGE_SIZE);
            if (flashStatus != FLASH_COMPLETE) {
                return RESULT_ERROR;
            }
        }

        validPageStatus = *(uint16_t*)eepromPages[validPage].pageStart;
        if (validPageStatus == TO_DELETE) { // If page is in this state, system was shut down badly
            return EE_PageTransfer();
        }

        if (validPageStatus != VALID_PAGE) {
            // Mark validPage as valid
            flashStatus = WriteWord_FLASH(eepromPages[validPage].pageStart, VALID_PAGE);
            if (flashStatus != FLASH_COMPLETE) {
                return RESULT_NOT_VALID_PAGE;
            }
        }

        if (EE_VerifyValidPageFull() == RESULT_PAGE_FULL) {
            return EE_PageTransfer();
        }

        return RESULT_OK;
    }
}

/**
  * @brief  Find valid Page
  */
static uint16_t EE_FindValidPage(void)
{
    uint16_t PageStatus0, PageStatus1;

    // Get Page0 actual status
    PageStatus0 = (*(uint16_t*)eepromPages[0].pageStart);

    // Get Page1 actual status
    PageStatus1 = (*(uint16_t*)eepromPages[1].pageStart);

    if (PageStatus0 == VALID_PAGE) {
        if (PageStatus1 == VALID_PAGE) {
            return 0xFFFF;
        } else {
            return 0;
        }
    } else if (PageStatus1 == VALID_PAGE) {
        return 1;
    } else if (PageStatus0 == RECEIVE_DATA) {
        if (PageStatus1 == RECEIVE_DATA) {
            return 0xFFFF;
        } else {
            return 0;
        }
    } else if (PageStatus1 == RECEIVE_DATA) {
        return 1;
    } else if (PageStatus0 == TO_DELETE) {
        if (PageStatus1 == TO_DELETE) {
            return 0xFFFF;
        } else {
            return 0;
        }
    } else if (PageStatus1 == TO_DELETE) {
        return 1;
    }

    return 0xFFFF;
}
/**
  * @brief  Erases PAGE and PAGE1 and writes VALID_PAGE header to PAGE
  */
EEPROM_RESULT EE_Format(void)
{
    FLASH_Status flashStatus;

    // Erase
    flashStatus = Erase_FLASH(eepromPages[0].pageStart,PAGE_SIZE);
    if (flashStatus != FLASH_COMPLETE) {
        return RESULT_ERROR;
    }
    flashStatus = Erase_FLASH(eepromPages[1].pageStart,PAGE_SIZE);
    if (flashStatus != FLASH_COMPLETE) {
        return RESULT_ERROR;
    }

    // Set Page0 as valid page
    flashStatus = WriteWord_FLASH(eepromPages[0].pageStart, VALID_PAGE);
    if (flashStatus != FLASH_COMPLETE) {
        return RESULT_ERROR;
    }

    return RESULT_OK;
}

/**
  * @brief  Verifies if the indicated page is empty
  */
static EEPROM_RESULT EE_VerifyBlankPage(uint16_t sectorIdx)
{
    uint32_t address, endAddress;

    if (sectorIdx > 1) {
        return RESULT_ERROR;
    }

    endAddress = eepromPages[sectorIdx].pageEnd;
    for (address = eepromPages[sectorIdx].pageStart; address < endAddress; address += 4) {
        if (*(uint32_t*)address != 0xFFFFFFFF) {
            return RESULT_ERROR;
        }
    }

    return RESULT_OK;
}

static EEPROM_RESULT EE_PageTransfer(void)
{
    uint16_t validPage, destinationPage;
    FLASH_Status flashStatus;
    EEPROM_RESULT eepromStatus;
    uint32_t varIdx;
    uint16_t varData;

    validPage = EE_FindValidPage();

    if (validPage == 0) {
        destinationPage = 1;
    } else if (validPage == 1) {
        destinationPage = 0;
    } else {
        // valid page not found
        return RESULT_NOT_FOUND;
    }

    // Clear destination page
    if (EE_VerifyBlankPage(destinationPage) != RESULT_OK) {
        flashStatus = Erase_FLASH(eepromPages[destinationPage].pageStart,PAGE_SIZE);
        if (flashStatus != FLASH_COMPLETE) {
            return RESULT_ERROR;
        }
    }
    /* Transfer process: transfer variables from old to the new active page */
    _lastWriteAddress = ADDRESS_INVALID;
    for (varIdx = 0; varIdx < _nbOfVar; varIdx++) {
        eepromStatus = EE_ReadVariable(varIdx, &varData);
        if (eepromStatus == RESULT_OK) {
            eepromStatus = EE_VerifyPageFullWriteVariable(destinationPage, varIdx, varData);
            if (eepromStatus != RESULT_OK) {
                return eepromStatus;
            }
        }
    }
    /* Set the new Page status to RECEIVE_DATA status */
    flashStatus = WriteWord_FLASH(eepromPages[destinationPage].pageStart, RECEIVE_DATA);
    if (flashStatus != FLASH_COMPLETE) {
        return RESULT_ERROR;
    }

    /* Erase the old Page: Set old Page status to ERASED status */
    flashStatus = WriteWord_FLASH(eepromPages[validPage].pageStart, TO_DELETE);
    if (flashStatus != FLASH_COMPLETE) {
        return RESULT_ERROR;
    }
    flashStatus = Erase_FLASH(eepromPages[validPage].pageStart,PAGE_SIZE);
    if (flashStatus != FLASH_COMPLETE) {
        return RESULT_ERROR;
    }

    /* Set new Page status to VALID_PAGE status */
    flashStatus = WriteWord_FLASH(eepromPages[destinationPage].pageStart, VALID_PAGE);
    if (flashStatus != FLASH_COMPLETE) {
        return RESULT_ERROR;
    }

    return RESULT_OK;
}
static EEPROM_RESULT EE_VerifyValidPageFull(void)
{
    uint16_t validPage;

    validPage = EE_FindValidPage();
    if (validPage > 1) {
        return RESULT_ERROR;
    }

#if USE_REDUCED_PAGE_SIZE
    if (*(uint32_t*)(eepromPages[validPage].pageStart + 0x50) == 0xFFFFFFFF) {
#else
    if (*(uint32_t*)(eepromPages[validPage].pageEnd - 4) == 0xFFFFFFFF) {
#endif
        return RESULT_OK;
    } else {
        return RESULT_PAGE_FULL;
    }
}

/**
  * @brief  Returns the last stored variable data, if found, which correspond to
  *   the passed virtual address
  */
EEPROM_RESULT EE_ReadVariable(uint16_t virtAddress, uint16_t* data)
{
	uint16_t validPage;
	uint16_t addressValue;
	uint32_t address, pageStartAddress;

	/* Get active Page for read operation */
	validPage = EE_FindValidPage();
	if (validPage > 1) {
		return  RESULT_NOT_VALID_PAGE;
	}

	if (virtAddress > _nbOfVar){
		return  RESULT_NOT_FOUND;
	}

	/* Get the valid Page start end Address */
	pageStartAddress = eepromPages[validPage].pageStart;

	/* Check each active page address starting from end */
	for (address = eepromPages[validPage].pageEnd - 2; address > pageStartAddress; address -= 4) {
		addressValue = (*( uint16_t*)address);
		if (addressValue == virtAddress) {
			/* Get content of Address-2 which is variable value */
			*data = (*( uint16_t*)(address - 2));
			return RESULT_OK;
		}
	}
	return RESULT_NOT_FOUND;
}

/**
  * @brief  Writes/upadtes variable data in EEPROM.
  */
EEPROM_RESULT EE_WriteVariable(uint16_t VirtAddress, uint16_t Data)
{
    EEPROM_RESULT status;

    if (VirtAddress > _nbOfVar){
        return  RESULT_NOT_FOUND;
    }

    /* Write the variable virtual address and value in the EEPROM valid page */
    status = EE_VerifyPageFullWriteVariable(EE_FindValidPage(), VirtAddress, Data);
    if (status == RESULT_PAGE_FULL) { // Cannot write, page full
        status = EE_PageTransfer();
        if (status != RESULT_OK) {
            return RESULT_ERROR;
        }
        // If write said page full, it didn't write value
        status = EE_VerifyPageFullWriteVariable(EE_FindValidPage(), VirtAddress, Data);
    }

    if (status != RESULT_OK) {
        return RESULT_ERROR;
    }

    /* In case the EEPROM active page is full perform page transfer */
    if (EE_VerifyValidPageFull() == RESULT_PAGE_FULL) { // Variable written and resulted in page full
        status = EE_PageTransfer();
    }

    return status;
}

/**
  * @brief  Write variable
  */
static EEPROM_RESULT EE_VerifyPageFullWriteVariable(uint16_t destinationPage, uint16_t VirtAddress, uint16_t Data)
{
    FLASH_Status flashStatus;
    uint32_t address, endAddress;

    if (destinationPage >= 2) {
        return RESULT_ERROR;
    }

    address = _lastWriteAddress;
    if (_lastWriteAddress == ADDRESS_INVALID){
        address = eepromPages[destinationPage].pageStart + 4; // Reserve space at beginning for page status
    }
    endAddress = eepromPages[destinationPage].pageEnd;

    /* Check each active page address starting from begining */
    while (address < endAddress) {
        if ((*(uint32_t*)address) == 0xFFFFFFFF) {
            flashStatus = WriteWord_FLASH(address, Data);
            if (flashStatus != FLASH_COMPLETE) {
                return RESULT_ERROR;
            }
            /* Set variable virtual address */
            flashStatus = WriteWord_FLASH(address + 2, VirtAddress);
            if (flashStatus != FLASH_COMPLETE) {
                return RESULT_ERROR;
            } else {
                _lastWriteAddress = address + 4;
                return RESULT_OK;
            }
        } else {
            /* Next address location */
            address = address + 4;
        }
    }

    return RESULT_PAGE_FULL; // Cannot use verify page full as it always checks valid page
}
