/*
 * Pr_serie.h
 *
 *  Created on: 13 oct. 2022
 *      Author: nicoa
 */

#ifndef PR_SERIE_H_
#define PR_SERIE_H_
#include "LPC845.h"
uint16_t RecibirSerie(void);
void Transmitir(char * , uint8_t );
void Push_Tx(uint8_t );
int16_t PopTx(void);
int16_t PopRx(void);
void Push_Rx(uint8_t );

#define TAM 20

#endif /* PR_SERIE_H_ */
