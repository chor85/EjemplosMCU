/*
===============================================================================
 Name        : 7Segs.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "DR_Init.h"
#include "PR_7Seg.h"


int main(void) {

	uint8_t presionada = 0;
	uint8_t contador = 0;

	InitHw();

    while(1) {

    	//cuando detecto la tecla presionada
    	if ( GetPIN(0,4) == 0 && presionada == 0)
    	{
    		//para que entre una sola vez (por flanco)
    		presionada = 1;
    		contador++;

    	}
    	else if ( GetPIN(0,4))
    		presionada = 0;

    	Display(0,contador);
    	Display(1,contador);


    }
    return 0 ;
}
