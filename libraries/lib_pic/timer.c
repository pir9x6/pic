/******************************************************************************
* Title:    Driver for timers
* Supported MCU:    PIC18(L)F252 / dsPIC33FJ128MC802 / dsPIC33FJ256MC710
*******************************************************************************
* Versions: v1.0    01/08/2014  MPLAB: vx.x   XC16: vx.x
*                   Initial version
*           v1.1    14/08/2026  MPLAB: v6.20  XC-DSC: v4.0
*                   Added support for timers 6/7/8/9
******************************************************************************/

/*****************************************************************************
* includes
******************************************************************************/
#include "timer.h"
#include "types.h"

/*****************************************************************************
* Initialisation
******************************************************************************/
result_t timer_init(const TIMER_CFG_t *cfg)
{
    if (cfg->timer_id == TIMER_ID_0){
        return ERROR;
    }
    else if (cfg->timer_id == TIMER_ID_1){
        #if defined (_18F252) || (_18LF252)

            return ERROR;

        #elif defined (__dsPIC33FJ128MC820__) || (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T1CON = 0x0000;     // Reset configuration
            T1CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T1IF = 0;          // Reset Timer1 interrupt flag
            _T1IP = 6;          // priority level
            _T1IE = 1;          // Enable Timer 1 interrupt
            TMR1 = 0;           // reset counter
            PR1 = cfg->period;
            T1CONbits.TON = 1;  // Start Timer1

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_2){
        #if defined (_18F252) || (_18LF252)

            /* Enables the TMR2 to PR2 match interrupt */
            PIE1bits.TMR2IE = 1;

            /* Set Prescaler */
            T2CONbits.T2CKPS = (u8)cfg->timer_prescaler;

            /* set postscaler */
            T2CONbits.TOUTPS = (u8)cfg->timer_postscaler;

            /* Set timer period */
            PR2 = (u8)(cfg->period - 1);

            /* enable timer */
            T2CONbits.TMR2ON = 1;

        #elif defined (_18F26K42) || (_18F57K42)

            /* Enables the TMR2 to PR2 match interrupt */
            TMR2IE = 1;

            /* Set Prescaler */
            T2CONbits.CKPS = (u8)cfg->timer_prescaler;

            /* set postscaler */
            T2CONbits.OUTPS = (u8)cfg->timer_postscaler;

            /* set Fosc/4 as clock source */
            T2CLKbits.CS = 1;

            /* Set timer period */
            PR2 = cfg->period - 1;

            /* enable timer */
            T2CONbits.TMR2ON = 1;

        #elif defined (__dsPIC33FJ128MC820__) || (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T2CON = 0x0000;     // Reset configuration
            T2CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T2IF = 0;          // Reset Timer1 interrupt flag
            _T2IP = 6;          // priority level
            _T2IE = 1;          // Enable Timer 1 interrupt
            TMR2 = 0;           // reset counter
            PR2 = cfg->period;
            T2CONbits.TON = 1;  // Start Timer1

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_3){

        #if defined (__dsPIC33FJ128MC820__) || (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T3CON = 0x0000;     // Reset configuration
            T3CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T3IF = 0;          // Reset Timer1 interrupt flag
            _T3IP = 6;          // priority level
            _T3IE = 1;          // Enable Timer 1 interrupt
            TMR3 = 0;           // reset counter
            PR3 = cfg->period;
            T3CONbits.TON = 1;  // Start Timer1

        #else
            return ERROR;
        #endif

    }
    else if (cfg->timer_id == TIMER_ID_4){
        #if defined (_18F26K42) || (_18F57K42)

            /* Enables the TMR4 to PR4 match interrupt */
            TMR4IE = 1;

            /* Set Prescaler */
            T4CONbits.CKPS = (u8)cfg->timer_prescaler;

            /* set postscaler */
            T4CONbits.OUTPS = (u8)cfg->timer_postscaler;

            /* set Fosc/4 as clock source */
            T4CLKbits.CS = 1;

            /* Set timer period */
            PR4 = cfg->period - 1;

            /* enable timer */
            T4CONbits.TMR4ON = 1;

        #elif defined (__dsPIC33FJ128MC820__) || (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T4CON = 0x0000;     // Reset configuration
            T4CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T4IF = 0;          // Reset Timer1 interrupt flag
            _T4IP = 6;          // priority level
            _T4IE = 1;          // Enable Timer 4 interrupt
            TMR4 = 0;           // reset counter
            PR4 = cfg->period;
            T4CONbits.TON = 1;  // Start Timer4

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_5){
        #if defined (__dsPIC33FJ128MC820__) || (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T5CON = 0x0000;     // Reset configuration
            T5CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T5IF = 0;          // Reset Timer5 interrupt flag
            _T5IP = 6;          // priority level
            _T5IE = 1;          // Enable Timer 5 interrupt
            TMR5 = 0;           // reset counter
            PR5 = cfg->period;
            T5CONbits.TON = 1;  // Start Timer5

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_6){
        #if defined (_18F26K42) || (_18F57K42)

            /* Enables the TMR2 to PR2 match interrupt */
            TMR6IE = 1;

            /* Set Prescaler */
            T6CONbits.CKPS = (u8)cfg->timer_prescaler;

            /* set postscaler */
            T6CONbits.OUTPS = (u8)cfg->timer_postscaler;

            /* set Fosc/4 as clock source */
            T6CLKbits.CS = 1;

            /* Set timer period */
            PR6 = cfg->period - 1;

            /* enable timer */
            T6CONbits.TMR6ON = 1;

        #elif defined (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T6CON = 0x0000;     // Reset configuration
            T6CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T6IF = 0;          // Reset Timer6 interrupt flag
            _T6IP = 6;          // priority level
            _T6IE = 1;          // Enable Timer 6 interrupt
            TMR6 = 0;           // reset counter
            PR6 = cfg->period;
            T6CONbits.TON = 1;  // Start Timer6

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_7)
    {
        #if defined (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T7CON = 0x0000;     // Reset configuration
            T7CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T7IF = 0;          // Reset Timer6 interrupt flag
            _T7IP = 6;          // priority level
            _T7IE = 1;          // Enable Timer 6 interrupt
            TMR7 = 0;           // reset counter
            PR7 = cfg->period;
            T7CONbits.TON = 1;  // Start Timer6

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_8)
    {
        #if defined (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T8CON = 0x0000;     // Reset configuration
            T8CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T8IF = 0;          // Reset Timer6 interrupt flag
            _T8IP = 6;          // priority level
            _T8IE = 1;          // Enable Timer 6 interrupt
            TMR8 = 0;           // reset counter
            PR8 = cfg->period;
            T8CONbits.TON = 1;  // Start Timer6

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_9)
    {
        #if defined (__dsPIC33FJ256MC710__)

            // Freq Timer = Fosc / Prescaler / TMR
            T9CON = 0x0000;     // Reset configuration
            T9CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            _T9IF = 0;          // Reset Timer6 interrupt flag
            _T9IP = 6;          // priority level
            _T9IE = 1;          // Enable Timer 6 interrupt
            TMR9 = 0;           // reset counter
            PR9 = cfg->period;
            T9CONbits.TON = 1;  // Start Timer6

        #else
            return ERROR;
        #endif
    }
    else if (cfg->timer_id == TIMER_ID_2_3)
    {
        #if defined (__dsPIC33FJ128MC820__) || (__dsPIC33FJ256MC710__)

            T3CONbits.TON = 0;              // Stop any 16-bit Timer3 operation
            T2CONbits.TON = 0;              // Stop any 16/32-bit Timer3 operation
            T2CONbits.T32 = 1;              // Enable 32-bit Timer mode
            T2CONbits.TCS = 0;              // Select internal instruction cycle clock
            T2CONbits.TGATE = 0;            // Disable Gated Timer mode
            TMR2 = 0;                       // reset compteur
            TMR3 = 0;                       // reset compteur
            PR2 = (u16)cfg->period;         // Timer period (lsb)
            PR3 = (u16)(cfg->period >> 16); // Timer period (msb)
            T2CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            IPC2bits.T3IP = 0x01;           // Set Timer3 Interrupt Priority Level
            IFS0bits.T3IF = 0;              // Clear Timer3 Interrupt Flag
            IEC0bits.T3IE = 1;              // Enable Timer3 interrupt
            T2CONbits.TON = 1;              // Start 32-bit Timer

        #endif
    }
    else if (cfg->timer_id == TIMER_ID_4_5)
    {
        #if defined (__dsPIC33FJ128MC820__) || (__dsPIC33FJ256MC710__)

            T5CONbits.TON = 0;              // Stop any 16-bit Timer3 operation
            T4CONbits.TON = 0;              // Stop any 16/32-bit Timer3 operation
            T4CONbits.T32 = 1;              // Enable 32-bit Timer mode
            T4CONbits.TCS = 0;              // Select internal instruction cycle clock
            T4CONbits.TGATE = 0;            // Disable Gated Timer mode
            TMR4 = 0;                       // reset compteur
            TMR5 = 0;                       // reset compteur
            PR4 = (u16)cfg->period;         // Timer period (lsb)
            PR5 = (u16)(cfg->period >> 16); // Timer period (msb)
            T4CONbits.TCKPS = cfg->timer_prescaler;    // Prescaler (0=1 - 1=8 - 2=64 - 3=256)
            IPC7bits.T5IP = 0x01;           // Set Timer3 Interrupt Priority Level
            IFS1bits.T5IF = 0;              // Clear Timer3 Interrupt Flag
            IEC1bits.T5IE = 1;              // Enable Timer3 interrupt
            T4CONbits.TON = 1;              // Start 32-bit Timer

        #endif
    }
    else{
        return ERROR;
    }

    return SUCCESS;
}
