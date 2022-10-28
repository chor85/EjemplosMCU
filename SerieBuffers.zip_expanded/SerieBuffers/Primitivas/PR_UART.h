/*
 * PR_UART.h
 *
 *  Created on: 25 oct. 2021
 *      Author: chor
 */

#ifndef PR_UART_H_
#define PR_UART_H_

#include "LPC845.h"
#include "DR_UART.h"

int16_t RecibirSerie ( void );
void TransmitirMsg ( uint8_t * , uint32_t );
void TransmitirByte ( uint8_t );

#endif /* PR_UART_H_ */
