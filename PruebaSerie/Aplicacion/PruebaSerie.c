/*
===============================================================================
 Name        : PruebaSerie.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "LPC845.h"
#include "DR_Init.h"

uint8_t mensaje[] = "HOLA MUNDO";
#define LONGITUD_MSJ	10

void TimerHandler(void);

int main(void) {

	InitHw();
	TimerStart(0,1,TimerHandler,SEG);
	while(1) {

		TimerEvent();
    }
    return 0 ;
}

void TimerHandler(void)
{
	static uint8_t i = 0;
	USART0->TXDAT = mensaje[i];
	i++;
	i%=LONGITUD_MSJ;
	TimerStart(0,1,TimerHandler,SEG);

}
