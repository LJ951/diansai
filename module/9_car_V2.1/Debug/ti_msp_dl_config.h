/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_R */
#define PWM_R_INST                                                         TIMA0
#define PWM_R_INST_IRQHandler                                   TIMA0_IRQHandler
#define PWM_R_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define PWM_R_INST_CLK_FREQ                                             40000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_R_C0_PORT                                                 GPIOA
#define GPIO_PWM_R_C0_PIN                                          DL_GPIO_PIN_0
#define GPIO_PWM_R_C0_IOMUX                                       (IOMUX_PINCM1)
#define GPIO_PWM_R_C0_IOMUX_FUNC                      IOMUX_PINCM1_PF_TIMA0_CCP0
#define GPIO_PWM_R_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_R_C1_PORT                                                 GPIOA
#define GPIO_PWM_R_C1_PIN                                          DL_GPIO_PIN_1
#define GPIO_PWM_R_C1_IOMUX                                       (IOMUX_PINCM2)
#define GPIO_PWM_R_C1_IOMUX_FUNC                      IOMUX_PINCM2_PF_TIMA0_CCP1
#define GPIO_PWM_R_C1_IDX                                    DL_TIMER_CC_1_INDEX

/* Defines for PWM_L */
#define PWM_L_INST                                                         TIMG8
#define PWM_L_INST_IRQHandler                                   TIMG8_IRQHandler
#define PWM_L_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
#define PWM_L_INST_CLK_FREQ                                             40000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_L_C0_PORT                                                 GPIOA
#define GPIO_PWM_L_C0_PIN                                          DL_GPIO_PIN_7
#define GPIO_PWM_L_C0_IOMUX                                      (IOMUX_PINCM14)
#define GPIO_PWM_L_C0_IOMUX_FUNC                     IOMUX_PINCM14_PF_TIMG8_CCP0
#define GPIO_PWM_L_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_L_C1_PORT                                                 GPIOA
#define GPIO_PWM_L_C1_PIN                                         DL_GPIO_PIN_22
#define GPIO_PWM_L_C1_IOMUX                                      (IOMUX_PINCM47)
#define GPIO_PWM_L_C1_IOMUX_FUNC                     IOMUX_PINCM47_PF_TIMG8_CCP1
#define GPIO_PWM_L_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                    (TIMG12)
#define TIMER_0_INST_IRQHandler                                TIMG12_IRQHandler
#define TIMER_0_INST_INT_IRQN                                  (TIMG12_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                        (399999U)




/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C1
#define I2C_0_INST_IRQHandler                                    I2C1_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C1_INT_IRQn
#define I2C_0_BUS_SPEED_HZ                                                400000
#define GPIO_I2C_0_SDA_PORT                                                GPIOB
#define GPIO_I2C_0_SDA_PIN                                         DL_GPIO_PIN_3
#define GPIO_I2C_0_IOMUX_SDA                                     (IOMUX_PINCM16)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                      IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOB
#define GPIO_I2C_0_SCL_PIN                                         DL_GPIO_PIN_2
#define GPIO_I2C_0_IOMUX_SCL                                     (IOMUX_PINCM15)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                      IOMUX_PINCM15_PF_I2C1_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           40000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_0_FBRD_40_MHZ_115200_BAUD                                      (45)





/* Port definition for Pin Group MPU6050 */
#define MPU6050_PORT                                                     (GPIOB)

/* Defines for INT_PIN: GPIOB.0 with pinCMx 12 on package pin 47 */
// groups represented: ["Encoder","MPU6050"]
// pins affected: ["L1_E1","L1_E2","L2_E1","L2_E2","R1_E1","R1_E2","R2_E1","R2_E2","INT_PIN"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define MPU6050_INT_PIN_IIDX                                 (DL_GPIO_IIDX_DIO0)
#define MPU6050_INT_PIN_PIN                                      (DL_GPIO_PIN_0)
#define MPU6050_INT_PIN_IOMUX                                    (IOMUX_PINCM12)
/* Port definition for Pin Group Buzzer */
#define Buzzer_PORT                                                      (GPIOA)

/* Defines for PIN_0: GPIOA.27 with pinCMx 60 on package pin 31 */
#define Buzzer_PIN_0_PIN                                        (DL_GPIO_PIN_27)
#define Buzzer_PIN_0_IOMUX                                       (IOMUX_PINCM60)
/* Defines for OLED_SDA: GPIOB.15 with pinCMx 32 on package pin 3 */
#define OLED_OLED_SDA_PORT                                               (GPIOB)
#define OLED_OLED_SDA_PIN                                       (DL_GPIO_PIN_15)
#define OLED_OLED_SDA_IOMUX                                      (IOMUX_PINCM32)
/* Defines for OLED_SCL: GPIOA.17 with pinCMx 39 on package pin 10 */
#define OLED_OLED_SCL_PORT                                               (GPIOA)
#define OLED_OLED_SCL_PIN                                       (DL_GPIO_PIN_17)
#define OLED_OLED_SCL_IOMUX                                      (IOMUX_PINCM39)
/* Port definition for Pin Group Trail */
#define Trail_PORT                                                       (GPIOA)

