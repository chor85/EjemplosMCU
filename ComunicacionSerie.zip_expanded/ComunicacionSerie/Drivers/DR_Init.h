#ifndef DR_INIT_H_
#define DR_INIT_H_

//Registros de control del FRO y del CLK

//Direccion de la funcion de ROM para setear la frecuencia del oscilador:
#define FRO_SET_FRECUENCY_FUNC ( 0x0F0026F5U)
#define FREQ_PRINCIPAL 30000000
#define BAUDRATE 312
#include "Systick.h"
#include "DR_GPIO.h"
#include "LPC845.h"

void InitHw(void);
void InitPLL(void);
void UART0_Init(void);


#endif /* DR_INIT_H_ */
