/*
 * spi_flash.c
 *
 *  Created on: 22 ene. 2024
 *      Author: PLANTIUM
 */


#include <sflash_W25Q32JV.h>

__RAMFUNC(RAM2) status_t _wait_bus_busy(FLEXSPI_Type *base);
__RAMFUNC(RAM2) void _enable_cache(flexspi_cache_status_t cacheStatus);
__RAMFUNC(RAM2) void _disable_cache(flexspi_cache_status_t *cacheStatus);
__RAMFUNC(RAM2) status_t _write_enable(FLEXSPI_Type *base, uint32_t baseAddr);
__RAMFUNC(RAM2) status_t _enable_quad_mode(FLEXSPI_Type *base);
__RAMFUNC(RAM2) status_t _get_vendor_id(FLEXSPI_Type *base, uint8_t *vendorId);


const uint32_t FLEXSPI_customLUT[CUSTOM_LUT_LENGTH] = {
		 /* Fast read quad mode - SDR */
		 [4 * NOR_CMD_LUT_SEQ_IDX_READ_FAST_QUAD] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x6B, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, 0x18),
		 [4 * NOR_CMD_LUT_SEQ_IDX_READ_FAST_QUAD + 1] = FLEXSPI_LUT_SEQ(
		 kFLEXSPI_Command_DUMMY_SDR, kFLEXSPI_4PAD, 0x08, kFLEXSPI_Command_READ_SDR, kFLEXSPI_4PAD, 0x04),

		 /* Fast read mode - SDR */
		 [4 * NOR_CMD_LUT_SEQ_IDX_READ_FAST] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x0B, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, 0x18),
		 [4 * NOR_CMD_LUT_SEQ_IDX_READ_FAST + 1] = FLEXSPI_LUT_SEQ(
		 kFLEXSPI_Command_DUMMY_SDR, kFLEXSPI_1PAD, 0x08, kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, 0x04),

		 /* Normal read mode -SDR */
		 [4 * NOR_CMD_LUT_SEQ_IDX_READ_NORMAL] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x03, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, 0x18),
		 [4 * NOR_CMD_LUT_SEQ_IDX_READ_NORMAL + 1] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, 0x04, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

		 /* Read extend parameters */
		 [4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x81, kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, 0x04),

		 /* Write Enable */
		 [4 * NOR_CMD_LUT_SEQ_IDX_WRITEENABLE] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x06, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

		 /* Erase Sector */
		 [4 * NOR_CMD_LUT_SEQ_IDX_ERASESECTOR] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x20, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, 0x18),

		 /* Page Program - single mode */
		 [4 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM_SINGLE] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x02, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, 0x18),
		 [4 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM_SINGLE + 1] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_1PAD, 0x04, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

		 /* Page Program - quad mode */
		 [4 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM_QUAD] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x32, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, 0x18),
		 [4 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM_QUAD + 1] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_4PAD, 0x04, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

		 /* Read ID */
		 [4 * NOR_CMD_LUT_SEQ_IDX_READID] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x9F, kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, 0x04),

		 /* Enable Quad mode */
		 [4 * NOR_CMD_LUT_SEQ_IDX_WRITESTATUSREG] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x01, kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_1PAD, 0x04),

		 /* Enter QPI mode */
		 [4 * NOR_CMD_LUT_SEQ_IDX_ENTERQPI] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x35, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

		 /* Exit QPI mode */
		 [4 * NOR_CMD_LUT_SEQ_IDX_EXITQPI] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_4PAD, 0xF5, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),

		 /* Read status register */
		 [4 * NOR_CMD_LUT_SEQ_IDX_READSTATUSREG] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0x05, kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, 0x04),

		 /* Erase whole chip */
		 [4 * NOR_CMD_LUT_SEQ_IDX_ERASECHIP] =
		 FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, 0xC7, kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0),
};

unsigned long base_addr = 0x70000000;

void SFLASH_init(void)
{
	uint8_t vendorID = 0;

    FLEXSPI_UpdateLUT(BOARD_FLEXSPI, 0, FLEXSPI_customLUT, CUSTOM_LUT_LENGTH);

    FLEXSPI_SoftwareReset(BOARD_FLEXSPI);

    _get_vendor_id(BOARD_FLEXSPI, &vendorID);
    PRINTF("Vendor ID: 0x%x\r\n", vendorID);

    _enable_quad_mode(BOARD_FLEXSPI);
}

