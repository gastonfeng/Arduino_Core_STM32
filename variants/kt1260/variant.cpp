/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C"
{
#endif
#ifdef BUILD_NUMBER
  const int build = BUILD_NUMBER;
#else
const int build = 0;
#endif
  int uptime;
  int atemp_init, atemp, avref; //芯片温度,基准电压
  char xx1, xx2, xx3, xx4, xx5, xx6, xx7, xx8, xx9, xx10, xx11, xx12, xx13, xx14, xx15, xx16, yy1, yy2, yy3, yy4, yy5, yy6, yy7, yy8, yy9, yy10, yy11, yy12, yy13, yy14, yy15, yy16, yy17, yy18, yy19, yy20, yy21, yy22, yy23, yy24;
  short xa1, xa2, xa3, xa4, xa5, xa6, xa7, xa8, xa9, xa10, ya1, ya2;
  int xt1, xt2, xt3, xt4;
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
  *            System Clock source            = PLL (HSI)
  *            SYSCLK(Hz)                     = 64000000
  *            HCLK(Hz)                       = 64000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            PLL_Source                     = HSI
  *            PLL_Mul                        = 16
  *            Flash Latency(WS)              = 2
  *            ADC Prescaler                  = 6
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
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV5;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_PLL2;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL2_ON;
    RCC_OscInitStruct.PLL2.PLL2MUL = RCC_PLL2_MUL8;
    RCC_OscInitStruct.PLL2.HSEPrediv2Value = RCC_HSE_PREDIV2_DIV5;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
      Error_Handler();
    }

    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
    PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }
    HAL_RCC_MCOConfig(RCC_MCO, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);
    __HAL_RCC_PLLI2S_ENABLE();
  }

#ifdef __cplusplus
}
#endif
