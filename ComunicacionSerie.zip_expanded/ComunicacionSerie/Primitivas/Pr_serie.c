/*
 * Pr_serie.c
 *
 *  Created on: 13 oct. 2022
 *      Author: nicoa
 */
#include "Pr_serie.h"

uint8_t Buffer_Tx[TAM];
uint8_t Buffer_Rx[TAM];
uint8_t in_rx;
uint8_t in_tx;
uint8_t out_rx;
uint8_t out_tx;

void Transmitir(char * vec, uint8_t cant)
{
	int16_t i=0;

	for(i=0;i<cant;i++)
	{
		Push_Tx(vec[i]);
	}
}

uint16_t RecibirSerie(void)
{
	int16_t aux=-1;
	if(in_rx!=out_rx)
	{
		aux=Buffer_Rx[out_rx];
		out_rx++;
		if(out_rx==TAM)
		{
			out_rx=0;
		}
	}
	return aux;
}


void Push_Tx(uint8_t dato)
{
	static uint8_t in_tx = 0;
	Buffer_Tx[in_tx] = dato;
	in_tx ++;
	if ( in_tx == TAM ){
		in_tx = 0;
	}

	USART0->INTENSET |=1<<2;
}

int16_t PopTx(void )
{
	int16_t retorno = -1;
	if ( out_tx != in_tx )
	{
		retorno = Buffer_Tx[out_tx];
		out_tx++;
		out_tx %= TAM;
	}

	return retorno;

}

int16_t PopRx ( void )
{
	int16_t retorno = -1;
	if ( out_rx != in_rx )
	{
		retorno = Buffer_Rx[out_rx];
		out_rx++;
		out_rx %= TAM;
	}
	return retorno;
}
void Push_Rx ( uint8_t dato )
{
	Buffer_Rx[in_rx] = dato;
	in_rx++;
	in_rx %= TAM;
}
