#include "ti_msp_dl_config.h"

uint8_t KeyNum(void)
{
    if(!DL_GPIO_readPins(GPIO_Key1_PORT, GPIO_Key1_PIN_Key1_PIN)){
        return 1;
    }
    return 0;
}
