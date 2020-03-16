#include "pittong.h"

void pittong_init(void)
{
		GPIO_InitTypeDef	GPIO_InitStruct;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOD, ENABLE);
 
    GPIO_InitStruct.GPIO_Pin = block_Pittong|F1_Pittong;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(Pittong_Port, &GPIO_InitStruct);
		
		GPIO_InitStruct.GPIO_Pin = F2_Pittong;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
	
}

void pittong_action(uint16_t Pin_port,FunctionalState NewState)
{

	if(NewState == ENABLE)
	{
			if(Pin_port==F2_Pittong)
		{
			GPIO_ResetBits(GPIOC,Pin_port);
		}
		GPIO_ResetBits(Pittong_Port,Pin_port);
	}
	else
	{
		if(Pin_port==F2_Pittong)
		{
			GPIO_SetBits(GPIOC,Pin_port);
		}
		GPIO_SetBits(Pittong_Port,Pin_port);
	}
	
}
