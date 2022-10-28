/*
 * DR_7Seg.c
 *
 *  Created on: 27 sep. 2021
 *      Author: chor
 */


#include "DR_7Seg.h"
#define Display0 0
#define Display1 1
#define Display2 2
#define Display3 3
volatile uint8_t Digitos_Display[N_DIGITOS];
void BarridoDisplay(void)
{
	//const uint8_t Tabla_Digitos_BCD_7segmentos[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	uint8_t aux;
	static int indice_display=Display0;
	SetPIN(display0,OFF);
	SetPIN(display1,OFF);
	SetPIN(display2,OFF);
	SetPIN(display3,OFF);
	//aux=Tabla_Digitos_BCD_7segmentos[Digitos_Display[indice_display]];
	aux=Digitos_Display[indice_display];
	SetPIN(segA, (aux>>0)& 0x01);
	SetPIN(segB, (aux>>1)& 0x01);
	SetPIN(segC, (aux>>2)& 0x01);
	SetPIN(segD, (aux>>3)& 0x01);
	switch(indice_display)
	{
		case Display0:
			SetPIN(display0,ON);
			break;
		case Display1:
			SetPIN(display1,ON);
			break;
		case Display2:
			SetPIN(display2,ON);
			break;
		case Display3:
			SetPIN(display3,ON);
			break;

	}
	indice_display++;
	indice_display%=N_DIGITOS;
}
