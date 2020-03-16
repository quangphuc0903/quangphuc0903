#ifndef __BUTTON_H
#define __BUTTON_H

#include "stm32f10x.h"                  // Device header

#define button_start	GPIO_Pin_2
#define button_stop	GPIO_Pin_6
#define button_kc	GPIO_Pin_3


#define button_Port	GPIOE

void button_init(void);


#endif
