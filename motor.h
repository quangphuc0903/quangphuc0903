#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f10x.h"                  // Device header


#define motor_pin 	GPIO_Pin_6|GPIO_Pin_4|GPIO_Pin_3|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_7
#define motor_f1_1	GPIO_Pin_6
#define motor_f1_2	GPIO_Pin_4
#define motor_f1_3	GPIO_Pin_3

#define motor_f2_1	GPIO_Pin_2
#define motor_f2_2	GPIO_Pin_5
#define motor_f2_3	GPIO_Pin_7

#define motor_port GPIOD
#define RCC_motor	RCC_APB2Periph_GPIOD
void motor_init(void);
void Step_Motor_Action(uint16_t Pin_port,FunctionalState NewState);


#endif
