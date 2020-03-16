#include "motor.h"

void motor_init(void)
{
		GPIO_InitTypeDef	GPIO_InitStruct;
	
		RCC_APB2PeriphClockCmd(RCC_motor, ENABLE);
 
    GPIO_InitStruct.GPIO_Pin = motor_pin;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
	
}

void Step_Motor_Action(uint16_t Pin_port,FunctionalState NewState)
{
	if(NewState == ENABLE)
	{
		GPIO_ResetBits(motor_port,Pin_port);
	}
	else
	{
		GPIO_SetBits(motor_port,Pin_port);
	}
	
}
