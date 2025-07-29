#include "ti_msp_dl_config.h"

uint8_t Key_Num;

uint8_t Key_GetNum(void)
{
	uint8_t Temp;
	if (Key_Num)
	{
		Temp = Key_Num;
		Key_Num = 0;
		return Temp;
	}
	return 0;
}

uint8_t Key_GetState(void)
{
	if(!DL_GPIO_readPins(Key_PORT, Key_Key1_PIN)){
        return 1;
    }
    if(!DL_GPIO_readPins(Key_PORT, Key_Key2_PIN)){
        return 2;
    }
    if(!DL_GPIO_readPins(Key_PORT, Key_Key3_PIN)){
        return 3;
    }
    if(!DL_GPIO_readPins(Key_PORT, Key_Key4_PIN)){
        return 4;
    }
    return 0;
}

void Key_Tick(void)
{
	static uint8_t Count;
	static uint8_t CurrState, PrevState;
	
	Count ++;
	if (Count >= 20)
	{
		Count = 0;
		
		PrevState = CurrState;
		CurrState = Key_GetState();
		
		if (CurrState == 0 && PrevState != 0)
		{
			Key_Num = PrevState;
		}
	}
}
