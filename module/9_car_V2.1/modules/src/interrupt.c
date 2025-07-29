#include "interrupt.h"

int16_t Encoder_Count1, Encoder_Count2, Encoder_Count3, Encoder_Count4;
// int16_t Speed1, Speed2, Speed3, Speed4;
float pitch, roll, yaw, Pitch_Err, Roll_Err, Yaw_Err;
uint16_t count1, count2;
uint8_t flag;

int16_t Get_Encoder(uint8_t Encoder)
{
    int16_t Temp;
    switch(Encoder)
    {
        case 1:
            Temp = Encoder_Count2;
            Encoder_Count2 = 0;
            return Temp;
            break;
        case 2:
            Temp = Encoder_Count1;
            Encoder_Count1 = 0;
            return Temp;
            break;
        case 3:
            Temp = Encoder_Count3;
            Encoder_Count3 = 0;
            return Temp;
            break;
        case 4:
            Temp = Encoder_Count4;
            Encoder_Count4 = 0;
            return Temp;
        default:
            return 0;
    }
}

void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_Timer_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMER_IIDX_ZERO:
        {
			Key_Tick();

			count1++;

            if(count1 >= 2)
            {
                count1 = 0;

                PID_L1.Actual = Get_Encoder(1);
                PID_L2.Actual = Get_Encoder(2);
                PID_R1.Actual = Get_Encoder(3);
                PID_R2.Actual = Get_Encoder(4);

                PID_Update(&PID_L1);
                PID_Update(&PID_L2);
                PID_Update(&PID_R1);
                PID_Update(&PID_R2);

                Motor_Set_All(PID_R1.Out/100.0, PID_R2.Out/100.0, PID_L1.Out/100.0, PID_L2.Out/100.0);
            }

			if(count2 <= 2100)
                count2++;
            if(count2 == 2100)
                flag = 1;
		}
	}
}

