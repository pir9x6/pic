#ifndef _MAIN_H_
#define _MAIN_H_

#include "pic_compiler.h"

#if defined(__dsPIC33FJ256MC710__) || defined(__PIC24FJ256GB210__)
    #include "Defines_EB_QFP100.h"
    #include "ds1621.h"
    #include "ds1337.h"
    #include "i2c.h"
    #include "lcd.h"
    #include "uart.h"
    #include "lcd.h"
#elif defined (__PIC24FJ64GB002__)
    #include "Defines_EB_ENC28J60.h"
#endif

#include "delays.h"
#include "GenericTypeDefs.h"
#include "types.h"
#include "oscillator.h"
#include "adc.h"
#include "io.h"

//processor speed
#define GetSystemClock()        32000000ul
#define GetInstructionClock()   (GetSystemClock()/2)
#define GetPeripheralClock()    GetInstructionClock()

//#define EB_QFP100
#define UART_FREQ       115200      // debit RS232
#define LCD_4bits       1           // LCD en mode 4 bits
#define I2C_FREQ        100000      // frequence du bus I2C
#define UART_VERBOSE
#define USE_LCD
#define USE_UART
#define I2C_SLAVE_ADDR  0x54

// SPI SCK, SDI, SDO pins are automatically controlled by the PIC24/dsPIC/PIC32 SPI module
#define ENC_SPI_IF          (IFS0bits.SPI1IF)
#define ENC_SSPBUF          (SPI1BUF)
#define ENC_SPISTAT         (SPI1STAT)
#define ENC_SPISTATbits     (SPI1STATbits)
#define ENC_SPICON1         (SPI1CON1)
#define ENC_SPICON1bits     (SPI1CON1bits)
#define ENC_SPICON2         (SPI1CON2)


int readADC1(int ch); // Le um canal do adc
int readPot(void);      // Le o sensor do pot
int readTemp(void);     // Le o sensor de Temperatura
void uart_isr ();
void tcpip_init();
void io_config();
void lcd_display_ip(DWORD_VAL ip);

#define ENC28J60_BUTTON0    0
#define ENC28J60_BUTTON1    0
#define ENC28J60_BUTTON2    0
#define ENC28J60_BUTTON3    0
#define ENC28J60_LED0       0
#define ENC28J60_LED1       0
#define ENC28J60_LED2       0
#define ENC28J60_LED3       0
#define ENC28J60_LED4       0
#define ENC28J60_LED5       0
#define ENC28J60_LED6       0
#define ENC28J60_LED7       0

#endif
