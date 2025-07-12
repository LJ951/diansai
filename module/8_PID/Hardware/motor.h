#ifndef __MOTOR_H_
#define __MOTOR_H_

void duty_R(uint16_t duty, uint8_t channl);
void duty_L(uint16_t duty, uint8_t channl);
void Motor_R1(float pwm);
void Motor_R2(float pwm);
void Motor_L1(float pwm);
void Motor_L2(float pwm);

#endif
