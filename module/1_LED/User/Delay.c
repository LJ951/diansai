#include "ti_msp_dl_config.h"

#define DELAY (80000)

void Delay_ms(uint32_t ms)
{
	while(ms--)
	{
		delay_cycles(DELAY);
	}
}
