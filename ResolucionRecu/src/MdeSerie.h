/*
 * MdeSerie.h
 *
 *  Created on: 1 sep. 2022
 *      Author: chor
 */

#ifndef MDESERIE_H_
#define MDESERIE_H_

#include "LPC845.h"

#define 	ESPERA_HEADER	0
#define		ESPERA_CANT		1
#define		ESPERA_TAM		2
#define		ESPERA_FIN		3

void MdeSerie ( uint8_t );
void InitMdeSerie ( void );

//Esta variable se setea en el tiempo de periodicidad de sellado en función del tamaño de la bolsa:
extern uint8_t t_bolsa;
//Esta variable se pone en 1 cuando llega una trama completa:
extern uint8_t pc_ok;
//Variable flag del timer 0:
extern uint8_t flag_t0;

#endif /* MDESERIE_H_ */