int8_t SFLASH_erase_sector(FLEXSPI_Type *base, uint32_t address)
{
    status_t status;
    flexspi_transfer_t flashXfer;
    static uint8_t s_nor_program_buffer[256];
    static uint8_t s_nor_read_buffer[256];
    flexspi_cache_status_t cacheStatus;
    _disable_cache(&cacheStatus);

    // Write enable
    flashXfer.deviceAddress = address;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Command;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_WRITEENABLE;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);

    if (status != kStatus_Success)
    {
        return FLASH_ERROR_OPERATION;
    }

    flashXfer.deviceAddress = address;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Command;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_ERASESECTOR;

    status                  = FLEXSPI_TransferBlocking(base, &flashXfer);

    if (status != kStatus_Success)
    {
        return FLASH_ERROR_OPERATION;
    }
    __disable_irq();
    status = _wait_bus_busy(base);

    // Do software reset.
    FLEXSPI_SoftwareReset(base);

    _enable_cache(cacheStatus);
    __enable_irq();

    memset(s_nor_program_buffer, 0xFFU, sizeof(s_nor_program_buffer));

    DCACHE_InvalidateByRange(EXAMPLE_FLEXSPI_AMBA_BASE + address, FLASH_PAGE_SIZE);

    memcpy(s_nor_read_buffer, (void *)(EXAMPLE_FLEXSPI_AMBA_BASE + address),
           sizeof(s_nor_read_buffer));

    if (memcmp(s_nor_program_buffer, s_nor_read_buffer, sizeof(s_nor_program_buffer)))
    {
        PRINTF("Erase data -  read out data value incorrect !\r\n ");
        return FLASH_ERROR_OPERATION;
    }
    else
    {
        PRINTF("Erase data - successfully. \r\n");
    }
    return FLASH_COMPLETE;
}

int8_t SFLASH_WriteByte(FLEXSPI_Type *base, uint32_t dstAddr, uint8_t Data)
{
    status_t status;
    flexspi_transfer_t flashXfer;
    flexspi_cache_status_t cacheStatus;
    static uint8_t program_buffer[1];
    static uint8_t read_buffer_check[1];

    program_buffer[0] = Data;

    _disable_cache(&cacheStatus);

    // To make sure external flash be in idle status, added wait for busy before program data for
     //   an external flash without RWW(read while write) attribute.
    status = _wait_bus_busy(base);

    if (kStatus_Success != status)
    {
        return FLASH_ERROR_OPERATION;
    }

    // Write enable.
    status = _write_enable(base, dstAddr);

    if (status != kStatus_Success)
    {
        return FLASH_ERROR_OPERATION;
    }

    // Prepare page program command
    flashXfer.deviceAddress = dstAddr;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Write;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM_QUAD;
    flashXfer.data          = (uint32_t *)program_buffer;
    flashXfer.dataSize      = 1;
    status                  = FLEXSPI_TransferBlocking(base, &flashXfer);

    if (status != kStatus_Success)
    {
        return FLASH_ERROR_OPERATION;
    }

    status = _wait_bus_busy(base);

    // Do software reset or clear AHB buffer directly.
    FLEXSPI_SoftwareReset(base);

    _enable_cache(cacheStatus);

    if (status != kStatus_Success)
    {
        PRINTF("Byte program failure !\r\n");
        return FLASH_ERROR_OPERATION;
    }

    DCACHE_InvalidateByRange(EXAMPLE_FLEXSPI_AMBA_BASE + dstAddr, 1);

    memcpy(read_buffer_check, (void *)(EXAMPLE_FLEXSPI_AMBA_BASE + dstAddr),
           sizeof(read_buffer_check));

    if (memcmp(read_buffer_check, program_buffer, sizeof(program_buffer)) != 0)
    {
        PRINTF("Program Byte -  read out data value incorrect !\r\n ");
        return FLASH_ERROR_OPERATION;
    }
    else
    {
        PRINTF("Program Byte - successfully. \r\n");
    }

    return FLASH_COMPLETE;
}

int8_t WriteWord_FLASH (uint32_t Address, uint16_t Data)
{
    int8_t      Status;
    uint8_t*    pData8;
    uint8_t     i;

    Status = FLASH_COMPLETE;

    Address = Address - base_addr;

    pData8 = (uint8_t*) &Data;

    for (i = 0; i < 2; i++) {
        if (SFLASH_WriteByte(BOARD_FLEXSPI, Address + i, pData8[i]) != 0){
            return FLASH_ERROR_OPERATION;
        }
    }
    return (Status);
}

