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




/* Port definition for Pin Group GPIO_LED1 */
#define GPIO_LED1_PORT                                                   (GPIOA)

/* Defines for PIN_LED1: GPIOA.0 with pinCMx 1 on package pin 33 */
#define GPIO_LED1_PIN_LED1_PIN                                   (DL_GPIO_PIN_0)
#define GPIO_LED1_PIN_LED1_IOMUX                                  (IOMUX_PINCM1)
/* Port definition for Pin Group GPIO_Key1 */
#define GPIO_Key1_PORT                                                   (GPIOB)

/* Defines for PIN_Key1: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_Key1_PIN_Key1_PIN                                  (DL_GPIO_PIN_21)
#define GPIO_Key1_PIN_Key1_IOMUX                                 (IOMUX_PINCM49)
/* Defines for PIN_SCL: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_OLED_PIN_SCL_PORT                                           (GPIOB)
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_15)
#define GPIO_OLED_PIN_SCL_IOMUX                                  (IOMUX_PINCM32)
/* Defines for PIN_SDA: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_OLED_PIN_SDA_PORT                                           (GPIOA)
#define GPIO_OLED_PIN_SDA_PIN                                   (DL_GPIO_PIN_17)
#define GPIO_OLED_PIN_SDA_IOMUX                                  (IOMUX_PINCM39)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);



#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
