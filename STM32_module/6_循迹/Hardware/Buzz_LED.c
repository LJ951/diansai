#include "stm32f10x.h"                  // Device header

void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOC, GPIO_Pin_12);
}

void Buzz_ON(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_12);
}

void Buzz_OFF(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_12);
}

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void LED1_ON(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

void LED1_OFF(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void LED2_ON(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
}

void LED2_OFF(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);
}
