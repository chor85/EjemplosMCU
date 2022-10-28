/*
===============================================================================
 Name        : ResolucionRecu.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "LPC845.h"
#include "Primitivas.h"
#include "MdePpal.h"


int main(void) {

	InitHw();
	InitMdePpal ();

    while(1) {

    	MdePpal();
    	TimerEvent();
    }
    return 0 ;
}
