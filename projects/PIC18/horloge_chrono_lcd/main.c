/*
 * File:   main.c
 * Author: Pierre
 *
 * Created on 10 décembre 2017, 23:55
 */


#include <xc.h>
#include "clock.h"
#include "delays.h"
#include "hardware_profile.h"
#include "lcd_2x16.h"
#include "timer.h"
#include "types.h"
#include "uart.h"

t_time t;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Sous-Prog D'interruption ----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void interrupt high_priority timer2_irq(void)
{
    static u16 CntTmr1 = 0;

    T2CONbits.TMR2ON = 0;               // Timer 2 off
    PIR1bits.TMR2IF = 0;                // RAZ du Timer
    T2CONbits.TMR2ON = 1;               // Timer 2 on

    if (CntTmr1++ == 16){
        t.sec++;
        LED = !LED;
        lcd_write_hour(t, LCD_LINE_1, LCD_CHAR_1);
        clock_update(&t);
        CntTmr1 = 0;
        uart_write_u8(UART_ID_1, 123, UART_OPT_NONE);
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Configuration du Processeur -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma config WDT = OFF        // Watchdog OFF
#pragma config OSC = HS         // Quartz 10MHz
#pragma config LVP = OFF        // Low Power Prog OFF


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------------- Main --------------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main(void) {
//--------------------------- Initialisation du PIC ---------------------------
    TRISA = 0b00000000;         // PORTA en sortie
    TRISB = 0x00;               // PORTB en sortie
    TRISC = 0x00;               // PORTC en sortie
    ADCON1 = 0x07;              // PORTA en I/O Numériques
    
//-------------------------- Initialization of Timer 2 ------------------------
    timer2_init(/*postscaler*/4, /*timer*/255);                 // 16 - 255
    
//--------------------------- Initialization of UART --------------------------
    uart_init(UART_ID_1, UART_FREQ, UART_OPT_NONE);
    
//---------------------------------- init lcd ---------------------------------
    lcd_2x16_init();

    while (1)
    {
        Nop();
    }
    return;
}
