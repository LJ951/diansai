#include "stm32f10x.h"                  // Device header
#include "sensor.h"

#define GW_GRAY_SERIAL_GPIO_GROUP GPIOC
#define GW_GRAY_SERIAL_GPIO_CLK GPIO_Pin_4
#define GW_GRAY_SERIAL_GPIO_DAT GPIO_Pin_5
#define GW_GRAY_DELAY_TICK 27

void sensor_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GW_GRAY_SERIAL_GPIO_DAT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GW_GRAY_SERIAL_GPIO_GROUP, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GW_GRAY_SERIAL_GPIO_CLK;
	GPIO_Init(GW_GRAY_SERIAL_GPIO_GROUP, &GPIO_InitStructure);
}


static void gw_gray_delay(uint32_t delay)
{
	volatile uint32_t delay_tick = delay;
	
	while (delay_tick > 0) {
		delay_tick--;
	}
}

uint8_t gw_gray_serial_read(GPIO_TypeDef *GPIOx, uint16_t gpio_clk, uint16_t gpio_dat)
{
	uint8_t ret = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		GPIO_ResetBits(GPIOx, gpio_clk);
		gw_gray_delay(GW_GRAY_DELAY_TICK);

		ret |= GPIO_ReadInputDataBit(GPIOx, gpio_dat) << i;

		GPIO_SetBits(GPIOx, gpio_clk);

		gw_gray_delay(GW_GRAY_DELAY_TICK);
	}
	
	return ret;
}

