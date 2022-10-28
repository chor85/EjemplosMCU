/*
===============================================================================
 Name        : SystickCompleto.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>

#include "DR_Init.h"
#include "PR_Timers.h"
#include "LPC845.h"

#define T0	0
#define T1	1
#define T2	2

#define	TIEMPO_T0	2
#define	TIEMPO_T1	5
#define	TIEMPO_T2	9

void HandlerT0 (void);
void HandlerT1 (void);
void HandlerT2 (void);

uint8_t flag_t0 = 0, flag_t1 = 0, flag_t2 = 0;

int main(void) {

	InitHw();

	LED_OFF(ROJO);
	LED_OFF(VERDE);
	LED_OFF(AZUL);

	TimerStart(0,TIEMPO_T0,HandlerT0,SEG);
	TimerStart(1,TIEMPO_T1,HandlerT1,SEG);
	TimerStart(2,TIEMPO_T2,HandlerT2,SEG);

    while(1) {

    	if (flag_t0)
    	{
    		flag_t0 = 0;
    		ToggleEstadoLed(ROJO);
    		TimerStart(0,TIEMPO_T0,HandlerT0,SEG);

    	}
    	if (flag_t1)
    	{
    		flag_t1 = 0;
    		ToggleEstadoLed(AZUL);
    		TimerStart(1,TIEMPO_T1,HandlerT1,SEG);
    	}
    	if (flag_t2)
    	{
    		flag_t2 = 0;
    		ToggleEstadoLed(VERDE);
    		TimerStart(2,TIEMPO_T2,HandlerT2,SEG);
    	}

    	TimerEvent();

    }
    return 0 ;
}

void HandlerT0 ( void )
{
	flag_t0 = 1;
}

void HandlerT1 ( void )
{
	flag_t1 = 1;
}

void HandlerT2 ( void )
{
	flag_t2 = 1;
}
