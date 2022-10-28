#include <DR_GPIO.h>
#include "LPC845.h"

void InitGPIO(void)
{
	SYSCON->SYSAHBCLKCTRL0 |= (1 << SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT);
	SYSCON->SYSAHBCLKCTRL0 |= (1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT);

	/*
	SetDIR(PIN_LEDR, SALIDA);
	SetDIR(PIN_LEDG, SALIDA);
	SetDIR(PIN_LEDB, SALIDA);
	 */

	SetDIR(0,4,ENTRADA);
	SetDIR(segA, SALIDA);
	SetDIR(segB, SALIDA);
	SetDIR(segC, SALIDA);
	SetDIR(segD, SALIDA);

	//SETEAMOS LOS PINS PARA SALIDAS
	SetDIR(COL0,SALIDA);
	SetDIR(COL1,SALIDA);
	SetDIR(COL2,SALIDA);
	SetDIR(COL3,SALIDA);

	SetDIR(FIL0,ENTRADA);
	SetDIR(FIL1,ENTRADA);
	SetDIR(FIL2,ENTRADA);
	SetDIR(FIL3,ENTRADA);

	SetDIR(display0, SALIDA);
	SetDIR(display1, SALIDA);
	SetDIR(display2, SALIDA);
	SetDIR(display3, SALIDA);

/*
	SetPINMODE_OUT(IOCON_INDEX_PIO1_0, 0);
	SetPINMODE_OUT(IOCON_INDEX_PIO1_1, 0);
	SetPINMODE_OUT(IOCON_INDEX_PIO1_2, 0);
	SetPINMODE_OUT(IOCON_INDEX_PIO0_1, 0);
	*/

	//RESISTENCIAS DE PULL UP PARA LAS COLUMNAS

	//RESISTENCIAS DE PULL UP PARA LAS FILAS
	SetPINMODE_IN(IOCON_INDEX_PIO0_10,0x2);
	SetPINMODE_IN(IOCON_INDEX_PIO0_11,0x2);
	SetPINMODE_IN(IOCON_INDEX_PIO0_13,0x2);
	SetPINMODE_IN(IOCON_INDEX_PIO0_14,0x2);


}
void initdisplay(void)
{
	uint8_t aux;
	aux=0x3f;

	SetPIN(segA, (aux &(uint8_t)0x01));
	SetPIN(segB, (aux>>1)&(uint8_t)0x01);
	SetPIN(segC, (aux>>2)&(uint8_t)0x01);
	SetPIN(segD, (aux>>3)&(uint8_t)0x01);
	SetPIN(display0,ON);
	SetPIN(display1,ON);
	SetPIN(display2,ON);
	SetPIN(display3,ON);
}


void SetDIR (uint32_t Puerto, uint32_t Pin, uint32_t Direccion)	//Setea los pines como Entradas o salidas 0=entrada - 1=salida
{
	if(Direccion == 1)
		GPIO->DIR[Puerto] |= (1<<Pin);
	else
		GPIO->DIR[Puerto] &= ~(1<<Pin);
}

void SetPIN (uint32_t Puerto, uint32_t Pin, uint32_t Estado)	//Setea el Estado (0 o 1) indicado en el pin especificado
{
	if(Estado == 1)
		GPIO->PIN[Puerto] |= (0x01<<Pin);	//Set
	else
		GPIO->PIN[Puerto] &= ~(0x01<<Pin);	//Clear
}

uint32_t GetPIN (uint32_t Puerto, uint32_t Pin) //Devuelve el valor del pin especificado
{
	uint32_t ret=0;

	if( ( GPIO->PIN[Puerto] & (0x01<<Pin) ) != 0)
		ret=1;

	return ret;
}


//0x0 Inactive (no pull-down/pull-up resistor enabled).
//0x1 Pull-down resistor enabled.
//0x2 Pull-up resistor enabled.
//0x3 Repeater mode.

void SetPINMODE_IN (uint32_t pin_index, uint32_t Modo)
{
	IOCON->PIO[pin_index]=  ( (IOCON->PIO[pin_index] & (~(IOCON_PIO_MODE_MASK))) | (Modo<< IOCON_PIO_MODE_SHIFT) );
}

//Open-drain mode.
//0 Disable.
//1 Open-drain mode enabled

void SetPINMODE_OUT (uint32_t pin_index, uint32_t Modo)	//Drain Mode
{
	if(Modo == 1)
		IOCON->PIO[pin_index] |= (1<<IOCON_PIO_OD_SHIFT);
	else
		IOCON->PIO[pin_index] &= ~(1<<IOCON_PIO_OD_SHIFT);
}
