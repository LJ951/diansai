#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "Timer.h"
#include "Encoder.h"
#include "PID.h"
#include "Serial.h"


int main(void)
{		
	Timer_Init();
	OLED_Init();
	Serial_Init();
	
	while (1)
	{
		
//		OLED_Printf(0, 0, OLED_6X8, "Kp:%4.2f", Kp);

		
		OLED_Update();
		
//		Serial_Printf("%f,%f,%f\r\n", Target, Actual, Out);
	}
}


void TIM1_UP_IRQHandler(void)
{

	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
