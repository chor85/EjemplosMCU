/*
 * Primitivas.h
 *
 *  Created on: 1 sep. 2022
 *      Author: chor
 */

#ifndef PRIMITIVAS_H_
#define PRIMITIVAS_H_

#include "LPC845.h"

#define SEG 0

//Inicializa los periféricos del microcontrolador
void InitHw( void );

//Dispara el timer N con el tiempo T, en la base de tiempos BASE. Al finalizar, invoca a la función Handler:
void TimerStart ( uint8_t N , uint32_t T, void (*Handler) ( void ) , uint8_t BASE);

//Detiene el timer N
void TimerStop (uint8_t N);

//Realiza el manejo de las temporizaciones
void TimerEvent (void);

//Botón de Arranque/Parada. Devuelve un 1 si el botón se presiona, o un 0 en caso contrario.
uint8_t GetBoton ( void );

//Motor de la bobina, encendido de la resistencia de sellado y activación del pistón para descender el sellado: Con 1 se activan las actuaciones  y con 0 se desactivan:
void MotorCinta ( uint8_t );
void PistonSellado ( uint8_t );
void R_Sellado ( uint8_t);

//Sensor de temperatura: Envía un 1 cuando la resistencia alcanza la temperatura para sellar las bolsas:
uint8_t TempOK (void);

//Lectura del puerto serie: Devuelve -1 si no hay un dato nuevo en el puerto, o el byte recibido en cuanto llegue un dato nuevo:
int16_t LeerByte ( void );


#endif /* PRIMITIVAS_H_ */
