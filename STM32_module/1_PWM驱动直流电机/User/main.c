#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"

uint8_t KeyNum;
int8_t Speed;

int main(void)
{		
	PWM_Init();
	while (1)
	{
		PWM_SetCompare3(100);
		Delay_ms(3000);
		PWM_SetCompare3(50);
		Delay_ms(3000);
		PWM_SetCompare3(10);
		Delay_ms(3000);
	}
}
