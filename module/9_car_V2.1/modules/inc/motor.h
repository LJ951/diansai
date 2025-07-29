#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "74HC595.h"
#include <math.h>
#include "ti_msp_dl_config.h"

void Motor_Init(void);
void Motor_Set_All(float pwm_r1, float pwm_r2, float pwm_l1, float pwm_l2);
void Motor_Stop_All(void);

#endif
