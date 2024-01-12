/*
 * uart.c
 *
 *  Created on: 12 ene. 2024
 *      Author: PLANTIUM
 */

#include <uart.h>

void UART_Init (void)
{
    BOARD_InitPins_UART1();
    BOARD_InitUART();
}
