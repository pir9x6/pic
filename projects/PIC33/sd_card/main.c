//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&       Title       :   SD Card Access test                             &&&
//&&&       File        :   main.c                                          &&&
//&&&       Description :   Main function                                   &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&       Autor       :   Pierre BLACHÉ                                   &&&
//&&&       Date        :   12/12/2016                                      &&&
//&&&       Version     :   1.0                                             &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "misc.h"
#include "oscillator.h"
#include "types.h"

#include "delays.h"
#include "i2c.h"
#include "io.h"
#include "mmc_sd.h"
#include "spi.h"
#include "uart.h"

#include "hardware_profile.h"
#include "interrupts_management.h"

#include <xc.h>

#pragma config FNOSC = PRI              // Primary (XT, HS, EC) Oscillator
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON  & POSCMD_HS)
#pragma config FWDTEN = OFF             // watchdog is off
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config ALTI2C = OFF             // pin SDA & SCL
    
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
    //------------------------ MCU Configuration ------------------------------
    oscillator_init (OSC_80MHZ);

    //------------------------ IO configuration -------------------------------
    TRISA = 0;
    TRISB = 0;
    _TRISB14 = IO_IN;           // Uart RX
    _TRISB7 = IO_IN;            // SPI Din
    
    // remapable pins
    _U1RXR = UART1_RX_RP;       // pin RB15 as UART input
    UART1_TX_RP = RPO_U1TX;
    
    _SDI1R = SPI1_DIN_RP;       // data in
    SPI1_DOUT_RP = RPO_SDO1;    // data out
    SPI1_CLK_RP = RPO_SCK1OUT;  // clock out
    
    AD1PCFGL = 0xFFFF;          // PORTA & PORTB as digital I/O

    //--------------------------- Periph init ---------------------------------
    // init UART @ 115200
    delay_ms(100);
    uart_init(UART_ID_1, UART_FREQ, UART_EN_IT_RX);
    uart_write_string(UART_ID_1, "\n====== Hello ======\n");

    // init SPI #1
    spi_init(SPI_ID_1);

    // init sd card
    sd_initialize();

    /* Read in the first block on the SD Card */
//    if (ok == SUCCESS)
//    {
//        sd_read_block (&sdc, 0, sd_buffer);
//        sd_wait_notbusy (&sdc);
//    }
    
    //---------------------------- Main Loop ----------------------------------
    while (1)
    {
        //====================
        LED1 = 1;
        LED2 = 0;
        delay_ms (150);

        //====================
        LED1 = 0;
        LED2 = 1;
        delay_ms (150);
    }

    return 0;
}
