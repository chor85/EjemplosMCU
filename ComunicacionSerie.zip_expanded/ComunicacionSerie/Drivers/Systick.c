#include "Systick.h"

void SysTick_Handler(void)
{
	static uint8_t cont=0;
	//Leo el registro de estado para limpiar el flag de interrupciones
	uint8_t aux = SYSTICK->CSR;
	DriverTecladoSW();
	if(cont==TIME_DISPLAY)
	{
		BarridoDisplay();
		cont=0;
	}
	cont++;



}


void InitSystick(void)
{
	SYSTICK->CSR=7;			//Pongo en 1 los ultimos 3 bits del registro
	SYSTICK->RVR=30000-1;	//Configuro el systick cada 1ms, le pongo -1 porque el micro tarda un tick mas en hacer el reload
	SYSTICK->CVR=SYSTICK->RVR;	//La primer recarga la tiene que hacer el usuario
}
