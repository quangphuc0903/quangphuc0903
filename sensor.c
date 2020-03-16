#include "sensor.h"

void Sensor_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = Sensor_Pin_F1|Sensor_Pin_F2;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Sensor_Port, &GPIO_InitStruct);	
}

uint8_t read_sensor(uint16_t sensor)
{
	return GPIO_ReadInputDataBit(Sensor_Port,sensor);
}
