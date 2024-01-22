/*
 * spi_flash.c
 *
 *  Created on: 22 ene. 2024
 *      Author: PLANTIUM
 */


#include "spi_flash.h"

void    SPIFLASH_init(void)
{
	BOARAD_InitSPI2();
}
