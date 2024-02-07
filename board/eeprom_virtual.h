/*
 * eeprom_virtual.h
 *
 *  Created on: 7 feb. 2024
 *      Author: PLANTIUM
 */

#ifndef EEPROM_VIRTUAL_H_
#define EEPROM_VIRTUAL_H_

/* Includes ------------------------------------------------------------------*/
#include "types.h"

/* Defines -------------------------------------------------------------------*/
typedef enum EEPROM_RESULT_t {
    RESULT_OK               = (uint16_t) 0,
    RESULT_NOT_FOUND        = (uint16_t) 1,
    RESULT_NOT_INIT         = (uint16_t) 2,
    RESULT_NOT_VALID_PAGE   = (uint16_t) 3,
    RESULT_ERROR            = (uint16_t) 4,
    RESULT_PAGE_FULL        = (uint16_t) 5,
} EEPROM_RESULT;

/* Define the size of the sectors to be used */
//#define PAGE_SIZE               (uint32_t)0x8000  /* Page size = 32KByte */
//#define SECTOR_SIZE             (uint32_t)0x10000

/* EEPROM start address in Flash */
//#define EEPROM_START_ADDRESS  ((uint32_t)0x70080000) /* EEPROM emulation start address:
//                                                       Sectors 5 and 6. 16kB each */

/* Pages 0 and 1 base and end addresses *//*
#define PAGE0_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + 0x0000))
#define PAGE0_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + PAGE_SIZE))

#define PAGE1_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + SECTOR_SIZE))
#define PAGE1_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (SECTOR_SIZE + PAGE_SIZE)))*/

/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
EEPROM_RESULT   EE_Init(uint32_t nbOfVar);
EEPROM_RESULT   EE_Format(void);

#endif /* EEPROM_VIRTUAL_H_ */
