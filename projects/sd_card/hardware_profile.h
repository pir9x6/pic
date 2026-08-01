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

#define I2C_FREQ                100000        // i2c bus frequency
#define UART_FREQ               115200        // uart frequency
#define I2C_SLAVE_ADDR          0x54


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
#define LED2                LATBbits.LATB4

#define SPI_CS              LATBbits.LATB1


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Remapable Pins -------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define UART1_RX_RP         14
#define UART1_TX_RP         _RP15R

#define SPI1_DIN_RP         7
#define SPI1_DOUT_RP        _RP6R
#define SPI1_CLK_RP         _RP5R


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------------- Pinout ------------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/*
                                 ___________________
                                | 01/Mclr    Vdd/40 |
                             WP | 02/RA0     Vss/39 |
                             CD | 03/RA1    RB15/38 | TX
                           LED1 | 04/RB0    RB14/37 | RX
                         SPI CS | 05/RB1    RB13/36 |
                                | 06/RB2    RB12/35 |
                                | 07/RB3     PGC/34 |
                                | 08/Vss     PGD/33 |
                                | 09/Osci    Vdd/32 |
                                | 10/Osco    Vss/31 |
                           LED2 | 11/RB      RB9/30 | SDA
                                | 12/RA4     RB8/29 | SCL
                                | 13/Vdd     RB7/28 | SPI Din
                        SPI Clk | 14/RB5     RB6/27 | SPI Dout
                                 ___________________

*/


#endif
