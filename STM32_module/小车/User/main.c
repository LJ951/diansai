#include "stm32f10x.h"                  // Device header
#include "stdbool.h"
#include "stdio.h"
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
#include "car.h"

uint8_t KeyNum;
uint8_t get;
bool Buzz, LED1, LED2, diagonal;

car Car = {
	.state = 0,
	.on = 0,
};
Get data;

//左轮的PID
PID_1 PID1 = {
	.Kp = 0.41,
	.Ki = 0.26,
	.Kd = 0.08,
	.OutMax = 80,
	.OutMin = 0,
};

//右轮的PID
PID_1 PID2 = {
	.Kp = 0.41,
	.Ki = 0.26,
	.Kd = 0.08,
	.OutMax = 80,
	.OutMin = 0,
};

//循迹PID
PID_1 PID_sensor = {
	.Kp = 0.41,
	.Ki = 0.26,
	.Kd = 0.08,
	.OutMax = 10,
	.OutMin = -10,
	.Target = 0,
};

//位置式PID
PID_1 PID_diagonal = {
	.Kp = 0.41,
	.Ki = 0.26,
	.Kd = 0.08,
	.OutMax = 80,
	.OutMin = 0,
};

// 循迹
void sensor_(void)
{
	uint8_t PID_Out;
	uint8_t speed_L, speed_R;

	PID_Out = PID_sensor.Out * 8;
	speed_L = 80 - PID_Out;
	speed_R = 80 - PID_Out;
	
	PID1.Target = speed_L;
	PID2.Target = speed_R;
}


int main(void)
{		
	//初始化
	LED_Init();
	Buzzer_Init();
	Timer_Init();
	OLED_Init();
	PWM_Init();
	Encoder_Init1();
	Encoder_Init2();
	Key_Init();
	Serial_Init();
	sensor_init();
	
	Buzz=1;
	
	while (1)
	{
		KeyNum = Key_GetNum();
		
		data.one = (get>>0)&0x01;
		data.two = (get>>1)&0x01;
		data.three = (get>>2)&0x01;
		data.four = (get>>3)&0x01;
		data.five = (get>>4)&0x01;
		data.six = (get>>5)&0x01;
		data.seven = (get>>6)&0x01;
		data.eight = (get>>7)&0x01;
		
		if(KeyNum == 1){
			Car.state ++;
		}
		if(KeyNum == 2){
			Car.on = !Car.on;
		}
		if(Car.state >= 4){
			Car.state = 0;
		}
		
		switch(Car.state){
			//第一问
			case 0:{
				if(Car.on){
					
					//直走
					PID1.Target = 70;
					PID2.Target = 70;
					
					//走到B点蜂鸣器响并停止
					if((data.three & data.four & data.five & data.six) == 0){
						Buzz = 1;
						PID1.Target = 0;
						PID2.Target = 0;
						Car.on = 0;
					}
				}
			}break;
			
			//第二问
			case 1:{
				if(Car.on){
					for(int i=0;i<2;i++){
						//直走
						PID1.Target = 70;
						PID2.Target = 70;
						
						//走到B点蜂鸣器响
						if((data.three & data.four & data.five & data.six) == 0){
							Buzz = 1;
							//循迹
							sensor_();
						}
						if((data.one & data.two & data.three & data.four & data.five & data.six & data.seven & data.eight) == 1){
								
							}
						Car.on = 0;
					}
				}
			}break;
			
			//第三问
			case 2:{
				if(Car.on){
					// 开启位置式PID
					diagonal = 1;
					PID1.Actual = 0;
					PID2.Actual = 0;
					
					
				}
			}break;
			
			//第四问
			case 3:{
				if(Car.on){
					for(int i=0;i<4;i++){
						
					}
				}
			}break;
		};
		
		if(Car.on == 0){
			PID1.Target = 0;
			PID2.Target = 0;
		}
		
		//OLED显示数据
		OLED_Printf(0, 0, OLED_6X8, "Tar1:%+04.0f  ", PID1.Target);
		OLED_Printf(0, 8, OLED_6X8, "Act1:%+04.0f  ", PID1.Actual);
		OLED_Printf(0, 16, OLED_6X8, "Out1:%+04.0f  ", PID1.Out);
		
		OLED_Printf(64, 0, OLED_6X8, "Tar2:%+04.0f  ", PID2.Target);
		OLED_Printf(64, 8, OLED_6X8, "Act2:%+04.0f  ", PID2.Actual);
		OLED_Printf(64, 16, OLED_6X8, "Out2:%+04.0f  ", PID2.Out);
		
		OLED_Printf(0, 24, OLED_6X8, "state:%d  ", Car.state);
		OLED_Printf(0, 32, OLED_6X8, "on:%d  ", Car.on);
		OLED_Printf(64, 32, OLED_6X8, "Buzz:%d  ", Buzz);
		OLED_Printf(0, 40, OLED_6X8, "sensorValues:%+02.0f  ", PID_sensor.Actual);
		OLED_Printf(0, 48, OLED_6X8, "data:%d,%d,%d,%d,%d,%d,%d,%d  ", data.one, data.two, data.three, data.four, data.five, data.six, data.seven, data.eight);
		
		OLED_Update();
		
	}
}


void TIM3_IRQHandler(void)
{
	static uint16_t Count1, Count2, Count3;
	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
	{
		//按键消抖
		Key_Tick();

		Count1 ++;
		Count2 ++;
		Count3 ++;
		
		//每40毫秒运行一次
		if (Count1 >= 40)
		{
			Count1 = 0;
			
			//PID算法
			if(diagonal){
				PID1.Actual += Encoder_Get1();
				PID2.Actual += Encoder_Get2();
			}
			else{
				PID1.Actual = Encoder_Get1();
				PID2.Actual = Encoder_Get2();
			}
			
			if(data.one == 0){
				PID_sensor.Actual += -4;
			}
			if(data.two == 0){
				PID_sensor.Actual += -3;
			}
			if(data.three == 0){
				PID_sensor.Actual += -2;
			}
			if(data.four == 0){
				PID_sensor.Actual += -1;
			}
			if(data.five == 0){
				PID_sensor.Actual += 1;
			}
			if(data.six == 0){
				PID_sensor.Actual += 2;
			}
			if(data.seven == 0){
				PID_sensor.Actual += 3;
			}
			if(data.eight == 0){
				PID_sensor.Actual += 4;
			}
			
			PID_Update1(&PID_sensor);
			PID_Update1(&PID1);
			PID_Update1(&PID2);
			PID_Update1(&PID_diagonal);
			
			PWM_SetCompare1(PID1.Out);
			PWM_SetCompare2(PID2.Out);
		}
		
		//每10毫秒运行一次
		if(Count2 >= 10)
		{
			Count2 = 0;
			
			//循迹数据获取
			get = gw_gray_serial_read(GPIOC, GPIO_Pin_4, GPIO_Pin_5);
		}
		
		//蜂鸣器响500毫秒
		if(Buzz){
			Count3++;
			Buzz_ON();
			if(Count3 >= 500){
				Count3 = 0;
				Buzz = 0;
				Buzz_OFF();
			}
		}
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}
