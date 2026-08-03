#ifndef _HARDWARE_PROFILE_H_
#define _HARDWARE_PROFILE_H_

#include "pic_compiler.h"
#include <p33Fxxxx.h>

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------- Constants -----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define GetSystemClock()        (80000000ul)
#define GetInstructionClock()   (GetSystemClock()/2)
#define GetPeripheralClock()    GetInstructionClock()
#define FCY                     GetInstructionClock()

//#define UART_VERBOSE
//#define USE_LCD

#define I2C_FREQ        100000        // i2c bus frequency
#define UART_FREQ       115200        // uart frequency
#define I2C_SLAVE_ADDR  0x54


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------- Functionnalities --------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define USE_CLI
#define USE_DS1621
#define USE_DS1337


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------- Entrées/Sorties --------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define LED1                LATBbits.LATB0
#define LED2                LATBbits.LATB5
#define LED3                LATBbits.LATB2

#define IR                  PORTBbits.RB7

#define U1RX_TRIS           TRISBbits.TRISB14
#define U1TX_TRIS           TRISBbits.TRISB15


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Remapable Pins -------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define UART1_RX_RP         14
#define UART1_TX_RP         _RP15R

#define PWM1_RP             _RP15R


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------------- Pinout ------------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/*
                                 _______________
                           Mclr | 01         40 | Vdd
                     LED1 - RA0 | 02         39 | Vss
                     LED2 - RA1 | 03         38 | RB15 - TX
                       D0 - RB0 | 04         37 | RB14 - RX
                       D1 - RB1 | 05         36 | RB13 - RD_CLK
                       D2 - RB2 | 06         35 | RB12 - D8
                       D3 - RB3 | 07         34 | RB11 - PGC
                            Vss | 08         33 | RB10 - PGD
                           Osci | 09         32 | Vdd
                     Rst - Osco | 10         31 | Vss
                       D4 - RB4 | 11         30 | RB9 - SDA
                    Wr_En - RA4 | 12         29 | RB8 - SCL
                            Vdd | 13         28 | RB7 - D7
                       D5 - RB5 | 14         27 | RB6 - D6
                                 _______________

*/


#endif
