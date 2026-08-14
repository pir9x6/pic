#include "p18CXXX.h"
#include "types.h"
#include "misc.h"
#include "i2c.h"
#include "pcf8574.h"

#ifndef _MAIN_H_
#define _MAIN_H_



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------------- prototypes --------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void InterruptTimer2 ();        // interruption sur le Timer 2
void pcf7485_sec_raz ();


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------- Constants -----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define GetSystemClock()        (10000000ul)
#define GetInstructionClock()   (GetSystemClock()/4)
#define GetPeripheralClock()    GetInstructionClock()
#define I2C_FREQ      100000        // i2c bus frequency
#define UART_FREQ     115200        // uart frequency
#define I2C_1                       // use i2s bus n°1

#endif
