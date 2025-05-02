//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Author      :   Pierre BLACHÉ                                       &&&
//&&&   Version     :   v2.0                                                &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Description :   - Orange 3mm LED Clock                              &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Dependencies:   - timers                                            &&&
//&&&                   - pcf8574                                           &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Versions    :                                                       &&&
//&&&   v1.0    01/08/2014    Creation                                      &&&
//&&&   v2.0    01/01/2017    Changed IDE to MPLAB X                        &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------- Configuration Bits ------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
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



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------------------- Includes -----------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#include <xc.h>
#include <libpic30.h>

#include "hardware_profile.h"
#include "interrupts_management.h"

#include "delays.h"
#include "oscillator.h"
#include "i2c.h"
#include "pwm.h"
#include "timer.h"
#include "uart.h"

#include "pcf8574.h"

#include "misc.h"
#include "types.h"
 


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
    //-------------------------- Local Variables -----------------------------
//    u8 temperature[2] = {0, 0};
    u8 pcf_tab[12] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00, 0xFF};
    t_time t;
    u8 bcd[5] = {0, 0, 0, 0, 0};
    __C30_UART = 1;
    t.day = 31;
    t.dow = 2;
    t.hrs = 23;
    t.min = 52;
    t.mth = 12;
    t.sec = 0;
    t.yrs = 14;

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
    uart_init(UART_ID_1, UART_FREQ, UART_EN_IT_RX);
    i2c_init(I2C_BUS_1, I2C_FREQ, I2C_MASTER);
    timer1_init(TMR_PRES_256, 10000);
    pwm_init(PWM_ID_1, 2000, 100);

    //-------------------------- Init I2C Chips -------------------------------
    PIN_PWM = 1;
    LED = 1;

    //---------------------------- Main Loop ----------------------------------
    while (1)
    {
        LED = !LED;

        dec_2_bcd(t.hrs, bcd);
        pcf8574_write_port(I2C_BUS_1, PCF8574_I2C_ADR + 0, pcf_tab[bcd[1]]);
        pcf8574_write_port(I2C_BUS_1, PCF8574_I2C_ADR + 1, pcf_tab[bcd[0]]);

        dec_2_bcd(t.min, bcd);
        pcf8574_write_port(I2C_BUS_1, PCF8574_I2C_ADR + 2, pcf_tab[bcd[1]]);
        pcf8574_write_port(I2C_BUS_1, PCF8574_I2C_ADR + 3, pcf_tab[bcd[0]]);

        dec_2_bcd(t.sec, bcd);
        pcf8574_write_port(I2C_BUS_1, PCF8574_I2C_ADR + 4, pcf_tab[bcd[1]]);
        pcf8574_write_port(I2C_BUS_1, PCF8574_I2C_ADR + 5, pcf_tab[bcd[0]]);

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
