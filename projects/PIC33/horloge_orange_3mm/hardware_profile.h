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

#define I2C_FREQ                100000        // i2c bus frequency
#define UART_FREQ               115200        // uart frequency
#define I2C_SLAVE_ADDR          0x54

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------------------- GPIO ------------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define LED                 LATAbits.LATA0
#define DIR_LED             TRISAbits.TRISA0

#define LED2                LATAbits.LATA4
#define DIR_LED2            TRISAbits.TRISA4

#define PIN_PWM             LATBbits.LATB15
#define DIR_PWM             TRISBbits.TRISB15

#define U1RX_TRIS           TRISBbits.TRISB0
#define U1TX_TRIS           TRISBbits.TRISB14


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Remapable Pins -------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define UART1_RX_RP         0
#define UART1_TX_RP         _RP14R

#define PWM1_RP             _RP15R


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------------- Pinout -----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/*
                                 _______________
                           Mclr | 01         18 | Vdd
                      LED - RA0 | 02         17 | Vss
                            RA1 | 03         16 | RB15 - PWM
                      PGD - RB0 | 04         15 | RB14 - UART TX (debug)
                      PGC - RB1 | 05         14 | Vcore
                     OSCI - RA2 | 06         13 | VSS
                     OSCO - RA3 | 07         12 | RB9 - SDA
                            RB4 | 08         11 | RB8 - SCL
                LED2(debug) RA4 | 09         10 | RB7
                                 _______________

*/


#endif