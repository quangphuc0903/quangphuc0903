#include "pwm.h"


void PWM_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
	
	// Enable GPIO clock and release reset
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_AFIO, ENABLE);


	/* Configure all the GPIOC in Input Floating mode */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);	

	/* Configure all the GPIOC in Input Floating mode */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOD, &GPIO_InitStruct);

	GPIO_PinRemapConfig(GPIO_Remap_TIM4, ENABLE);	
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	// Create 5kHz PWM
	// TIM3 is connected to APB1 bus that have default clock 72MHz
	// So, the frequency of TIM3 is 72MHz
	// We use prescaler 10 here
	// So, the frequency of TIM3 now is 72MHz
	TIM_TimeBaseInitStruct.TIM_Prescaler = 9;	 												// he so chia Prescaler = timer_default_clock/timer_tick_clock -1
	TIM_TimeBaseInitStruct.TIM_Period = 1124; 												// chu ky cua xung pwm = timer_tick_clock/pwm_frequance -1
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1; 					// chia ??? (default = 0)
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; 			// kieu dem(dem tien)
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);									// Khai bao cau hinh timer
	// Start TIM3
	TIM_Cmd(TIM3, ENABLE); 																						// bat dau timer
	
	// Step 2: Initialize PWM
	// Common PWM settings
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1; 										// chon che do timer pwm 1
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;				// Trang thai dau ra
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;						// Muc xung ra (cao / thap)
	
	// Duty cycle calculation equation:
	// TIM_Pulse = (((TIM_Period + 1) * duty_cycle) / 100) - 1
	// Ex. 25% duty cycle:
	// 		TIM_Pulse = (((1439 + 1) * 25) / 100) - 1 = 359
	//		TIM_Pulse = (((1439 + 1) * 75) / 100) - 1 = 1079
	// We initialize PWM value with duty cycle of 0%
	
	TIM_OCInitStruct.TIM_Pulse = 562; //50% //chi dinh gia tri xung
	TIM_OC1Init(TIM3, &TIM_OCInitStruct);															// Cau hinh cai dat cho kenh 1 pwm 
	TIM_OC2Init(TIM3, &TIM_OCInitStruct);															// Cau hinh cai dat cho kenh 2 pwm
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);									// Bat cau hinh cai dat cho kenh 1 pwm
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);									// Bat cau hinh cai dat cho kenh 2 pwm


	/*****************************************************************************************************/
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_TimeBaseInitStruct.TIM_Prescaler = 9;	 												// he so chia Prescaler = timer_default_clock/timer_tick_clock -1
	TIM_TimeBaseInitStruct.TIM_Period = 1124; 												// chu ky cua xung pwm = timer_tick_clock/pwm_frequance -1
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1; 					// chia ??? (default = 0)
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; 			// kieu dem(dem tien)
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStruct);									// Khai bao cau hinh timer
	// Start TIM4
	TIM_Cmd(TIM4, ENABLE); 																						// bat dau timer
	
	// Step 2: Initialize PWM
	// Common PWM settings
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1; 										// chon che do timer pwm 1
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;				// Trang thai dau ra
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;						// Muc xung ra (cao / thap)
	
	// Duty cycle calculation equation:
	// TIM_Pulse = (((TIM_Period + 1) * duty_cycle) / 100) - 1
	// Ex. 25% duty cycle:
	// 		TIM_Pulse = (((1439 + 1) * 25) / 100) - 1 = 359
	//		TIM_Pulse = (((1439 + 1) * 75) / 100) - 1 = 1079
	// We initialize PWM value with duty cycle of 0%
	
	TIM_OCInitStruct.TIM_Pulse = 562; //50% //chi dinh gia tri xung
	TIM_OC1Init(TIM4, &TIM_OCInitStruct);															// Cau hinh cai dat cho kenh 1 pwm 
	TIM_OC2Init(TIM4, &TIM_OCInitStruct);															// Cau hinh cai dat cho kenh 2 pwm
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);									// Bat cau hinh cai dat cho kenh 1 pwm
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);						
}
