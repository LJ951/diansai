#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "Timer.h"
#include "Encoder.h"

int32_t Speed;
int32_t Location;

int main(void)
{		
	Timer_Init();
	OLED_Init();
	PWM_Init();
	Encoder_Init();
	
	while (1)
	{
		PWM_SetCompare1(50);
		OLED_Printf(0, 0, OLED_8X16, "Speed:%+05d", Speed);
		OLED_Printf(0, 16, OLED_8X16, "Location:%+05d", Location);
		OLED_Update();
		
	}
}


void TIM1_UP_IRQHandler(void)
{
	static uint16_t Count;
	
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Count ++;
		if (Count >= 50)
		{
			Count = 0;
			
			Speed = Encoder_Get();
			Location += Speed;
		}
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
