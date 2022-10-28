/*
 * DR_UART.h
 *
 *  Created on: 20 oct. 2021
 *      Author: chor
 */

#ifndef DR_UART_H_
#define DR_UART_H_

#include "LPC845.h"

#define FREQ_PRINCIPAL	30000000U
#define BAUDRATE		9600U

void UART0_Init( void );
void UART0_IRQHandler (void);



#endif /* DR_UART_H_ */
