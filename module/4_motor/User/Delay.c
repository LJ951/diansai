#include "ti_msp_dl_config.h"

void Delay_ms(uint32_t ms)
{
	while(ms--)
	{
		delay_cycles(80000);
	}
}

void Delay_us(uint32_t us)
{
	while(us--)
	{
		delay_cycles(80);
	}
}
