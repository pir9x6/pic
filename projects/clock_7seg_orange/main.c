//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Description:    Orange 3mm LED Clock                                &&&
//&&&   MCU:            DSPIC33FJ12GP201                                    &&&
//&&&   MPLAB:          v6.20                                               &&&
//&&&   XC-DSC:         v4.00                                               &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Versions    :                                                       &&&
//&&&   v1.0    01/08/2014    Creation                                      &&&
//&&&   v2.0    01/01/2017    Changed IDE to MPLAB X                        &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&



/*****************************************************************************
* Configuration bits
******************************************************************************/
// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = PRI              // Oscillator Mode (Primary Oscillator (XT, HS, EC))
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = HS              // Primary Oscillator Source (HS Oscillator Mode)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function (OSC2 pin has digital I/O function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSECMD           // Clock Switching and Monitor (Clock switching is enabled, Fail-Safe Clock Monitor is disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)



/*****************************************************************************
* Includes
******************************************************************************/
#include <xc.h>
#include <libpic30.h>

#include "hardware_profile.h"
#include "interrupts_management.h"

#include "bcd.h"
#include "date_time.h"
#include "delays.h"
#include "oscillator.h"
#include "i2c.h"
#include "pwm.h"
#include "timer.h"
#include "uart.h"

#include "pcf8574.h"

#include "misc.h"
#include "types.h"


/*****************************************************************************
* I2C addresses
******************************************************************************/
#define I2C_ADR_PCF8574A        0x38


/*****************************************************************************
* Main program
******************************************************************************/
int main (void)
{
    //-------------------------- Local Variables -----------------------------
//    u8 temperature[2] = {0, 0};
    u8 pcf_tab[12] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00, 0xFF};
    u8 bcd[5] = {0, 0, 0, 0, 0};
    __C30_UART = 1;
    date_time_t t = {
        .hrs = 18,
        .min = 16,
        .sec =  0,
        .dow =  6,
        .day = 26,
        .mth = 07,
        .yrs = 26
    };
    UART_CFG_t uart_1_cfg = {
        .uart_id = UART_ID_1,
        .baudrate = UART_FREQ
    };
    I2C_CFG_t i2c_1_cfg = {
        .bus_id = I2C_BUS_1,
        .freq = I2C_FREQ,
        .slave_or_master = I2C_MASTER,
        .en_master_it = 0,
        .en_slave_it = 0,
        .slave_addr = 0x00
    };
    TIMER_CFG_t timer_1_cfg = {
        .timer_id = TIMER_ID_1,
        .timer_prescaler = TMR_PRESCALER_256,
        .timer_postscaler = TMR_POSTSCALER_NONE,
        .period = 10000
    };
    
    //------------------- Configuration du MCU (21µs)--------------------------
    oscillator_init (OSC_80MHZ);

    //------------------------ IO configuration -------------------------------
    TRISA = 0;
    TRISB = 0;
    AD1PCFGL = 0xFFFF;                  // PORTB en  digital I/O
    DIR_PWM = IO_OUT;
    DIR_LED = IO_OUT;
    DIR_LED2 = IO_OUT;

    //--------------------------- Periph init ---------------------------------
    delay_ms(100);
    uart_init(&uart_1_cfg);
    i2c_init(&i2c_1_cfg);
    timer1_init(timer_1_cfg);
    pwm_init(PWM_ID_1, 2000, 100);

    //-------------------------- Init I2C Chips -------------------------------
    PIN_PWM = 1;
    LED = 1;

    //---------------------------- Main Loop ----------------------------------
    while (1)
    {
        LED = !LED;

        dec_2_bcd(t.hrs, bcd);
        pcf8574_write_port(I2C_BUS_1, I2C_ADR_PCF8574A + 0, pcf_tab[bcd[1]]);
        pcf8574_write_port(I2C_BUS_1, I2C_ADR_PCF8574A + 1, pcf_tab[bcd[0]]);

        dec_2_bcd(t.min, bcd);
        pcf8574_write_port(I2C_BUS_1, I2C_ADR_PCF8574A + 2, pcf_tab[bcd[1]]);
        pcf8574_write_port(I2C_BUS_1, I2C_ADR_PCF8574A + 3, pcf_tab[bcd[0]]);

        dec_2_bcd(t.sec, bcd);
        pcf8574_write_port(I2C_BUS_1, I2C_ADR_PCF8574A + 4, pcf_tab[bcd[1]]);
        pcf8574_write_port(I2C_BUS_1, I2C_ADR_PCF8574A + 5, pcf_tab[bcd[0]]);

        pwm_set_duty(PWM_ID_1, 200);

        delay_ms (500);

        if (t.sec >= 59){
            t.sec = 0;
            if (t.min >= 59){
                t.min = 0;
                if (t.hrs >= 23){
                    t.hrs = 0;
                }else{
                    t.hrs++;
                }
            }else{
                t.min++;
            }
        }else{
            t.sec++;
        }
    }

    return 0;
}
