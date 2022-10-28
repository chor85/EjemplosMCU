/*
 * MdePpal.h
 *
 *  Created on: 1 sep. 2022
 *      Author: chor
 */

#ifndef MDEPPAL_H_
#define MDEPPAL_H_

#include "LPC845.h"
#include "Primitivas.h"

#define		APAGADA			0
#define		ESPERA_PC		1
#define		ENROLLANDO		2
#define		SELLANDO		3

void MdePpal ( void );
void InitMdePpal ( void );
void HandlerT0 ( void );


#endif /* MDEPPAL_H_ */