void _enable_cache(flexspi_cache_status_t cacheStatus)
{
    if (cacheStatus.DCacheEnableFlag)
    {
        // Enable D cache.
        SCB_EnableDCache();
    }

    if (cacheStatus.ICacheEnableFlag)
    {
        // Enable I cache.
        SCB_EnableICache();
    }
}
status_t _wait_bus_busy(FLEXSPI_Type *base)
{
    // Wait status ready.
    bool isBusy;
    uint32_t readValue;
    status_t status;
    flexspi_transfer_t flashXfer;

    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Read;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_READSTATUSREG;
    flashXfer.data          = &readValue;
    flashXfer.dataSize      = 1;

    do
    {
        status = FLEXSPI_TransferBlocking(base, &flashXfer);

        if (status != kStatus_Success)
        {
            return status;
        }
        if (FLASH_BUSY_STATUS_POL)
        {
            if (readValue & (1U << FLASH_BUSY_STATUS_OFFSET))
            {
                isBusy = true;
            }
            else
            {
                isBusy = false;
            }
        }
        else
        {
            if (readValue & (1U << FLASH_BUSY_STATUS_OFFSET))
            {
                isBusy = false;
            }
            else
            {
                isBusy = true;
            }
        }

    } while (isBusy);

    return status;
}
status_t _write_enable(FLEXSPI_Type *base, uint32_t baseAddr)
{
    flexspi_transfer_t flashXfer;
    status_t status;

   // Write enable
    flashXfer.deviceAddress = baseAddr;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Command;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_WRITEENABLE;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);

    return status;
}
void _disable_cache(flexspi_cache_status_t *cacheStatus)
{
    // Disable D cache.
    if (SCB_CCR_DC_Msk == (SCB_CCR_DC_Msk & SCB->CCR))
    {
        SCB_DisableDCache();
        cacheStatus->DCacheEnableFlag = true;
    }

    // Disable I cache.
    if (SCB_CCR_IC_Msk == (SCB_CCR_IC_Msk & SCB->CCR))
    {
        SCB_DisableICache();
        cacheStatus->ICacheEnableFlag = true;
    }
}

status_t _get_vendor_id(FLEXSPI_Type *base, uint8_t *vendorId)
{
    uint32_t temp;
    flexspi_transfer_t flashXfer;
    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Read;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_READID;
    flashXfer.data          = &temp;
    flashXfer.dataSize      = 1;

    status_t status = FLEXSPI_TransferBlocking(base, &flashXfer);

    *vendorId = temp;

    // Do software reset or clear AHB buffer directly.

    FLEXSPI_SoftwareReset(base);

    return status;
}

status_t _enable_quad_mode(FLEXSPI_Type *base)
{
    flexspi_transfer_t flashXfer;
    status_t status;
    uint32_t writeValue = FLASH_QUAD_ENABLE;

    flexspi_cache_status_t cacheStatus;
    _disable_cache(&cacheStatus);

    // Write enable
    status = _write_enable(base, 0);

    if (status != kStatus_Success)
    {
        return status;
    }

    // Enable quad mode.
    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Write;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_WRITESTATUSREG;
    flashXfer.data          = &writeValue;
    flashXfer.dataSize      = writeValue <= 0xFFU ? 1 : 2;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = _wait_bus_busy(base);

    // Do software reset.
    FLEXSPI_SoftwareReset(base);

    _enable_cache(cacheStatus);

    return status;
}

int8_t Erase_FLASH (uint32_t Address, uint32_t Size)
{
	int8_t status;
    uint32_t addr;

    status = FLASH_COMPLETE;

    //Address = EXAMPLE_FLEXSPI_AMBA_BASE + Address;

    if (Address >= base_addr && Size == 0x8000) {
    	Address = Address - EXAMPLE_FLEXSPI_AMBA_BASE;
		PRINTF("Erasing Serial NOR over FlexSPI...\r\n");
		for(addr = Address; addr <= (Address+0x7000); addr=addr+0x1000)
		{
			// Erase sector.
			status = SFLASH_erase_sector(BOARD_FLEXSPI, addr);
			if (status != FLASH_COMPLETE)
			{
				PRINTF("Erase sector failure !\r\n");
				status = FLASH_ERROR_OPERATION;
			}
		}
    }else
    {
    	status = FLASH_ERROR_OPERATION;
    }
    return status;
}

int8_t Read_FLASH (uint32_t Address, uint8_t* pData, uint32_t Size)
{
    int8_t             Status;
    uint8_t*            pSrc;
    uint8_t*            pDst;

    Status = FLASH_COMPLETE;
    pSrc = (uint8_t*)Address;
    pDst = pData;

    Address += base_addr;
    while (Size--) {
        *pDst++ = *pSrc++;
    }

    return (Status);
}
