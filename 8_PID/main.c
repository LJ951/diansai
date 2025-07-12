/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "main.h"

float Pitch, Roll, Yaw;
float Pitch_Err, Roll_Err, Yaw_Err;
uint8_t flag;
uint16_t count1, count2, count3;
int16_t Encoder1, Encoder2, Encoder3, Encoder4;
int16_t Speed, Location;

PID_t Inner = {         // 内环PID
	.Kp = 0.3,
	.Ki = 0.3,
	.Kd = 0,
	.OutMax = 100,
	.OutMin = -100
};

PID_t Outer = {         // 外环PID
	.Kp = 0.3,
	.Ki = 0.3,
	.Kd = 0,
	.OutMax = 50,
	.OutMin = -50
};

int main(void)
{

    SYSCFG_DL_init();
    SysTick_Init();

    MPU6050_Init();
    OLED_Init();
    OLED_Clear();

    Pitch = pitch;
    Roll = roll;
    Yaw = yaw;

    while(1)
    {
        OLED_Printf(0, 0, OLED_8X16, "mpu6050:Init...");
        OLED_Update();
        if(flag)
        {
            Pitch_Err = pitch;
            Roll_Err  = roll;
            Yaw_Err   = yaw;
            OLED_Clear();
            break;
        }
    }

    while (1) 
    {
        // Motor_L1(50);
        Encoder1 = Get_Encoder(1);
        Encoder2 = Get_Encoder(2);
        Encoder3 = Get_Encoder(3);
        Encoder4 = Get_Encoder(4);
        OLED_Printf(0, 0, OLED_6X8, "Encoder1:%d     ", Encoder1);
        OLED_Printf(0, 8, OLED_6X8, "Encoder2:%d     ", Encoder2);
        OLED_Printf(0, 16, OLED_6X8, "Encoder3:%d    ", Encoder3);
        OLED_Printf(0, 24, OLED_6X8, "Encoder4:%d    ", Encoder4);
        OLED_Printf(0, 32, OLED_6X8, "Pitch:%0.2f   ", Pitch);
        OLED_Printf(0, 40, OLED_6X8, "Roll:%0.2f    ", Roll);
        OLED_Printf(0, 48, OLED_6X8, "Yaw:%0.2f     ", Yaw);
        OLED_Update();
        
        
    }
}

void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMER_IIDX_ZERO:
        {
            Pitch = pitch - Pitch_Err;
            Roll  = roll  - Roll_Err;
            Yaw   = yaw   - Yaw_Err;

            count1++;
            count2++;
            count3++;
            // if(count1 >= 4)
            // {
            //     Speed = Get_Encoder();
            //     Location += Speed;
            //     Inner.Actual = Speed;
            //     PID_Update(&Inner);

            //     Outer.Actual = Location;
            //     PID_Update(&Outer);
            //     Inner.Target = Outer.Out;
            // }

            if(count2 >= 2000)
            {
                count2 = 0;
                flag = 1;
                
            }
            if(count3 >= 3000)
            {
                count3 = 0;
                Yaw_Err += 0.01;
                
            }
        }
            break;
        default:
            break;
    }
}
