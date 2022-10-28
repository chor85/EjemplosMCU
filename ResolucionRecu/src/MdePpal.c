/*
 * MdePpal.c
 *
 *  Created on: 1 sep. 2022
 *      Author: chor
 */

#include "MdePpal.h"
#include "MdeSerie.h"

//Esta variable se setea en el tiempo de periodicidad de sellado en función del tamaño de la bolsa:
uint8_t t_bolsa = 0;
//Esta variable se pone en 1 cuando llega una trama completa:
uint8_t pc_ok = 0;
//Variable flag del timer 0:
uint8_t flag_t0 = 0;
//Esta variable se setea en la cantidad de bolsas que se sellarán
uint8_t cant_bolsas = 0;

uint8_t bolsas_selladas = 0;

void MdePpal ( void )
{
	static uint8_t estado = APAGADA;
	int16_t auxiliar;
	uint8_t boton = GetBoton();

	switch ( estado )
	{
		case APAGADA:
			if ( boton )
			{
				InitMdeSerie();
				bolsas_selladas = 0;
				R_Sellado(1);
				estado = ESPERA_PC;
			}
			break;

		case ESPERA_PC:

			if ( boton )
			{
				R_Sellado(0);
				estado = APAGADA;
			}
			else if ( TempOK() && pc_ok )
			{
				pc_ok = 0;
				MotorCinta(1);
				TimerStart(0 , t_bolsa , HandlerT0 , SEG );
				estado = ENROLLANDO;
			}

			auxiliar = LeerByte();

			if ( auxiliar != -1 )
				MdeSerie(auxiliar);

			break;

		case ENROLLANDO:

			if ( boton )
			{
				R_Sellado(0);
				MotorCinta(0);
				TimerStop(0);
				estado = APAGADA;
			}
			else if ( flag_t0 )
			{
				flag_t0 = 0;
				MotorCinta(0);
				PistonSellado(1);
				TimerStart(0 , 2 , HandlerT0 , SEG );
				estado = SELLANDO;
			}
			else if ( cant_bolsas == bolsas_selladas )
			{
				MotorCinta(0);
				TimerStop(0);
				InitMdeSerie();
				bolsas_selladas = 0;
				estado = ESPERA_PC;
			}
			break;

		case SELLANDO:

			if ( boton )
			{
				R_Sellado(0);
				PistonSellado(0);
				TimerStop(0);
				estado = APAGADA;
			}
			else if ( flag_t0 )
			{
				flag_t0 = 0;
				MotorCinta(1);
				PistonSellado(0);
				TimerStart(0 , t_bolsa , HandlerT0 , SEG );
				bolsas_selladas++;
				estado = ENROLLANDO;
			}
			break;

		default:
			PistonSellado(0);
			MotorCinta(0);
			R_Sellado(0);
			estado = APAGADA;
			TimerStop(0);
			break;
	}

}

void InitMdePpal (void)
{
	PistonSellado(0);
	MotorCinta(0);
	R_Sellado(0);
}

void HandlerT0 ( void )
{
	flag_t0 = 1;
}
