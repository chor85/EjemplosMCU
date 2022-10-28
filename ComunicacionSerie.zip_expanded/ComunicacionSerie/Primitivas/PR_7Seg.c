/*
 * PR_7Seg.c
 *
 *  Created on: 27 sep. 2021
 *      Author: chor
 */

#include "PR_7Seg.h"
#include "DR_GPIO.h"
#include "DR_Teclado.h"
#include "DR_Init.h"
extern volatile uint8_t Digitos_Display[N_DIGITOS];

void display(unsigned int val)
{
	int i=0;
	for(i=0;i<N_DIGITOS;i++)
	{

		Digitos_Display[i]=val%10;
		val/=10;
	}

}

