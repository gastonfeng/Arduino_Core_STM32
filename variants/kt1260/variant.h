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

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
extern const int build;
extern int uptime;
extern int atemp_init,atemp,avref;   //芯片温度,基准电压


#define HAL_HCD_MODULE_ENABLED 1
  /*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#define PA0 0 // A0
#define PA1 1 // A1
#define PA2 2
#define PA3 3
#define PA4 4 // A2
#define PA5 5 // A8 - LED
#define PA6 6 // A7
#define PA7 7 // A6
#define PA8 8
#define PA9 9
#define PA10 10
#define PA11 11
#define PA12 12
#define PA13 13 // SWD
#define PA14 14 // SWD
#define PA15 15

#define PB0 16 // A3
#define PB1 17 // A11
#define PB2 18
#define PB3 19
#define PB4 20
#define PB5 21
#define PB6 22
#define PB7 23
#define PB8 24
#define PB9 25
#define PB10 26
#define PB11 27
#define PB12 28
#define PB13 29
#define PB14 30
#define PB15 31

#define PC0 32 // A5
#define PC1 33 // A4
#define PC2 34 // A9
#define PC3 35 // A10
#define PC4 36 // A12
#define PC5 37 // A13
#define PC6 38
#define PC7 39
#define PC8 40
#define PC9 41
#define PC10 42
#define PC11 43
#define PC12 44
#define PC13 45
#define PC14 46
#define PC15 47

#define PD0 48
#define PD1 49
#define PD2 50
#define PD3 51
#define PD4 52
#define PD5 53
#define PD6 54
#define PD7 55
#define PD8 56
#define PD9 57
#define PD10 58
#define PD11 59
#define PD12 60
#define PD13 61
#define PD14 62
#define PD15 63

#define PE0 64
#define PE1 65
#define PE2 66
#define PE3 67
#define PE4 68
#define PE5 69
#define PE6 70
#define PE11 71
#define PE12 72
#define PE13 73
#define PE14 74
#define PE15 75

#define NUM_DIGITAL_PINS 76
// This must be a literal with a value less than or equal to to MAX_ANALOG_INPUTS
#define NUM_ANALOG_INPUTS 14
#define NUM_ANALOG_FIRST 46

// On-board LED pin number
#define LED_BUILTIN 13
#define LED_GREEN LED_BUILTIN

// On-board user button
#define USER_BTN PC13

// Timer Definitions
// Do not use timer used by PWM pins when possible. See PinMap_PWM.
#define TIMER_TONE TIM4

// Do not use basic timer: OC is required
#define TIMER_SERVO TIM2 //TODO: advanced-control timers don't work

// UART Definitions
#define SERIAL_UART_INSTANCE 3 //Connected to ST-Link
// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#define PIN_SERIAL_RX PA10
#define PIN_SERIAL_TX PA9

#define BOARD_USART3_TX_PIN PC10
#define BOARD_USART3_RX_PIN PC11

#define X1 PD4
#define X2 PD7
#define X3 PB6
#define X4 PB7
#define X5 PE0
#define X6 PE1
#define X7 PE2
#define X8 PE3
#define X9 PE4
#define X10 PE5
#define X11 PE6
#define X12 PC13
#define X13 PC14
#define X14 PC15
#define X15 PC0
#define X16 PC2

#define XA4 PA3
#define XA7 PA4

extern char xx1, xx2, xx3, xx4, xx5, xx6, xx7, xx8, xx9, xx10, xx11, xx12, xx13, xx14, xx15, xx16, yy1, yy2, yy3, yy4, yy5, yy6, yy7, yy8, yy9, yy10, yy11, yy12, yy13, yy14, yy15, yy16, yy17, yy18, yy19, yy20, yy21, yy22, yy23, yy24;
extern short xa1, xa2, xa3, xa4, xa5, xa6, xa7, xa8, xa9, xa10, ya1, ya2;
extern int xt1, xt2, xt3, xt4;

#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR Serial
#define SERIAL_PORT_HARDWARE Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