/* Defines for Trail_DAT: GPIOA.12 with pinCMx 34 on package pin 5 */
#define Trail_Trail_DAT_PIN                                     (DL_GPIO_PIN_12)
#define Trail_Trail_DAT_IOMUX                                    (IOMUX_PINCM34)
/* Defines for Trail_CLK: GPIOA.13 with pinCMx 35 on package pin 6 */
#define Trail_Trail_CLK_PIN                                     (DL_GPIO_PIN_13)
#define Trail_Trail_CLK_IOMUX                                    (IOMUX_PINCM35)
/* Port definition for Pin Group Register */
#define Register_PORT                                                    (GPIOA)

/* Defines for TCP: GPIOA.14 with pinCMx 36 on package pin 7 */
#define Register_TCP_PIN                                        (DL_GPIO_PIN_14)
#define Register_TCP_IOMUX                                       (IOMUX_PINCM36)
/* Defines for HCP: GPIOA.15 with pinCMx 37 on package pin 8 */
#define Register_HCP_PIN                                        (DL_GPIO_PIN_15)
#define Register_HCP_IOMUX                                       (IOMUX_PINCM37)
/* Defines for DS: GPIOA.25 with pinCMx 55 on package pin 26 */
#define Register_DS_PIN                                         (DL_GPIO_PIN_25)
#define Register_DS_IOMUX                                        (IOMUX_PINCM55)
/* Port definition for Pin Group Key */
#define Key_PORT                                                         (GPIOB)

/* Defines for Key1: GPIOB.12 with pinCMx 29 on package pin 64 */
#define Key_Key1_PIN                                            (DL_GPIO_PIN_12)
#define Key_Key1_IOMUX                                           (IOMUX_PINCM29)
/* Defines for Key2: GPIOB.8 with pinCMx 25 on package pin 60 */
#define Key_Key2_PIN                                             (DL_GPIO_PIN_8)
#define Key_Key2_IOMUX                                           (IOMUX_PINCM25)
/* Defines for Key3: GPIOB.9 with pinCMx 26 on package pin 61 */
#define Key_Key3_PIN                                             (DL_GPIO_PIN_9)
#define Key_Key3_IOMUX                                           (IOMUX_PINCM26)
/* Defines for Key4: GPIOB.10 with pinCMx 27 on package pin 62 */
#define Key_Key4_PIN                                            (DL_GPIO_PIN_10)
#define Key_Key4_IOMUX                                           (IOMUX_PINCM27)
/* Port definition for Pin Group Encoder */
#define Encoder_PORT                                                     (GPIOB)

/* Defines for L1_E1: GPIOB.4 with pinCMx 17 on package pin 52 */
#define Encoder_L1_E1_IIDX                                   (DL_GPIO_IIDX_DIO4)
#define Encoder_L1_E1_PIN                                        (DL_GPIO_PIN_4)
#define Encoder_L1_E1_IOMUX                                      (IOMUX_PINCM17)
/* Defines for L1_E2: GPIOB.5 with pinCMx 18 on package pin 53 */
#define Encoder_L1_E2_IIDX                                   (DL_GPIO_IIDX_DIO5)
#define Encoder_L1_E2_PIN                                        (DL_GPIO_PIN_5)
#define Encoder_L1_E2_IOMUX                                      (IOMUX_PINCM18)
/* Defines for L2_E1: GPIOB.6 with pinCMx 23 on package pin 58 */
#define Encoder_L2_E1_IIDX                                   (DL_GPIO_IIDX_DIO6)
#define Encoder_L2_E1_PIN                                        (DL_GPIO_PIN_6)
#define Encoder_L2_E1_IOMUX                                      (IOMUX_PINCM23)
/* Defines for L2_E2: GPIOB.7 with pinCMx 24 on package pin 59 */
#define Encoder_L2_E2_IIDX                                   (DL_GPIO_IIDX_DIO7)
#define Encoder_L2_E2_PIN                                        (DL_GPIO_PIN_7)
#define Encoder_L2_E2_IOMUX                                      (IOMUX_PINCM24)
/* Defines for R1_E1: GPIOB.23 with pinCMx 51 on package pin 22 */
#define Encoder_R1_E1_IIDX                                  (DL_GPIO_IIDX_DIO23)
#define Encoder_R1_E1_PIN                                       (DL_GPIO_PIN_23)
#define Encoder_R1_E1_IOMUX                                      (IOMUX_PINCM51)
/* Defines for R1_E2: GPIOB.13 with pinCMx 30 on package pin 1 */
#define Encoder_R1_E2_IIDX                                  (DL_GPIO_IIDX_DIO13)
#define Encoder_R1_E2_PIN                                       (DL_GPIO_PIN_13)
#define Encoder_R1_E2_IOMUX                                      (IOMUX_PINCM30)
/* Defines for R2_E1: GPIOB.19 with pinCMx 45 on package pin 16 */
#define Encoder_R2_E1_IIDX                                  (DL_GPIO_IIDX_DIO19)
#define Encoder_R2_E1_PIN                                       (DL_GPIO_PIN_19)
#define Encoder_R2_E1_IOMUX                                      (IOMUX_PINCM45)
/* Defines for R2_E2: GPIOB.18 with pinCMx 44 on package pin 15 */
#define Encoder_R2_E2_IIDX                                  (DL_GPIO_IIDX_DIO18)
#define Encoder_R2_E2_PIN                                       (DL_GPIO_PIN_18)
#define Encoder_R2_E2_IOMUX                                      (IOMUX_PINCM44)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_R_init(void);
void SYSCFG_DL_PWM_L_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_0_init(void);
void SYSCFG_DL_UART_0_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
