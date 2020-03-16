#ifndef __DATA_H
#define __DATA_H

#include "stm32f10x.h"                  // Device header


#define data_in_1 GPIO_Pin_1
#define data_in_2	GPIO_Pin_4
#define data_in_port GPIOE

#define data_out_1	GPIO_Pin_1
#define data_out_2	GPIO_Pin_1

#define data_outC GPIO_Pin_8|GPIO_Pin_9
#define data_outD GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_14|GPIO_Pin_15	
#define data_out_portC GPIOC
#define data_out_portD GPIOD



void data_init(void);
void send_data(void);
uint8_t receive_data(uint16_t inx);


#endif
