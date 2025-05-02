#ifndef _HARDWARE_PROFILE_H_
#define _HARDWARE_PROFILE_H_

#include <xc.h>

#define GetSystemClock()        (10000000ul)
#define GetInstructionClock()   (GetSystemClock()/4)
#define GetPeripheralClock()    GetInstructionClock()

#define I2C_FREQ                100000                  // i2c bus frequency
#define UART_FREQ               115200                  // uart frequency

#define LED                     LATA0

// LCD 2x16
#define LCD_8_BITS              1
#define LCD_RS_PIN              LATB5                   // pin RS (Register Select)
#define LCD_RS_TRIS             TRISB5
#define LCD_E_PIN               LATB4                   // pin Enable
#define LCD_E_TRIS              TRISB4
#define LCD_D0_PIN              LATB0
#define LCD_D0_TRIS             TRISB0
#define LCD_D1_PIN              LATB1
#define LCD_D1_TRIS             TRISB1
#define LCD_D2_PIN              LATC2
#define LCD_D2_TRIS             TRISC2
#define LCD_D3_PIN              LATC3
#define LCD_D3_TRIS             TRISC3
#define LCD_D4_PIN              LATC4
#define LCD_D4_TRIS             TRISC4
#define LCD_D5_PIN              LATC5
#define LCD_D5_TRIS             TRISC5
#define LCD_D6_PIN              LATB2
#define LCD_D6_TRIS             TRISB2
#define LCD_D7_PIN              LATB3
#define LCD_D7_TRIS             TRISB3

#endif
