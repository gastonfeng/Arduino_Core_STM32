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

  /*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#define PA0 46 // A0
#define PA1 47 // A1
#define PA2 1
#define PA3 0
#define PA4 48 // A2
#define PA5 13 // A8 - LED
#define PA6 12 // A7
#define PA7 11 // A6
#define PA8 7
#define PA9 8
#define PA10 2
#define PA11 37
#define PA12 36
#define PA13 19 // SWD
#define PA14 20 // SWD
#define PA15 21

#define PB0 49 // A3
#define PB1 41 // A11
#define PB2 40
#define PB3 3
#define PB4 5
#define PB5 4
#define PB6 10
#define PB7 22
#define PB8 15
#define PB9 14
#define PB10 6
#define PB11 39
#define PB12 38
#define PB13 44
#define PB14 43
#define PB15 42

#define PC0 51 // A5
#define PC1 50 // A4
#define PC2 28 // A9
#define PC3 29 // A10
#define PC4 45 // A12
#define PC5 35 // A13
#define PC6 34
#define PC7 9
#define PC8 33
#define PC9 32
#define PC10 16
#define PC11 30
#define PC12 17
#define PC13 23
#define PC14 24
#define PC15 25

#define PD0 26
#define PD1 27
#define PD2 31
#define PD3 52
#define PD4 52
#define PD5 52
#define PD6 26
#define PD7 27
#define PD8 31
#define PD9 52
#define PD10 52
#define PD11 52
#define PD12 26
#define PD13 27
#define PD14 31
#define PD15 52

#define PE0 52
#define PE1 52
#define PE2 52
#define PE3 52
#define PE4 52
#define PE5 52
#define PE6 52
#define PE11 52
#define PE12 53
#define PE13 54
#define PE14 55
#define PE15 56

#define NUM_DIGITAL_PINS 60
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
