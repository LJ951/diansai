#include "ti_msp_dl_config.h"
#include "clock.h"
#include "mpu6050.h"

void SysTick_Handler(void)
{
    tick_ms++;
}

void GROUP1_IRQHandler(void)
{
    switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) {
        /* MPU6050 INT */
        #if defined GPIO_MPU6050_PORT
            #if defined GPIO_MPU6050_INT_IIDX
            case GPIO_MPU6050_INT_IIDX:
            #elif (GPIO_MPU6050_PORT == GPIOA) && (defined GPIO_MULTIPLE_GPIOA_INT_IIDX)
            case GPIO_MULTIPLE_GPIOA_INT_IIDX:
            #elif (GPIO_MPU6050_PORT == GPIOB) && (defined GPIO_MULTIPLE_GPIOB_INT_IIDX)
            case GPIO_MULTIPLE_GPIOB_INT_IIDX:
            #endif
                Read_Quad();
                break;
        #endif
    }
}

