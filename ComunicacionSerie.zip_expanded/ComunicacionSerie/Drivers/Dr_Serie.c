/*
 * Dr_Serie.c
 *
 *  Created on: 13 oct. 2022
 *      Author: nicoa
 */


//Drivers
#include "Dr_Serie.h"
extern uint8_t Buffer_Tx[TAM];
extern uint8_t Buffer_Rx[TAM];
extern uint8_t in_rx;
extern uint8_t in_tx;
extern uint8_t out_rx;
extern uint8_t out_tx;

void USART0_IRQHandler(void)
{
	uint8_t stat=USART0->STAT;
	int16_t dato;

	if(stat & 1)//Se recibio un dato
	{
		dato= PopTx();
		if(dato!=-1)
		{
			USART0->TXDAT=dato;
		}
		else
		{
			USART0->INTENCLR = 1<<2;
		}
	}

	if(stat & (1<<2))//Enviar dato
	{
		//envio dato
		Push_Rx(USART0->RXDAT);
	}
}
