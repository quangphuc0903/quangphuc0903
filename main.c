#include "main.h"
void f1(void);
void f2(void);

int flag_start_f1=1;
int flag_end_f1 = 0;

int flag_start_f2	=	0;
int flag_end_f2		= 0;


int check_button = 0;



int main()
{
	
	//stop GPIO6 porte
	//start khan cap GPIO2&3 portC
	PWM_Init();
	USART_Config(USART1,9600);
	motor_init();
	Lamp_Init();
	Sensor_Init();
	pittong_init();
	//SysTick_Init();
	data_init();
	button_init();
	
	Step_Motor_Action(motor_f1_1,DISABLE);
	Step_Motor_Action(motor_f1_2,DISABLE);
	Step_Motor_Action(motor_f1_3,DISABLE);
	Step_Motor_Action(motor_f2_1,DISABLE);
	Step_Motor_Action(motor_f2_2,DISABLE);
	Step_Motor_Action(motor_f2_3,DISABLE);

	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOC,button_kc)==1)
		{
			flag_start_f1=1;
			flag_end_f1 = 0;
		
			flag_start_f2	=	0;
			flag_end_f2		= 0;
			
			turn_lamp(lamp_red);
			off_lamp(lamp_green);
			off_lamp(lamp_orange);
			Step_Motor_Action(motor_f1_1,DISABLE);
			Step_Motor_Action(motor_f1_2,DISABLE);
			Step_Motor_Action(motor_f1_3,DISABLE);
			Step_Motor_Action(motor_f2_1,DISABLE);
			Step_Motor_Action(motor_f2_2,DISABLE);
			Step_Motor_Action(motor_f2_3,DISABLE);
		}
		while(GPIO_ReadInputDataBit(GPIOC,button_kc)==0)
		{
			
				off_lamp(lamp_red);
				if(GPIO_ReadInputDataBit(button_Port,button_stop)==0)
				{
					check_button=1;
					//delay_ms(10);
					turn_lamp(lamp_orange);
					off_lamp(lamp_green);
					Step_Motor_Action(motor_f1_1,DISABLE);
					Step_Motor_Action(motor_f1_2,DISABLE);
					Step_Motor_Action(motor_f1_3,DISABLE);
					Step_Motor_Action(motor_f2_1,DISABLE);
					Step_Motor_Action(motor_f2_2,DISABLE);
					Step_Motor_Action(motor_f2_3,DISABLE);
				}
				while(check_button)
				{
					if(GPIO_ReadInputDataBit(GPIOC,button_start)==0)
					{
						off_lamp(lamp_orange);
						check_button=0;
						
					//	delay_ms(10);
					}
					if(GPIO_ReadInputDataBit(GPIOC,button_kc)==1)
					{
						off_lamp(lamp_orange);
						check_button=0;
					//	delay_ms(10);
					}
				}
			turn_lamp(lamp_green);
			f1();
			f2();
		}
	}
}


void f1(void)
{
	if(flag_start_f1 ==1)
	{	
			if(read_sensor(Sensor_F1_In1)==0)
			{
			Step_Motor_Action(motor_f1_1,ENABLE);
			Step_Motor_Action(motor_f1_2,DISABLE);
			}
		if(read_sensor(Sensor_F1_In2)==0)
		{
			Step_Motor_Action(motor_f1_1,DISABLE);
			flag_start_f1=2;
		}
	}
	
	else if(flag_start_f1 ==2)
	{
		if(read_sensor(Sensor_F1_OUT)==1)
		{
			Step_Motor_Action(motor_f1_1,ENABLE);
			Step_Motor_Action(motor_f1_2,DISABLE);
			Step_Motor_Action(motor_f1_3,ENABLE);
			pittong_action(F1_Pittong,DISABLE);
		}
		else
		{
			pittong_action(F1_Pittong,ENABLE);
			Step_Motor_Action(motor_f1_1,DISABLE);
			Step_Motor_Action(motor_f1_3,DISABLE);
			Step_Motor_Action(motor_f1_2,DISABLE);	
			flag_start_f1=3;
		}
	}
	
	else if(flag_start_f1==3)
	{
		if(receive_data(data_in_1)==0)
		{
			Step_Motor_Action(motor_f1_1,DISABLE);
			Step_Motor_Action(motor_f1_3,DISABLE);
			Step_Motor_Action(motor_f1_2,ENABLE);	
		//	delay_ms(5000);
			//Step_Motor_Action(motor_f1_2,DISABLE);	

			flag_start_f1=4;
			flag_end_f1=1;
		}
		
	}

	if(flag_end_f1==1)
	{
			flag_start_f1=1;
			flag_end_f1=0;
	}
}


void f2(void)
{
	if(receive_data(data_in_2)==0)
	{flag_start_f2=1;}
	
	if(flag_start_f2==1)
	{
		Step_Motor_Action(motor_f2_2,ENABLE);
		pittong_action(F2_Pittong,ENABLE);
		if(read_sensor(Sensor_F2_In)==0)
		{
			Step_Motor_Action(motor_f2_2,DISABLE);
			flag_start_f2=2;
		}
		else
		{
			Step_Motor_Action(motor_f2_2,ENABLE);
		}
	}
	
	if(flag_start_f2==2)
	{
		if(read_sensor(Sensor_F2_OUT)==1)
		{

			pittong_action(F2_Pittong,DISABLE);
			Step_Motor_Action(motor_f2_3,ENABLE);
			Step_Motor_Action(motor_f2_1,ENABLE);
			pittong_action(block_Pittong,ENABLE);
		}
		else
		{
			
			pittong_action(F2_Pittong,ENABLE);
			Step_Motor_Action(motor_f2_3,DISABLE);
			Step_Motor_Action(motor_f2_1,DISABLE);
			pittong_action(block_Pittong,DISABLE);
			flag_start_f2 = 3;
			flag_end_f2=1;
		}
	}
	
	if(flag_end_f2==1)
	{
			flag_start_f2=0;
			flag_end_f2=0;
	}
}
