/*
===============================================================================
 Name        : ComunicacionSerie.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "LPC845.h"
#include "Pr_Tecla.h"
#include "Pr_serie.h"
#include "DR_Init.h"



int main(void) {

	InitHw();
	uint8_t letra ="a";
    while(1)
    {
    	if(getKey()!=-1)
    	{
    		Transmitir(letra,1);
    		letra++;
    	}
    }
    return 0 ;
}
