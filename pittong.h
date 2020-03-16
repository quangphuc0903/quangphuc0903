#ifndef __PITTONG_H
#define __PITTONG_H

#include "stm32f10x.h"                  // Device header

#define F1_Pittong GPIO_Pin_9
#define F2_Pittong GPIO_Pin_10 //portC
#define block_Pittong GPIO_Pin_8
#define Pittong_Port	GPIOD

void pittong_init(void);
void pittong_action(uint16_t Pin_port,FunctionalState NewState);


#endif
