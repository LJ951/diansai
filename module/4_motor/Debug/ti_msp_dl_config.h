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



/* Defines for PWM_L */
#define PWM_L_INST                                                         TIMA0
#define PWM_L_INST_IRQHandler                                   TIMA0_IRQHandler
#define PWM_L_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define PWM_L_INST_CLK_FREQ                                             10000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_L_C0_PORT                                                 GPIOA
#define GPIO_PWM_L_C0_PIN                                          DL_GPIO_PIN_0
#define GPIO_PWM_L_C0_IOMUX                                       (IOMUX_PINCM1)
#define GPIO_PWM_L_C0_IOMUX_FUNC                      IOMUX_PINCM1_PF_TIMA0_CCP0
#define GPIO_PWM_L_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_L_C1_PORT                                                 GPIOA
#define GPIO_PWM_L_C1_PIN                                          DL_GPIO_PIN_1
#define GPIO_PWM_L_C1_IOMUX                                       (IOMUX_PINCM2)
#define GPIO_PWM_L_C1_IOMUX_FUNC                      IOMUX_PINCM2_PF_TIMA0_CCP1
#define GPIO_PWM_L_C1_IDX                                    DL_TIMER_CC_1_INDEX

/* Defines for PWM_R */
#define PWM_R_INST                                                         TIMG8
#define PWM_R_INST_IRQHandler                                   TIMG8_IRQHandler
#define PWM_R_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
#define PWM_R_INST_CLK_FREQ                                             10000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_R_C0_PORT                                                 GPIOA
#define GPIO_PWM_R_C0_PIN                                          DL_GPIO_PIN_7
#define GPIO_PWM_R_C0_IOMUX                                      (IOMUX_PINCM14)
#define GPIO_PWM_R_C0_IOMUX_FUNC                     IOMUX_PINCM14_PF_TIMG8_CCP0
#define GPIO_PWM_R_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_R_C1_PORT                                                 GPIOA
#define GPIO_PWM_R_C1_PIN                                         DL_GPIO_PIN_22
#define GPIO_PWM_R_C1_IOMUX                                      (IOMUX_PINCM47)
#define GPIO_PWM_R_C1_IOMUX_FUNC                     IOMUX_PINCM47_PF_TIMG8_CCP1
#define GPIO_PWM_R_C1_IDX                                    DL_TIMER_CC_1_INDEX




/* Port definition for Pin Group GPIO_Key1 */
#define GPIO_Key1_PORT                                                   (GPIOB)

/* Defines for PIN_Key1: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_Key1_PIN_Key1_PIN                                  (DL_GPIO_PIN_21)
#define GPIO_Key1_PIN_Key1_IOMUX                                 (IOMUX_PINCM49)
/* Defines for PIN_SCL: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_OLED_PIN_SCL_PORT                                           (GPIOA)
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_17)
#define GPIO_OLED_PIN_SCL_IOMUX                                  (IOMUX_PINCM39)
/* Defines for PIN_SDA: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_OLED_PIN_SDA_PORT                                           (GPIOB)
#define GPIO_OLED_PIN_SDA_PIN                                   (DL_GPIO_PIN_15)
#define GPIO_OLED_PIN_SDA_IOMUX                                  (IOMUX_PINCM32)
/* Port definition for Pin Group GPIO_595 */
#define GPIO_595_PORT                                                    (GPIOA)

/* Defines for PIN_595STCP: GPIOA.14 with pinCMx 36 on package pin 7 */
#define GPIO_595_PIN_595STCP_PIN                                (DL_GPIO_PIN_14)
#define GPIO_595_PIN_595STCP_IOMUX                               (IOMUX_PINCM36)
/* Defines for PIN_595SHCP: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_595_PIN_595SHCP_PIN                                (DL_GPIO_PIN_15)
#define GPIO_595_PIN_595SHCP_IOMUX                               (IOMUX_PINCM37)
/* Defines for PIN_595DS: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_595_PIN_595DS_PIN                                  (DL_GPIO_PIN_25)
#define GPIO_595_PIN_595DS_IOMUX                                 (IOMUX_PINCM55)
/* Port definition for Pin Group GPIO_Encoder */
#define GPIO_Encoder_PORT                                                (GPIOB)

/* Defines for R2_E1: GPIOB.19 with pinCMx 45 on package pin 16 */
// pins affected by this interrupt request:["R2_E1","R2_E2"]
#define GPIO_Encoder_INT_IRQN                                   (GPIOB_INT_IRQn)
#define GPIO_Encoder_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_R2_E1_IIDX                             (DL_GPIO_IIDX_DIO19)
#define GPIO_Encoder_R2_E1_PIN                                  (DL_GPIO_PIN_19)
#define GPIO_Encoder_R2_E1_IOMUX                                 (IOMUX_PINCM45)
/* Defines for R2_E2: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_Encoder_R2_E2_IIDX                             (DL_GPIO_IIDX_DIO18)
#define GPIO_Encoder_R2_E2_PIN                                  (DL_GPIO_PIN_18)
#define GPIO_Encoder_R2_E2_IOMUX                                 (IOMUX_PINCM44)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_L_init(void);
void SYSCFG_DL_PWM_R_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
