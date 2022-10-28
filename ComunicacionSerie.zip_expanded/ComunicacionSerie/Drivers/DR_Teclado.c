/*
 * DR_Teclado.c
 *
 *  Created on: 15 sep. 2022
 *      Author: alumno
 */
#include "DR_GPIO.h"
#include "DR_Teclado.h"
#include "DR_Init.h"

volatile uint8_t Tecla;

void DriverTecladoSW(void)
{
	static uint8_t contador=0;
	uint8_t aux;
	aux=getTecla();
	if(aux != NO_KEY && contador<N_REBOTES)
	{
		contador++;
		if(contador==N_REBOTES)
		{
			Tecla=aux;
		}
	}
	else if(aux==NO_KEY)
	{
		contador=0;
	}
}

uint8_t getTecla(void)
{
	uint8_t aux = NO_KEY;

	SetPIN(COL0,0);//HABILITO COL0
	SetPIN(COL1,1);
	SetPIN(COL2,1);
	SetPIN(COL3,1);


	if( GetPIN(FIL0) == 0)
	{
		aux=1;
	}
	else if(GetPIN(FIL1)==0)
	{
			aux=4;
	}
	else if(GetPIN(FIL2)==0)
	{
		aux=7;
	}

	SetPIN(COL0,1);
	SetPIN(COL1,0);
	SetPIN(COL2,1);
	SetPIN(COL3,1);


	if(GetPIN(FIL0)==0)
	{
		aux=2;
	}
	else if(GetPIN(FIL1)==0)
	{
		aux=5;
	}
	else if(GetPIN(FIL2)==0)
	{
		aux=8;
	}
	else if(GetPIN(FIL3)==0)
	{
		aux=0;
	}

	SetPIN(COL0,1);
	SetPIN(COL1,1);
	SetPIN(COL2,0);
	SetPIN(COL3,1);

	if(GetPIN(FIL0)==0)
	{
		aux=3;
	}
	else if(GetPIN(FIL1)==0)
	{
		aux=6;
	}
	else if(GetPIN(FIL2)==0)
	{
		aux=9;
	}

	return aux;
}



