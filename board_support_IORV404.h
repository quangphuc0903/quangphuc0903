#ifndef __BOARD_SUPPORT_IORV404_H
#define __BOARD_SUPPORT_IORV404_H

#include "stm32f10x.h"                  // Device header

#define PinE_In GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15
#define PortE_In GPIOE
#define RCC_PortE RCC_APB2Periph_GPIOE

#define PinD_Out GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15
#define PortD_Out GPIOD
#define RCC_PortD RCC_APB2Periph_GPIOD
void input_init(void);
void output_init(void);
#endif
