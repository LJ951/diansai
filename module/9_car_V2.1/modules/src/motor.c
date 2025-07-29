#include "motor.h"


// ================== 74HC595输出位定义 ==================
// 右前电机（R1）正转/反转控制位
#define MOTOR_R1_FWD_BIT  0
#define MOTOR_R1_REV_BIT  1
// 右后电机（R2）正转/反转控制位
#define MOTOR_R2_FWD_BIT  3
#define MOTOR_R2_REV_BIT  2
// 左前电机（L1）正转/反转控制位
#define MOTOR_L1_FWD_BIT  5
#define MOTOR_L1_REV_BIT  4
// 左后电机（L2）正转/反转控制位
#define MOTOR_L2_FWD_BIT  6
#define MOTOR_L2_REV_BIT  7

// ================== PWM参数定义 ==================
#define MOTOR_PWM_PERIOD 4000.0f   // PWM周期（可根据实际硬件调整）
#define MOTOR_DEADZONE   0.02f     // 死区阈值（小于此值认为电机停）

float val;

/**
 * @brief 设置指定电机的PWM占空比。
 * @param duty    占空比（0~1，已取绝对值）
 * @param is_left 是否为左侧电机（1:左侧，0:右侧）
 * @param channel 通道号（0/1）
 */
static void set_pwm(float duty, uint8_t is_left, uint8_t channel)
{
    val = MOTOR_PWM_PERIOD - (MOTOR_PWM_PERIOD * duty);
    if(is_left)
        DL_Timer_setCaptureCompareValue(PWM_L_INST, val, channel);
    else
        DL_Timer_setCaptureCompareValue(PWM_R_INST, val, channel);
}

/**
 * @brief 设置电机方向位（正转/反转/停止）。
 * @param fwd_bit 正转控制位编号
 * @param rev_bit 反转控制位编号
 * @param pwm     PWM值（正为正转，负为反转，0为停）
 */
static void set_motor_dir(uint8_t fwd_bit, uint8_t rev_bit, float pwm)
{
    // 先清除方向位
    HC595_clear_bit(fwd_bit);
    HC595_clear_bit(rev_bit);
    if(pwm > MOTOR_DEADZONE)
        HC595_set_bit(fwd_bit, 1);   // 正转
    else if(pwm < -MOTOR_DEADZONE)
        HC595_set_bit(rev_bit, 1);   // 反转
    // 否则为停
}

/**
 * @brief 电机驱动初始化。建议上电后先调用，确保所有电机停止。
 */
void Motor_Init(void)
{
    // 如有需要可初始化74HC595
    // HC595_Init();
    Motor_Stop_All();
}

/**
 * @brief 一次性设置所有电机的PWM和方向。
 *        正负号区分正反转，0为停止。
 * @param pwm_r1 右前电机PWM
 * @param pwm_r2 右后电机PWM
 * @param pwm_l1 左前电机PWM
 * @param pwm_l2 左后电机PWM
 */
void Motor_Set_All(float pwm_r1, float pwm_r2, float pwm_l1, float pwm_l2)
{
    // R1
    set_motor_dir(MOTOR_R1_FWD_BIT, MOTOR_R1_REV_BIT, pwm_r1);
    set_pwm(fabsf(pwm_r1), 0, 0);
    // R2
    set_motor_dir(MOTOR_R2_FWD_BIT, MOTOR_R2_REV_BIT, pwm_r2);
    set_pwm(fabsf(pwm_r2), 0, 1);
    // L1
    set_motor_dir(MOTOR_L1_FWD_BIT, MOTOR_L1_REV_BIT, pwm_l1);
    set_pwm(fabsf(pwm_l1), 1, 0);
    // L2
    set_motor_dir(MOTOR_L2_FWD_BIT, MOTOR_L2_REV_BIT, pwm_l2);
    set_pwm(fabsf(pwm_l2), 1, 1);
}

/**
 * @brief 停止所有电机（方向位清零，PWM输出为0）。
 */
void Motor_Stop_All(void)
{
    // 清除所有方向位
    for(int i=0;i<8;i++)
        HC595_clear_bit(i);
    // 所有PWM输出为0
    set_pwm(0,0,0);
    set_pwm(0,0,1);
    set_pwm(0,1,0);
    set_pwm(0,1,1);
}

