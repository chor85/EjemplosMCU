/*
 * PR_UART.c
 *
 *  Created on: 25 oct. 2021
 *      Author: chor
 */

#include "PR_UART.h"

void TransmitirMsg ( uint8_t * buffer , uint32_t size )
{
	int i;
	for ( i = 0 ; i < size ; i++ )
		PushTx(buffer[i]);
}

void TransmitirByte ( uint8_t dato )
{
	PushTx(dato);
}


int16_t RecibirSerie ( void )
{
	return PopRx();
}

