/*
 *******************************************************************************
 * Copyright (c) 2018, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */
#include "pins_arduino.h"

#ifdef __cplusplus
extern "C"
{
#endif

  // Pin number
  const PinName digitalPin[] = {
      PA_0,  //D46/A0
      PA_1,  //D47/A1
      PA_2,  //D1
      PA_3,  //D0
      PA_4,  //D48/A2
      PA_5,  //D13 - LED
      PA_6,  //D12
      PA_7,  //D11
      PA_8,  //D7
      PA_9,  //D8
      PA_10, //D2
      PA_11, //D37
      PA_12, //D36
      PA_13, //D19 - SWD
      PA_14, //D20 - SWD
      PA_15, //D21
      PB_0,  //D49/A3
      PB_1,  //D41
      PB_2,  //D40
      PB_3,  //D3
      PB_4,  //D5
      PB_5,  //D4
      PB_6,  //D10
      PB_7,  //D22
      PB_8,  //D15
      PB_9,  //D14
      PB_10, //D6
      PB_11, //D39
      PB_12, //D38
      PB_13, //D44
      PB_14, //D43
      PB_15, //D42
      PC_0,  //D51/A5
      PC_1,  //D50/A4
      PC_2,  //D28
      PC_3,  //D29
      PC_4,  //D45
      PC_5,  //D35
      PC_6,  //D34
      PC_7,  //D9
      PC_8,  //D33
      PC_9,  //D32
      PC_10, //D16
      PC_11, //D30
      PC_12, //D17
      PC_13, //D23
      PC_14, //D24
      PC_15, //D25
      PD_0,  //D26
      PD_1,  //D27
      PD_2,  //D31
      PD_3,  //D26
      PD_4,  //D27
      PD_5,  //D31
      PD_6,  //D26
      PD_7,  //D27
      PD_8,  //D31
      PD_9,  //D26
      PD_10, //D27
      PD_11, //D31
      PD_12, //D26
      PD_13, //D27
      PD_14, //D31
      PD_15,
      // Duplicated pins in order to be aligned with PinMap_ADC
      PE_0,
      PE_1,
      PE_2,
      PE_3,
      PE_4,
      PE_5,
      PE_6,
      PE_11,
      PE_12,
      PE_13,
      PE_14,
      PE_15};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

  /**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            PLL_Source                     = HSE
  *            PLL_Mul                        = 9
  *            Flash Latency(WS)              = 2
  *            ADC Prescaler                  = 6
  *            USB Prescaler                  = 1.5
  * @param  None
  * @retval None
  */
  WEAK void SystemClock_Config(void)
  {
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /* Initializes the CPU, AHB and APB busses clocks */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      while (1)
        ;
    }

    /* Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
      while (1)
        ;
    }

    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_USB;
    PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
    PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      while (1)
        ;
    }
  }

#ifdef __cplusplus
}
#endif
