#ifndef __LAMP_H
#define __LAMP_H

#include "stm32f10x.h"                  // Device header

#define lamp_green GPIO_Pin_11	// port C
#define lamp_red	GPIO_Pin_12 	// port C
#define lamp_orange	GPIO_Pin_14 // port D

void Lamp_Init(void);
void turn_lamp(uint16_t lamp);
void off_lamp(uint16_t lamp);

#endif
