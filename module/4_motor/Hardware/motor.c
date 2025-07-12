#include "ti_msp_dl_config.h"
#include "74HC595.h"

void duty_R(float duty, uint8_t channl)
{
    uint32_t CompareBalue;
    CompareBalue = 10000 - 10000 * duty;
    if(channl)
        DL_TimerG_setCaptureCompareValue(PWM_R_INST, CompareBalue, DL_TIMER_CC_1_INDEX);
    else
        DL_TimerG_setCaptureCompareValue(PWM_R_INST, CompareBalue, DL_TIMER_CC_0_INDEX);
}

void duty_L(float duty, uint8_t channl)
{
    uint32_t CompareBalue;
    CompareBalue = 10000 - 10000 * duty;
    if(channl)
        DL_TimerG_setCaptureCompareValue(PWM_L_INST, CompareBalue, DL_TIMER_CC_1_INDEX);
    else
        DL_TimerG_setCaptureCompareValue(PWM_L_INST, CompareBalue, DL_TIMER_CC_0_INDEX);
}

void Motor_R1(float pwm, uint8_t mode)
{
    if(mode)
    {
        stoeage_Out(5);
        duty_R(pwm, 0);
    }
    else 
    {
        stoeage_Out(6);
        duty_R(pwm, 0);
    }
    
}

void Motor_R2(float pwm, uint8_t mode)
{
    if(mode)
    {
        stoeage_Out(7);
        duty_R(pwm, 1);
    }
    else 
    {
        stoeage_Out(8);
        duty_R(pwm, 1);
    }
    
}

void Motor_L1(float pwm, uint8_t mode)
{
    if(mode)
    {
        stoeage_Out(1);
        duty_L(pwm, 0);
    }
    else 
    {
        stoeage_Out(2);
        duty_L(pwm, 0);
    }
    
}

void Motor_L2(float pwm, uint8_t mode)
{
    if(mode)
    {
        stoeage_Out(3);
        duty_L(pwm, 1);
    }
    else 
    {
        stoeage_Out(4);
        duty_L(pwm, 1);
    }
    
}
