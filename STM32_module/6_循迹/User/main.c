#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "Timer.h"
#include "Encoder.h"
#include "PID.h"
#include "Serial.h"
#include "sensor.h"
#include "Buzz_LED.h"

uint8_t KeyNum;
uint8_t get;

PID_1 PID1 = {
	.Kp = 0.41,
	.Ki = 0.26,
	.Kd = 0.08,
	.OutMax = 80,
	.OutMin = 0,
};

PID_2 PID2 = {
	.Kp = 0.41,
	.Ki = 0.26,
	.Kd = 0.08,
	.OutMax = 80,
	.OutMin = 0,
};

int main(void)
{		
	LED_Init();
	Buzzer_Init();
	sensor_init();
	Timer_Init();
	OLED_Init();
	PWM_Init();
	Encoder_Init1();
	Encoder_Init2();
	Key_Init();
	Serial_Init();
	
	while (1)
	{
		KeyNum = Key_GetNum();
		
		if(KeyNum == 4)
		{
			PID1.Target += 20;
			PID2.Target += 20;
		}
		if(PID1.Target >= 100)
		{
			PID1.Target = 0;
		}
		if(PID2.Target >= 100)
		{
			PID2.Target = 0;
		}
		
		OLED_Printf(0, 0, OLED_6X8, "Tar1:%+04.0f  ", PID1.Target);
		OLED_Printf(0, 8, OLED_6X8, "Act1:%+04.0f  ", PID1.Actual);
		OLED_Printf(0, 16, OLED_6X8, "Out1:%+04.0f  ", PID1.Out);
		
		OLED_Printf(0, 24, OLED_6X8, "Tar2:%+04.0f  ", PID2.Target);
		OLED_Printf(0, 32, OLED_6X8, "Act2:%+04.0f  ", PID2.Actual);
		OLED_Printf(0, 40, OLED_6X8, "Out2:%+04.0f  ", PID2.Out);
		
		OLED_Printf(0, 48, OLED_6X8, "%d,%d,%d,%d,%d,%d,%d,%d", (get>>0)&0x01, (get>>1)&0x01, (get>>2)&0x01, (get>>3)&0x01, (get>>4)&0x01, (get>>5)&0x01, (get>>6)&0x01, (get>>7)&0x01);
		OLED_Update();
		
		Buzz_OFF();
		LED1_OFF();
		LED2_OFF();
	}
}


void TIM3_IRQHandler(void)
{
	static uint16_t Count1, Count2;
	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
	{
		Key_Tick();
		
		Count1 ++;
		if (Count1 >= 40)
		{
			Count1 = 0;
			
			PID1.Actual = Encoder_Get1();
			PID2.Actual = Encoder_Get2();
			
			PID_Update1(&PID1);
			PID_Update2(&PID2);
			
			PWM_SetCompare1(PID1.Out);
			PWM_SetCompare2(PID2.Out);
		}
		
		Count2 ++;
		if(Count2 >= 10)
		{
			Count2 = 0;
			
			get = gw_gray_serial_read(GPIOC, GPIO_Pin_4, GPIO_Pin_5);
		}
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}
