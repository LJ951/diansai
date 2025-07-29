#include "74HC595.h"

#define SHCP_0      DL_GPIO_clearPins(Register_PORT, Register_HCP_PIN)
#define STCP_0      DL_GPIO_clearPins(Register_PORT, Register_TCP_PIN)
#define DS_0        DL_GPIO_clearPins(Register_PORT, Register_DS_PIN)

#define SHCP_1      DL_GPIO_setPins(Register_PORT, Register_HCP_PIN)
#define STCP_1      DL_GPIO_setPins(Register_PORT, Register_TCP_PIN)
#define DS_1        DL_GPIO_setPins(Register_PORT, Register_DS_PIN)

// 全局状态变量，保存当前74HC595的输出状态
uint8_t hc595_current_state = 0x00;

void HC595_output(uint8_t byte_data)
{
    for(int i=0;i<8;i++)
    {
        if(byte_data & (1 << i))
            DS_1;
        else
            DS_0;
        delay_us(1);
        SHCP_1;
        delay_us(1);
        SHCP_0;
        delay_us(1);
    }
    STCP_1;
    delay_us(1);
    STCP_0;
    
    // 更新全局状态
    hc595_current_state = byte_data;
}

void HC595_Init(void)
{
    // 初始化引脚为输出
    SHCP_0;
    STCP_0;
    DS_0;
    
    // 清空74HC595输出和状态
    hc595_current_state = 0x00;
    HC595_output(0x00);
}

// 设置指定位为指定值（0或1）
void HC595_set_bit(uint8_t bit_position, uint8_t value)
{
    if(bit_position >= 8) return; // 位位置超出范围
    
    if(value)
    {
        hc595_current_state |= (1 << bit_position);
    }
    else
    {
        hc595_current_state &= ~(1 << bit_position);
    }
    
    // 立即更新输出
    HC595_output(hc595_current_state);
}

// 清除指定位（设为0）
void HC595_clear_bit(uint8_t bit_position)
{
    HC595_set_bit(bit_position, 0);
}

// 切换指定位状态
void HC595_toggle_bit(uint8_t bit_position)
{
    if(bit_position >= 8) return; // 位位置超出范围
    
    hc595_current_state ^= (1 << bit_position);
    
    // 立即更新输出
    HC595_output(hc595_current_state);
}

// 更新输出（将当前状态输出到74HC595）
void HC595_update_output(void)
{
    HC595_output(hc595_current_state);
}

// 获取当前状态
uint8_t HC595_get_state(void)
{
    return hc595_current_state;
}