//外部中断  dmp相关内容
void GROUP1_IRQHandler(void)//Group1的中断服务函数
{
	uint32_t portE2_intp = DL_GPIO_getEnabledInterruptStatus(MPU6050_PORT,MPU6050_INT_PIN_PIN);

    uint8_t Encodeg_flag_L1, A_flag1, B_flag1, direction_flag_L1;
    uint8_t Encodeg_flag_L2, A_flag2, B_flag2, direction_flag_L2;

	uint8_t Encodeg_flag_R1, C_flag1, D_flag1, direction_flag_R1;
    uint8_t Encodeg_flag_R2, C_flag2, D_flag2, direction_flag_R2;
    uint8_t Encodeg_flag,A_flag,B_flag,direction_flag;

	//MPU6050下降沿中断,频率可以通过DMP配置,默认200Hz
	if( (portE2_intp&MPU6050_INT_PIN_PIN)==MPU6050_INT_PIN_PIN )
	{
		Read_DMP();
        if(flag)
        {
            flag = 0;
            Pitch_Err = Pitch;
            Roll_Err  = Roll;
            Yaw_Err   = Yaw;
        }
		mpu6050.pitch = Pitch - Pitch_Err;
		mpu6050.roll = Roll - Roll_Err;
		mpu6050.yaw = Yaw - Yaw_Err;
		mpu6050.gyro.x=gyro[0];
		mpu6050.gyro.y=gyro[1];
		mpu6050.gyro.z=gyro[2];
		mpu6050.accel.x=accel[0];
		mpu6050.accel.y=accel[0];
		mpu6050.accel.z=accel[0];
		//清空标志位
		// DL_GPIO_clearInterruptStatus(MPU6050_PORT,MPU6050_INT_PIN_PIN);
	}

    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_L1_E1_PIN))
    {
        Encodeg_flag_L1 = 1;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L1_E1_PIN)) A_flag1 = 1;
        else A_flag1 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L1_E2_PIN)) B_flag1 = 1;
        else B_flag1 = 0;
        direction_flag_L1 = A_flag1+B_flag1+Encodeg_flag_L1;
        if(direction_flag_L1 == 0 || direction_flag_L1 ==2)Encoder_Count1++;
        else Encoder_Count1--;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_L1_E1_PIN);
    }
    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_L1_E2_PIN))
    {
        Encodeg_flag_L1 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L1_E1_PIN)) A_flag1 = 1;
        else A_flag1 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L1_E2_PIN)) B_flag1 = 1;
        else B_flag1 = 0;
        direction_flag_L1 = A_flag1 + B_flag1 + Encodeg_flag_L1;
        if(direction_flag_L1 == 0 || direction_flag_L1 ==2)Encoder_Count1++;
        else Encoder_Count1--;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_L1_E2_PIN);
    }

    // L2编码器
    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_L2_E1_PIN))
    {
        Encodeg_flag_L2 = 1;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L2_E1_PIN)) A_flag2 = 1;
        else A_flag2 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L2_E2_PIN)) B_flag2 = 1;
        else B_flag2 = 0;
        direction_flag_L2 = A_flag2+B_flag2+Encodeg_flag_L2;
        if(direction_flag_L2 == 0 || direction_flag_L2 ==2)Encoder_Count2++;
        else Encoder_Count2--;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_L2_E1_PIN);
    }
    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_L2_E2_PIN))
    {
        Encodeg_flag_L2 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L2_E1_PIN)) A_flag2 = 1;
        else A_flag2 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_L2_E2_PIN)) B_flag2 = 1;
        else B_flag2 = 0;
        direction_flag_L2 = A_flag2 + B_flag2 + Encodeg_flag_L2;
        if(direction_flag_L2 == 0 || direction_flag_L2 ==2)Encoder_Count2++;
        else Encoder_Count2--;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_L2_E2_PIN);
    }

    // R1编码器
    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_R1_E1_PIN))
    {
        Encodeg_flag_R1 = 1;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R1_E1_PIN)) C_flag1 = 1;
        else C_flag1 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R1_E2_PIN)) D_flag1 = 1;
        else D_flag1 = 0;
        direction_flag_R1 = C_flag1+D_flag1+Encodeg_flag_R1;
        if(direction_flag_R1 == 0 || direction_flag_R1 ==2)Encoder_Count3--;
        else Encoder_Count3++;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_R1_E1_PIN);
    }
    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_R1_E2_PIN))
    {
        Encodeg_flag_R1 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R1_E1_PIN)) C_flag1 = 1;
        else C_flag1 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R1_E2_PIN)) D_flag1 = 1;
        else D_flag1 = 0;
        direction_flag_R1 = C_flag1 + D_flag1 + Encodeg_flag_R1;
        if(direction_flag_R1 == 0 || direction_flag_R1 ==2)Encoder_Count3--;
        else Encoder_Count3++;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_R1_E2_PIN);
    }

    // R2编码器
    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_R2_E1_PIN))
    {
        Encodeg_flag_R2 = 1;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R2_E1_PIN)) C_flag2 = 1;
        else C_flag2 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R2_E2_PIN)) D_flag2 = 1;
        else D_flag2 = 0;
        direction_flag_R2 = C_flag2+D_flag2+Encodeg_flag_R2;
        if(direction_flag_R2 == 0 || direction_flag_R2 ==2)Encoder_Count4--;
        else Encoder_Count4++;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_R2_E1_PIN);
    }
    if(DL_GPIO_getEnabledInterruptStatus(Encoder_PORT, Encoder_R2_E2_PIN))
    {
        Encodeg_flag_R2 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R2_E1_PIN)) C_flag2 = 1;
        else C_flag2 = 0;
        if(DL_GPIO_readPins(Encoder_PORT, Encoder_R2_E2_PIN)) D_flag2 = 1;
        else D_flag2 = 0;
        direction_flag_R2 = C_flag2 + D_flag2 + Encodeg_flag_R2;
        if(direction_flag_R2 == 0 || direction_flag_R2 ==2)Encoder_Count4--;
        else Encoder_Count4++;
        
        DL_GPIO_clearInterruptStatus(Encoder_PORT, Encoder_R2_E2_PIN);
    }
}

//串口0,用于调试
void UART_0_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) 
    {
        case DL_UART_IIDX_RX:
            DL_UART_transmitData(UART_0_INST,DL_UART_Main_receiveData(UART_0_INST));
            break;
        default:
            break;
    }
}


