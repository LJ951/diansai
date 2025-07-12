#include "ti_msp_dl_config.h"
#include "interrupt.h"
#include "clock.h"
#include "mpu6050.h"
#include "Serial.h"

int16_t Encoder_Count1, Encoder_Count2, Encoder_Count3, Encoder_Count4;

void SysTick_Handler(void)
{
    tick_ms++;
}

int16_t Get_Encoder(uint8_t Encoder)
{
    int16_t Temp;
    switch(Encoder)
    {
        case 1:
            Temp = Encoder_Count1;
            Encoder_Count1 = 0;
            return Temp;
            break;
        case 2:
            Temp = Encoder_Count2;
            Encoder_Count2 = 0;
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
    }
}

void GROUP1_IRQHandler(void)
{
    uint8_t Encodeg_flag_L1, A_flag1, B_flag1, direction_flag_L1;
    uint8_t Encodeg_flag_L2, A_flag2, B_flag2, direction_flag_L2;

	uint8_t Encodeg_flag_R1, C_flag1, D_flag1, direction_flag_R1;
    uint8_t Encodeg_flag_R2, C_flag2, D_flag2, direction_flag_R2;
    switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) {
        
        /* MPU6050 INT */
        #if defined GPIO_MPU6050_PORT
            #if defined GPIO_MPU6050_INT_IIDX
            case GPIO_MPU6050_INT_IIDX:
            #elif (GPIO_MPU6050_PORT == GPIOA) && (defined GPIO_MULTIPLE_GPIOA_INT_IIDX)
            case GPIO_MULTIPLE_GPIOA_INT_IIDX:
            #elif (GPIO_MPU6050_PORT == GPIOB) && (defined GPIO_MULTIPLE_GPIOB_INT_IIDX)
            case GPIO_MULTIPLE_GPIOB_INT_IIDX:
            // L1编码器
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L1_E1_PIN))
            {
                Encodeg_flag_L1 = 1;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L1_E1_PIN)) A_flag1 = 1;
                else A_flag1 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L1_E2_PIN)) B_flag1 = 1;
                else B_flag1 = 0;
                direction_flag_L1 = A_flag1+B_flag1+Encodeg_flag_L1;
                if(direction_flag_L1 == 0 || direction_flag_L1 ==2)Encoder_Count1++;
                else Encoder_Count1--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L1_E1_PIN);
            }
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L1_E2_PIN))
            {
                Encodeg_flag_L1 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L1_E1_PIN)) A_flag1 = 1;
                else A_flag1 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L1_E2_PIN)) B_flag1 = 1;
                else B_flag1 = 0;
                direction_flag_L1 = A_flag1 + B_flag1 + Encodeg_flag_L1;
                if(direction_flag_L1 == 0 || direction_flag_L1 ==2)Encoder_Count1++;
                else Encoder_Count1--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L1_E2_PIN);
            }

            // L2编码器
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L2_E1_PIN))
            {
                Encodeg_flag_L2 = 1;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L2_E1_PIN)) A_flag2 = 1;
                else A_flag2 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L2_E2_PIN)) B_flag2 = 1;
                else B_flag2 = 0;
                direction_flag_L2 = A_flag2+B_flag2+Encodeg_flag_L2;
                if(direction_flag_L2 == 0 || direction_flag_L2 ==2)Encoder_Count2++;
                else Encoder_Count2--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L2_E1_PIN);
            }
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L2_E2_PIN))
            {
                Encodeg_flag_L2 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L2_E1_PIN)) A_flag2 = 1;
                else A_flag2 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_L2_E2_PIN)) B_flag2 = 1;
                else B_flag2 = 0;
                direction_flag_L2 = A_flag2 + B_flag2 + Encodeg_flag_L2;
                if(direction_flag_L2 == 0 || direction_flag_L2 ==2)Encoder_Count2++;
                else Encoder_Count2--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L2_E2_PIN);
            }

            // R1编码器
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R1_E1_PIN))
            {
                Encodeg_flag_R1 = 1;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R1_E1_PIN)) C_flag1 = 1;
                else C_flag1 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R1_E2_PIN)) D_flag1 = 1;
                else D_flag1 = 0;
                direction_flag_R1 = C_flag1+D_flag1+Encodeg_flag_R1;
                if(direction_flag_R1 == 0 || direction_flag_R1 ==2)Encoder_Count3++;
                else Encoder_Count3--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R1_E1_PIN);
            }
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R1_E2_PIN))
            {
                Encodeg_flag_R1 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R1_E1_PIN)) C_flag1 = 1;
                else C_flag1 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R1_E2_PIN)) D_flag1 = 1;
                else D_flag1 = 0;
                direction_flag_R1 = C_flag1 + D_flag1 + Encodeg_flag_R1;
                if(direction_flag_R1 == 0 || direction_flag_R1 ==2)Encoder_Count3++;
                else Encoder_Count3--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R1_E2_PIN);
            }

            // R2编码器
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R2_E1_PIN))
            {
                Encodeg_flag_R2 = 1;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R2_E1_PIN)) C_flag2 = 1;
                else C_flag2 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R2_E2_PIN)) D_flag2 = 1;
                else D_flag2 = 0;
                direction_flag_R2 = C_flag2+D_flag2+Encodeg_flag_R2;
                if(direction_flag_R2 == 0 || direction_flag_R2 ==2)Encoder_Count4++;
                else Encoder_Count4--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R2_E1_PIN);
            }
            if(DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R2_E2_PIN))
            {
                Encodeg_flag_R2 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R2_E1_PIN)) C_flag2 = 1;
                else C_flag2 = 0;
                if(DL_GPIO_readPins(GPIO_Encoder_PORT, GPIO_Encoder_R2_E2_PIN)) D_flag2 = 1;
                else D_flag2 = 0;
                direction_flag_R2 = C_flag2 + D_flag2 + Encodeg_flag_R2;
                if(direction_flag_R2 == 0 || direction_flag_R2 ==2)Encoder_Count4++;
                else Encoder_Count4--;
                
                DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R2_E2_PIN);
            }
            
            #endif
                Read_Quad();

                break;
        #endif
    }
}


