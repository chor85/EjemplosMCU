/*
 * Pr_Tecla.c
 *
 *  Created on: 13 oct. 2022
 *      Author: nicoa
 */

#include "Pr_Tecla.h"
#include "LPC845.h"

#include "PR_7Seg.h"
#include "DR_GPIO.h"
#include "DR_Teclado.h"
#include "DR_Init.h"

uint8_t getKey(void)
{
	volatile uint8_t aux = NO_KEY;
	if( Tecla != NO_KEY )
	{
		aux = Tecla;
		Tecla = NO_KEY;
	}
	return aux;
}
