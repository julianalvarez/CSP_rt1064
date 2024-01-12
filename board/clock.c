/*
 * clock.c
 *
 *  Created on: 12 ene. 2024
 *      Author: PLANTIUM
 */

#include "clock.h"

void CLOCK_Init (void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);
    BOARD_InitBootClocks();
}
