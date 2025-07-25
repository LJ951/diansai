#ifndef __SENSOR_H_
#define __SENSOR_H_

#include <stdint.h>
#include <stm32f10x_gpio.h>

void sensor_init(void);
uint8_t gw_gray_serial_read(GPIO_TypeDef *GPIOx, uint16_t gpio_clk, uint16_t gpio_dat);



#endif
