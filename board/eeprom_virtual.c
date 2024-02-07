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
//static uint32_t _nbOfVar;
//static uint32_t _lastWriteAddress;

/* Easier access to eeprom pages definitions */
//static const EEPROM_PAGE eepromPages[] = {{PAGE0_BASE_ADDRESS, PAGE0_END_ADDRESS},  //, PAGE0_ID},
//                                          {PAGE1_BASE_ADDRESS, PAGE1_END_ADDRESS}}; //, PAGE1_ID}};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
//static uint16_t      EE_FindValidPage(void);

/**
  *   Restore the pages to a known good state in case of page's status
  *   corruption after a power loss.
  *//*
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
*/
/**
  * @brief  Find valid Page
  *//*
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
}*/
/**
  * @brief  Erases PAGE and PAGE1 and writes VALID_PAGE header to PAGE
  *//*
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
}*/
