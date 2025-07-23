#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "Timer.h"
#include "Encoder.h"
#include "PID.h"
#include "Serial.h"

int16_t Speed, Location;
uint8_t KeyNum;

float Target, Actual, Out;
float Kp, Ki = 0.1, Kd;
float Error0, Error1, ErrorInt;

int main(void)
{		
	Timer_Init();
	OLED_Init();
	PWM_Init();
	Encoder_Init();
	Key_Init();
	Serial_Init();
	
	while (1)
	{
		KeyNum = Key_GetNum();
		if (KeyNum == 1)
		{
			Kp += 0.01;
		}
		if (KeyNum == 2)
		{
			Kp -= 0.01;
		}
		if (KeyNum == 3)
		{
			Target += 20;
		}
		if (KeyNum == 4)
		{
			Kd += 0.01;
		}
		if (KeyNum == 5)
		{
			Kd -= 0.01;
		}
		
		if(Target >= 150)
		{
			Target = 0;
		}

		
		OLED_Printf(0, 0, OLED_6X8, "Kp:%4.2f", Kp);
		OLED_Printf(0, 8, OLED_6X8, "Ki:%4.2f", Ki);
		OLED_Printf(0, 16, OLED_6X8, "Kd:%4.2f", Kd);
		
		OLED_Printf(0, 24, OLED_6X8, "Tar:%+04.0f", Target);
		OLED_Printf(0, 32, OLED_6X8, "Act:%+04.0f", Actual);
		OLED_Printf(0, 40, OLED_6X8, "Out:%+04.0f", Out);
		
		OLED_Update();
		
		Serial_Printf("%f,%f,%f\r\n", Target, Actual, Out);
	}
}


void TIM1_UP_IRQHandler(void)
{
	static uint16_t Count;
	
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Key_Tick();
		
		Count ++;
		if (Count >= 40)
		{
			Count = 0;
			
			Actual = Encoder_Get();
			
			Error1 = Error0;
			Error0 = Target - Actual;
			
			if (Ki != 0)
			{
				ErrorInt += Error0;
			}
			else
			{
				ErrorInt = 0;
			}
			
			Out = Kp * Error0 + Ki * ErrorInt + Kd * (Error0 - Error1);
			
			if (Out > 80) {Out = 80;}
			if (Out < 0) {Out = 0;}
			
			PWM_SetCompare1(Out);
		}
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
