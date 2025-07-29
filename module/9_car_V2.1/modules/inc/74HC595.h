#ifndef __74HC595_H_
#define __74HC595_H_

#include "ti_msp_dl_config.h"
#include "bsp_systick.h"

// 全局状态变量声明
extern uint8_t hc595_current_state;

void HC595_output(uint8_t byte_data);
void HC595_Init(void);

// 新增的状态管理函数
void HC595_set_bit(uint8_t bit_position, uint8_t value);
void HC595_clear_bit(uint8_t bit_position);
void HC595_toggle_bit(uint8_t bit_position);
void HC595_update_output(void);
uint8_t HC595_get_state(void);

#endif
