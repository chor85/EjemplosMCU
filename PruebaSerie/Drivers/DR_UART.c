/*
 * DR_UART.c
 *
 *  Created on: 20 oct. 2021
 *      Author: chor
 */
#include "DR_UART.h"

void UART0_Init(void)
{
	// HABILITO LA UART0
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 14);

	//Reseteo la UART0:
	SYSCON->PRESETCTRL0 &= ~(1<<14);
	SYSCON->PRESETCTRL0 |= (1<<14);

	//Habilito el CLK a la SWM:
	SYSCON->SYSAHBCLKCTRL0 |= (1<<7);

	// CONFIGURO LA MATRIX TX0 en P0.25	y RX0 en P0.24
	PINASSIGN0 &= ~(0x0000FFFFF);
	PINASSIGN0 = (25 << 0) | (24 << 8);

	// CONFIGURACION GENERAL
	USART0->CFG = 	(0 << 0)		// 0=DISABLE 1=ENABLE
				| (1 << 2)		// 0=7BITS 1=8BITS 2=9BITS
				| (0 << 4)		// 0=NOPARITY 2=PAR 3=IMPAR
				| (0 << 6)		// 0=1BITSTOP 1=2BITSTOP
				| (0 << 9)		// 0=NOFLOWCONTROL 1=FLOWCONTROL
				| (0 << 11);	// 0=ASINCRONICA 1=SINCRONICA

	// CONFIGURACION INTERRUPCIONES
	USART0->INTENSET = (1 << 0);	//RX

	// CONFIGURACION DEL BAUDRATE
	UART0CLKSEL = 0; //CLK = FRO = 30MHz
	USART0->BRG = (FREQ_PRINCIPAL / (BAUDRATE* 16));

	//Habilito interrupcion USART0 en el NVIC
	ISER0 |= (1 << 3);

	// ENABLE LA UART
	USART0->CFG |= 1;

	return;
}


void UART0_IRQHandler (void)
{
	uint32_t stat = USART0->STAT;

    // CASO RECEPCION
	if(stat & (1 << 0))
	{
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))
	{
	}

	//CASO ERRORES
	else
	{

	}

}



