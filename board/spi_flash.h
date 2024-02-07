/*
 * spi_flash.h
 *
 *  Created on: 22 ene. 2024
 *      Author: PLANTIUM
 */

#ifndef SPI_FLASH_H_
#define SPI_FLASH_H_

#include <stdint.h>
#include "fsl_flexspi.h"
#include "peripherals.h"
#include "board.h"
#include "pin_mux.h"
#include "fsl_cache.h"
#include "fsl_debug_console.h"
#include <cr_section_macros.h>

#define FLASH_PORT                      		kFLEXSPI_PortA1
#define FLASH_BUSY_STATUS_POL    				1
#define FLASH_BUSY_STATUS_OFFSET 				0
#define FLASH_PAGE_SIZE                 		256
#define FLASH_QUAD_ENABLE       				0x40
#define CUSTOM_LUT_LENGTH        				60
#define EXAMPLE_FLEXSPI_AMBA_BASE       		FlexSPI2_AMBA_BASE
#define SECTOR_SIZE                    			0x1000 // 4K
#define EXAMPLE_SECTOR                  		128

#define BOARD_FLEXSPI							FLEXSPI2

#define NOR_CMD_LUT_SEQ_IDX_READ_NORMAL        	0
#define NOR_CMD_LUT_SEQ_IDX_READ_FAST          	1
#define NOR_CMD_LUT_SEQ_IDX_READ_FAST_QUAD     	2
#define NOR_CMD_LUT_SEQ_IDX_READSTATUS         	3
#define NOR_CMD_LUT_SEQ_IDX_WRITEENABLE        	4
#define NOR_CMD_LUT_SEQ_IDX_ERASESECTOR        	5
#define NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM_SINGLE 	6
#define NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM_QUAD   	7
#define NOR_CMD_LUT_SEQ_IDX_READID            	8
#define NOR_CMD_LUT_SEQ_IDX_WRITESTATUSREG     	9
#define NOR_CMD_LUT_SEQ_IDX_ENTERQPI           	10
#define NOR_CMD_LUT_SEQ_IDX_EXITQPI            	11
#define NOR_CMD_LUT_SEQ_IDX_READSTATUSREG      	12
#define NOR_CMD_LUT_SEQ_IDX_ERASECHIP          	13

typedef struct _flexspi_cache_status
{
    volatile bool DCacheEnableFlag;
    volatile bool ICacheEnableFlag;
} flexspi_cache_status_t;

// Enums **********************************************************************
typedef enum
{
  FLASH_COMPLETE = 0,
  FLASH_BUSY = 1,
  FLASH_ERROR_RD,
  FLASH_ERROR_PGS,
  FLASH_ERROR_PGP,
  FLASH_ERROR_PGA,
  FLASH_ERROR_WRP,
  FLASH_ERROR_PROGRAM,
  FLASH_ERROR_OPERATION
}FLASH_Status;

__RAMFUNC(RAM2) void		SPIFLASH_init(void);
__RAMFUNC(RAM2) status_t 	SPIFLASH_erase_sector(FLEXSPI_Type *base, uint32_t address);
__RAMFUNC(RAM2) int8_t 		SPIFLASH_WriteByte(FLEXSPI_Type *base, uint32_t dstAddr, uint8_t Data);
__RAMFUNC(RAM2) int8_t 		WriteWord_FLASH (uint32_t Address, uint16_t Data);
__RAMFUNC(RAM2) int8_t 		SPIFLASH_ReadByte (uint32_t Address, uint8_t* pData, uint32_t Size);
__RAMFUNC(RAM2) status_t	SPIFLASH_read(FLEXSPI_Type *base, uint32_t dstAddr, const uint32_t *src, uint32_t length);



#endif /* SPI_FLASH_H_ */
