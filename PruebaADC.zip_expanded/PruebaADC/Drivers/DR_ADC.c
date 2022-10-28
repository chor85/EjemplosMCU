/*
 * DR_ADC.c
 *
 *  Created on: 28 oct. 2021
 *      Author: chor
 */


#include "DR_ADC.h"
#define TAM_BUFFER_ADC	5
uint32_t resultadoADC;
uint32_t buffer_muestras[TAM_BUFFER_ADC];

void InitADC ( void )
{
	//Energizo el ADC
	SYSCON->PDRUNCFG &= ~(1<<4);

	//Habilito el CLK del ADC:
	SYSCON->SYSAHBCLKCTRL0 |= 1<<24;

	//Selecciono el clk del ADC a 30MHz:
	SYSCON->ADCCLKSEL = 0;

	//Sin divisor:
	SYSCON->ADCCLKDIV = 0;

	//Para modificar la matriz de Switch (seleccionar el pin que voy a usar para el ADC)
	//primero habilito el clk:
	SYSCON->SYSAHBCLKCTRL0 |= 1<<7;

	//Habilito la entrada ADC1, que se encuentra como función especial en el pin P0.6:
	PINENABLE0 &= ~(1<<15);

	//Calibración del ADC:
	//Activo el bit de calibracion (bit30) y pongo el divisor a 500kHz (60):
	ADC->CTRL = (60 | (1<<30));
	//Espero a que se termine la calibracion (bloqueante por aprox 290useg):
	while ( ADC->CTRL & (1<<30) );

	//Muestreo a 10kHz: como cada conversion requiere 25 ciclos de clk,
	//necesito que el clk del ADC quede a 250kHz. Como el clk es de 30MHz,
	//el divisor debe ser de 120

	ADC->CTRL = 	119			|	//DIVISOR - 1
					(0 << 8 )	|	//Modo sincrónico
					(0 << 10)	|	//Low power mode deshabilitado
					(0 << 30);		//Modo calibración deshabilitado

	//Deshabilito la secuencia B:
	ADC->SEQB_CTRL = 0;

	//Selecciono VDD por encima de 2,7V (la alimentacion del ADC):
	ADC->TRM &= ~(1<<5);

	//Configuro la secuencia A:
	ADC->SEQA_CTRL = 	(1 << 1)  |		//Selecciono que se utilice el canal 1
						(0 << 19) |		//Conversiones sincrónicas
						(0 << 24) |		//Conversion a la frec_adc
						(1 << 27) |		//BURST mode
						(1 << 31);		//Habilitar seq A

	//Habilito la interrupcion por el fin de la conversion de la secuencia A:
	ADC->INTEN = 1;

	//Habilito la interrupcion en el NVIC:
	ISER0 |= (1 << 16);

}



void ADC_SEQA_IRQHandler ( void )
{

	static uint8_t posicion = 0;
	uint32_t auxiliar = 0, i = 0;

	//Pongo la muestra en un buffer junto con las anteriores para despues promediarlo
	buffer_muestras[posicion] = (( ADC->SEQA_GDAT >> 4 ) & 0x0FFF);
	posicion++;
	posicion %= TAM_BUFFER_ADC;

	//Hago el promedio de las ultimas TAM_BUFFER muestras:
	for ( i = 0 ; i < TAM_BUFFER_ADC ; i++)
		auxiliar+=buffer_muestras[i];

	resultadoADC = 	auxiliar/TAM_BUFFER_ADC;

}
