/*
 * DR_Teclado.h
 *
 *  Created on: 15 sep. 2022
 *      Author: alumno
 */

#ifndef DR_TECLADO_H_
#define DR_TECLADO_H_

#define NO_KEY 255
#define KEY 0
#define N_REBOTES 10
#define PULSADOR 0,4

void DriverTecladoSW(void);
uint8_t getTecla(void);
volatile extern uint8_t Tecla;


#endif /* DR_TECLADO_H_ */
