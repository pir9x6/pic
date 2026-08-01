#if defined (__18CXX)
    #include "p18cxxx.h"
#elif defined(__PIC24F__)
    #include "p24Fxxxx.h"
#elif defined(__PIC24H__)
    #include "p24Hxxxx.h"
#elif defined(__PIC24E__)
    #include "p24Exxxx.h"
#elif defined(__dsPIC33F__)
    #include "p33Fxxxx.h"
#elif defined(__dsPIC33E__)
    #include "p33Exxxx.h"
#elif defined(__dsPIC30F__)
    #include "p30fxxxx.h"
#else
    #error -- processor ID not specified in generic header file
#endif

#include "Defines_EB_QFP64.h"
#include "ads7843.h"
#include "delays.h"
#include "ext_int.h"
#include "i2c.h"
#include "glcd_320x240.h"
#include "misc.h"
#include "oscillator.h"
#include "uart.h"

//processor speed
#define SYS_CLK                 80000000ul
#define GetSystemClock()        80000000ul
#define GetInstructionClock()   (GetSystemClock()/2)
#define GetPeripheralClock()    GetInstructionClock()

#define EB_QFP64        1
#define UART_FREQ       115200
#define LCD_4bits       0
#define I2C_1           1
#define I2C_FREQ        100000
#define UART_VERBOSE    0
#define USE_LCD         0
#define USE_UART        1

void timer1_isr();
void timer2_isr();
void timer3_isr();
void timer4_isr();
void timer5_isr();

void uart_isr ();

void ext_int0_isr();
void ext_int1_isr();
void ext_int2_isr();
void ext_int3_isr();
void ext_int4_isr();
