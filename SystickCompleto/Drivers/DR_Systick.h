/*
 * Systick.h
 *
 *  Created on: 9 sep. 2021
 *      Author:
 */

#ifndef DR_SYSTICK_H_
#define DR_SYSTICK_H_

#include "LPC845.h"

#define CANT_TIMERS 16

extern uint8_t flagsT[CANT_TIMERS];
extern uint32_t timers[CANT_TIMERS];

void InitSystick(void);
void AnalizarTimers(void);

#endif /* DR_SYSTICK_H_ */
