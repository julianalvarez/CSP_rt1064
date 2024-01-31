/*
 * time.c
 *
 *  Created on: 15 nov. 2023
 *      Author: PLANTIUM
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "peripherals.h"

//#define GPT_CLOCK_FREQ (CLOCK_GetFreq(kCLOCK_PeriphClk))

static uint32_t nowTime = 0;

void TIME_Init (uint32_t TickInMicroseconds)
{
	BOARD_InitTIMER();
}

/* PIT_IRQn interrupt handler */
void BOARD_PIT_IRQHANDLER(void) {
	uint32_t status;

	status = PIT_GetStatusFlags(PIT, kPIT_Chnl_0);
	if(status & kPIT_TimerFlag){
		PIT_ClearStatusFlags(BOARD_PIT_PERIPHERAL,BOARD_PIT_CHANNEL_0,kPIT_TimerFlag);
	    nowTime++;
	}
}

uint32_t TIME_Get(void)
{
	return nowTime;
}
