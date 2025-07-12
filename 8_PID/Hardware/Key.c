#include "ti_msp_dl_config.h"

uint8_t KeyNum(void)
{
    if(!DL_GPIO_readPins(GPIO_Key_PORT, GPIO_Key_PIN_Key1_PIN)){
        return 1;
    }
    if(!DL_GPIO_readPins(GPIO_Key_PORT, GPIO_Key_PIN_Key2_PIN)){
        return 2;
    }
    if(!DL_GPIO_readPins(GPIO_Key_PORT, GPIO_Key_PIN_Key3_PIN)){
        return 3;
    }
    if(!DL_GPIO_readPins(GPIO_Key_PORT, GPIO_Key_PIN_Key4_PIN)){
        return 4;
    }
    return 0;
}
