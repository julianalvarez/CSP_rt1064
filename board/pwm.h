/*
 * pwm.h
 *
 *  Created on: 4 ene. 2024
 *      Author: PLANTIUM
 */
#ifndef PWM_H_
#define PWM_H_

/* Include ********************************************************************/
#include <stdint.h>
#include "peripherals.h"
#include "board.h"
#include "pin_mux.h"
#include <pwm.h>

void                    PWM_Init  (uint32_t uPwmId,		/* 0,1,2,3 */
                                   uint32_t uOutput,	/* 0,1,2,3,4,5 */
                                   uint32_t uFreq,      /* 500 - 20000 Hz */
                                   uint32_t uCycle);	/* 0 to 10000 */
void                    PWM_Start (uint32_t uPwmId);
void                    PWM_Stop  (uint32_t uPwmId);
void                    PWM_Set   (uint32_t uPwmId,		/* 0,1,2,3 */
                                   uint32_t uOutput,	/* 0,1,2,3,4,5 */
                                   uint32_t uCycle);	/* 0 to 10000 */
uint32_t                PWM_GetFreq (void);

#endif /* PWM_H_ */
