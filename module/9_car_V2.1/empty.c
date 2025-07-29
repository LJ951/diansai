#include "empty.h"

void car_Init(void)
{
	SYSCFG_DL_init();
	pIICInterface_t siic = &User_sIICDev;
	siic->init();
	//串口1调试中断
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
	NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);
	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
	DL_Timer_startCounter(PWM_L_INST);
	DL_Timer_startCounter(PWM_R_INST);
    DL_TimerG_startCounter(TIMER_0_INST);
	MPU6050_initialize();           //MPU6050初始化	
	DMP_Init();                     //初始化DMP 	
	OLED_Init();
}

int main(void)
{
    car_Init();

    while (1) {
		Topic();
    }
}


