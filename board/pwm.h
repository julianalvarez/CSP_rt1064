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

void                    Init_PWM  (void); //FLEXPWM1, SUBMOD 0, PWMA, 12kHZ, 50%
void                    PWM_Start (uint32_t uPwmId);
void                    PWM_Stop  (uint32_t uPwmId);
void                    PWM_Set   (uint32_t uPwmId,
                                   uint32_t uOutput,
                                   uint32_t uCycle);
uint32_t                PWM_GetFreq (void);

#endif /* PWM_H_ */
