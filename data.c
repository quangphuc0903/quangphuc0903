#include "data.h"

void data_init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitStruct.GPIO_Pin =	data_in_1|data_in_2;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Init(data_in_port, &GPIO_InitStruct);

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

//	GPIO_InitStruct.GPIO_Pin =	data_outD;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
//	GPIO_Init(GPIOD, &GPIO_InitStruct);
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

//	GPIO_InitStruct.GPIO_Pin =	data_outC;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
//	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
}
//void send_data(void)
//{
//	
//}
uint8_t receive_data(uint16_t inx)
{
	return GPIO_ReadInputDataBit(data_in_port,inx);
}
