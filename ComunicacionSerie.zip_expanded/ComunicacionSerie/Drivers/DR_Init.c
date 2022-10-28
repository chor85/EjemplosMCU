#include "DR_Init.h"
#include "LPC845.h"

//Genero una funcion a partir de un puntero a función que llame a esa posición de memoria:
void (*fro_set_frec) (int ) = FRO_SET_FRECUENCY_FUNC;


void InitHw(void)
{
	InitPLL();
	InitGPIO();
	InitSystick();
	initdisplay();
	UART0_Init();
}

void InitPLL(void)
{
	//Seteo la frecuencia del fro a 30MHz, llamando a la funcion de ROM:
	fro_set_frec(30000);

	//Selecciono la salida del FRO como el clk principal del sistema:

	SYSCON->FROOSCCTRL |= 1<<17;

	//Refresco el registro para habilitar el clk de 30MHz:
	SYSCON->FRODIRECTCLKUEN &= ~1;
	SYSCON->FRODIRECTCLKUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->MAINCLKPLLSEL = 0;

	SYSCON->MAINCLKPLLUEN &= ~1;
	SYSCON->MAINCLKPLLUEN |= 1;

	//Seteo FRO como el clkSrc del PLL:
	SYSCON->SYSPLLCLKSEL = 0;

	SYSCON->SYSPLLCLKUEN &= ~1;
	SYSCON->SYSPLLCLKUEN |= 1;

	SYSCON->SYSAHBCLKDIV = 1;
}

void UART0_Init(void)
{
	//HAB UART0
	SYSCON->SYSAHBCLKCTRL0 |=(1<<14);
	//RESET UART0
	SYSCON->PRESETCTRL0 &= ~(1<<14);
	SYSCON->PRESETCTRL0 |=(1<<14);
	//HAB CLK A LA SWM
	SYSCON->SYSAHBCLKCTRL0 |=(1<<7);

	PINASSIGN0 &= ~(0x0000FFFF);
	PINASSIGN0= (25<<0)|(24<<8);

	//CFG GRAL
	USART0->CFG= (0<<0)|(1<<2)|(0<<4)|(0<<6)|(0<<9)|(0<<11);
	//CFG INTR
	USART0->INTENSET=(1<<0);
	//CONF DEL BAUDRATE
	UART0CLKSEL=0;
	USART0->BRG=(FREQ_PRINCIPAL/(BAUDRATE*16));
	ISER0|=(1<<3);
	USART0->CFG|=1;

	return;

}
