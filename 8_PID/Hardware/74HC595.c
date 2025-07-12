#include "ti_msp_dl_config.h"

#define SHCP_0      DL_GPIO_clearPins(GPIO_595_PORT, GPIO_595_PIN_595SHCP_PIN)
#define STCP_0      DL_GPIO_clearPins(GPIO_595_PORT, GPIO_595_PIN_595STCP_PIN)
#define DS_0        DL_GPIO_clearPins(GPIO_595_PORT, GPIO_595_PIN_595DS_PIN)

#define SHCP_1      DL_GPIO_setPins(GPIO_595_PORT, GPIO_595_PIN_595SHCP_PIN)
#define STCP_1      DL_GPIO_setPins(GPIO_595_PORT, GPIO_595_PIN_595STCP_PIN)
#define DS_1        DL_GPIO_setPins(GPIO_595_PORT, GPIO_595_PIN_595DS_PIN)

uint8_t HexNum[8] = {
    0x01, 0x02,   //L1电机正反转
    0x04, 0x08,   //L2电机正反转
    0x10, 0x20,   //R1电机正反转
    0x40, 0x80,   //R2电机正反转
 };

 uint8_t BinNum[8];

 void hex_to_bin(uint8_t hex, uint8_t *bin)
 {
    for (int i=0;i<8;i++)
    {
        bin[i] = (hex >> i) & 1;
    }
 }

void stoeage_Init(void)
{
    SHCP_0;
    STCP_0;
}

void stoeage_W(uint8_t data)
{
    SHCP_1;
    if(data)
        DS_1;
    else
        DS_0;
    SHCP_0;
}

void stoeage_Clear(void)
{
    for(int i;i<8;i++)
    {
        stoeage_W(0);
    }
    STCP_0;
}

void stoeage_Update(void)
{
    STCP_1;

    stoeage_Init();
}

void stoeage_Out(uint8_t motor)
{
    stoeage_Init();
    for(int i;i<8;i++)
    {
        hex_to_bin(HexNum[motor - 1], BinNum);
        stoeage_W(BinNum[i]);
    }
    stoeage_Update();
}

