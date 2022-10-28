/*
 * MdeSerie.c
 *
 *  Created on: 1 sep. 2022
 *      Author: chor
 */

#include "MdeSerie.h"

//Esta variable se setea en el tiempo de periodicidad de sellado en función del tamaño de la bolsa:
extern uint8_t t_bolsa;
//Esta variable se setea en la cantidad de bolsas que se sellarán
extern uint8_t cant_bolsas;
//Esta variable se pone en 1 cuando llega una trama completa:
extern uint8_t pc_ok;

static uint8_t estado;

void MdeSerie ( uint8_t dato )
{
	static uint8_t t_auxiliar, cant_auxiliar;

	switch ( estado )
	{
	case ESPERA_HEADER:

		if ( dato == 0xFF)
			estado = ESPERA_CANT;

		break;

	case ESPERA_CANT:

		if ( dato > 0 && dato <= 200 )
		{
			cant_auxiliar = dato;
			estado = ESPERA_TAM;
		}
		else if ( dato != 0xFF )
			estado = ESPERA_HEADER;

		break;

	case ESPERA_TAM:

		if ( dato ==1 )
		{
			t_auxiliar = 5;
			estado = ESPERA_FIN;
		}
		else if ( dato == 2 )
		{
			t_auxiliar = 7;
			estado = ESPERA_FIN;
		}
		else if ( dato ==3 )
		{
			t_auxiliar = 10;
			estado = ESPERA_FIN;
		}

		else if ( dato != 0xFF )
			estado = ESPERA_HEADER;

		else
			estado = ESPERA_CANT;

		break;

	case ESPERA_FIN:

		if ( dato == (t_auxiliar + cant_auxiliar) )
		{
			t_bolsa = t_auxiliar;
			cant_bolsas = cant_auxiliar;
			pc_ok = 1;
		}
		else if ( dato != 0xFF )
			estado = ESPERA_HEADER;
		else
			estado = ESPERA_CANT;

		break;

	default:

		estado = ESPERA_HEADER;
		break;

	}
}

void InitMdeSerie(void)
{
	estado = ESPERA_HEADER;
}
