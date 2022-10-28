/*
 * Timer.h
 *
 *  Created on: 9 sep. 2021
 *      Author:
 */

#ifndef PR_TIMERS_H_
#define PR_TIMERS_H_

#include "../Drivers/DR_Systick.h"
#include "LPC845.h"

#define SEG 1000
#define MIN 60000
#define DEC 100
#define MILI 1

//void ( * HandlersTimer [CANT_TIMERS]) (void);

void TimerStart(uint8_t ntimer, uint32_t time, void (*handler)(void), uint32_t base);
void TimerStop(uint8_t ntimer);
void TimerEvent(void);

#endif /* PR_TIMERS_H_ */
