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
#include "PR_ADC.h"
#include "PR_7Seg.h"


int main(void) {

	uint32_t cuentas_ADC;

	InitHw();

	while(1) {

		cuentas_ADC = LeerSensor();
		Display( 0 , cuentas_ADC%1000 );
		Display( 1 , cuentas_ADC/1000 );

		TimerEvent();
    }
    return 0 ;
}

