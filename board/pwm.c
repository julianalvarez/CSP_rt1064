/*
 * pwm.c
 *
 *  Created on: 4 ene. 2024
 *      Author: PLANTIUM
 */

#include <pwm.h>
#include "fsl_xbara.h"

void Init_PWM (void)
{ //FLEXPWM1, SUBMOD 0, PWMA, 12kHZ, 50%

	BOARD_InitPins_PWM();

    /* Set the PWM Fault inputs to a low value*/
    XBARA_Init(XBARA1);
    XBARA_SetSignalsConnection(XBARA1, kXBARA1_InputLogicHigh, kXBARA1_OutputFlexpwm1Fault0);
    XBARA_SetSignalsConnection(XBARA1, kXBARA1_InputLogicHigh, kXBARA1_OutputFlexpwm1Fault1);
    XBARA_SetSignalsConnection(XBARA1, kXBARA1_InputLogicHigh, kXBARA1_OutputFlexpwm1234Fault2);
    XBARA_SetSignalsConnection(XBARA1, kXBARA1_InputLogicHigh, kXBARA1_OutputFlexpwm1234Fault3);

    BOARD_InitPWM();
}

void PWM_Start (uint32_t uPwmId)
{
	PWM_StartTimer(BOARD_PWM1_PERIPHERAL, (uPwmId));
}

void PWM_Set (uint32_t uPwmId,
              uint32_t uOutput,
              uint32_t uCycle)
{
    PWM_UpdatePwmDutycycle(BOARD_PWM1_PERIPHERAL, uPwmId, uOutput, kPWM_SignedCenterAligned, uCycle);
    PWM_SetPwmLdok(BOARD_PWM1_PERIPHERAL, kPWM_Control_Module_0 , true);
}
