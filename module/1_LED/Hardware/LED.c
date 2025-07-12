#include "ti_msp_dl_config.h"

void LED(uint8_t mode)
{
	if(mode)
		DL_GPIO_clearPins(GPIO_LED1_PORT, GPIO_LED1_PIN_LED1_PIN);
	else
		DL_GPIO_setPins(GPIO_LED1_PORT, GPIO_LED1_PIN_LED1_PIN);
}
