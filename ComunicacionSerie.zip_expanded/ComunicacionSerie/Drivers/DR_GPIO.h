#ifndef DR_GPIO_H_
#define DR_GPIO_H_

#include "LPC845.h"

#define PIN_LEDR	1,2
#define	PIN_LEDG	1,0
#define	PIN_LEDB	1,1

#define PIN_LED0	1,0
#define PIN_LED1	1,1
#define PIN_LED2	1,2
#define PIN_LED3	0,1

#define COL0 0,31
#define COL1 0,30
#define COL2 0,29
#define COL3 0,28

#define FIL0 0,8
#define FIL1 0,9
#define FIL2 0,13
#define FIL3 0,14

#define segA 0,16
#define segB 0,17
#define segC 0,18
#define segD 0,19
#define display0 0,20
#define display1 0,21
#define display2 0,22
#define display3 0,23

#define SALIDA 1
#define ENTRADA 0

void SetDIR (uint32_t Puerto, uint32_t Pin, uint32_t Direccion);	//Setea la dirección del pin especificado
void SetPIN (uint32_t Puerto, uint32_t Pin, uint32_t Estado);	//Setea el Estado (0 o 1) indicado en el pin especificado
uint32_t GetPIN (uint32_t Puerto, uint32_t Pin); //Devuelve el valor del pin especificado
void SetPINMODE_IN (uint32_t Pin_index, uint32_t Modo); 	//Pull-Down o Pull-Up
void SetPINMODE_OUT (uint32_t Pin_index, uint32_t Modo);	//Drain Mode
void initdisplay(void);


#endif /* DR_GPIO_H_ */
