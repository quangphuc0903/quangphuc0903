#ifndef __SENSOR_H
#define __SENSOR_H

#include "stm32f10x.h"                  // Device header

#define Sensor_F1_In1	GPIO_Pin_12
#define Sensor_F1_In2	GPIO_Pin_10
#define Sensor_F1_OUT	GPIO_Pin_3

#define Sensor_F2_In	GPIO_Pin_0
#define Sensor_F2_OUT	GPIO_Pin_14

#define Sensor_Port	GPIOE
#define Sensor_Pin_F1 Sensor_F1_In1|Sensor_F1_In2|Sensor_F1_OUT
#define Sensor_Pin_F2 Sensor_F2_In|Sensor_F2_OUT

void Sensor_Init(void);
uint8_t read_sensor(uint16_t sensor);


#endif
