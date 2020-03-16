#include "lamp.h"

void Lamp_Init(void)
{
		GPIO_InitTypeDef	GPIO_InitStruct;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
 
    GPIO_InitStruct.GPIO_Pin =	lamp_green|lamp_red;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
 
    GPIO_InitStruct.GPIO_Pin =	lamp_orange;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void off_lamp(uint16_t lamp)
{
	if(lamp==lamp_orange)
	{
		GPIO_ResetBits(GPIOD,lamp);
	}
	else
	{
		GPIO_ResetBits(GPIOC,lamp);

	}
}

void turn_lamp(uint16_t lamp)
{
	if(lamp==lamp_orange)
	{
		GPIO_SetBits(GPIOD,lamp);
	}
	else
	{
		GPIO_SetBits(GPIOC,lamp);

	}
}
