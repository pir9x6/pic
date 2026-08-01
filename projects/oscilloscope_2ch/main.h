#include "p33Fxxxx.h"
#include "uart.h"
#include "cy7c42x1.h"
#include "delays.h"
#include "i2c.h"
#include "io.h"
#include "Math.h"
#include "max7311.h"
#include "types.h"
#include "waves.h"

#ifndef _MAIN_H_
#define _MAIN_H_


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------- Constants -----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define GetSystemClock()        (80000000ul)
#define GetInstructionClock()   (GetSystemClock()/2)
#define GetPeripheralClock()    GetInstructionClock()

#define BOARD_DSO_2CH

#define I2C_FREQ      100000        // i2c bus frequency
#define UART_FREQ     115200        // uart frequency
#define I2C_1
#define I2C_SLAVE_ADDR  0x54

#define IDLE        0
#define ACQUI       1
#define TRANSMIT    2

#define FIFO_SIZE   (128*2^10)



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------- Entrées/Sorties --------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define LED1                LATAbits.LATA0
#define LED2                LATAbits.LATA1
#define PIN_FIFO_RSTn       LATAbits.LATA3
#define PIN_FIFO_WR_ENn     LATAbits.LATA4
#define PIN_FIFO_RD_CLK     LATBbits.LATB13

#define U1RX_TRIS           TRISBbits.TRISB14
#define U1TX_TRIS           TRISBbits.TRISB15

//#define FIFO_DATA           (u8)((LATBbits.LATB12<<7) | (0x7F & ((u8)LATB)>>1))
//#define FIFO_DATA           (u8)((LATBbits.LATB12<<7) + (LATBbits.LATB7<<6) + (LATBbits.LATB6<<5) + (LATBbits.LATB5<<4))
//#define FIFO_DATA           (u8)PORTB
#define FIFO_DATA           (((PORTB>>12)&0x01)<<7)|(u8)(PORTB&0x7F)



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Prototypes -----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void uart_isr();



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
