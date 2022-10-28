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
#include "PR_UART.h"

uint8_t letra = 'a';
void Handler (void);

int main(void) {


	InitHw();

	TimerStart(0,1,Handler,SEG);

	while(1) {

		TimerEvent();
    }
    return 0 ;
}

void Handler (void)
{
	TransmitirByte(letra);
	letra++;
	TimerStart(0,1,Handler,SEG);
}
