/*****************************************************************************
* Includes
******************************************************************************/
#include "console.h"
#include "hardware_profile.h"
#include "types.h"
#include "xc.h"

extern bool_t time_has_changed_timer;

/*****************************************************************************
* High-priority interrupts (18F252)
******************************************************************************/
#if defined (_18F252) || defined (_18LF252)
void __interrupt(high_priority) HighISR()
{
    /*******************************************************/
    /* Timer 0 interrupt */
    /*******************************************************/
    if (INTCONbits.TMR0IF && INTCONbits.TMR0IE){
        INTCONbits.TMR0IF = 0;     /* clear interrupt flag */
    }

    /*******************************************************/
    /* Timer 1 interrupt */
    /*******************************************************/
    else if (PIR1bits.TMR1IF && PIE1bits.TMR1IE){
        PIR1bits.TMR1IF = 0;     /* clear interrupt flag */
    }

    /*******************************************************/
    /* Timer 2 interrupt */
    /*******************************************************/
    else if (PIR1bits.TMR2IF && PIE1bits.TMR2IE){
        PIR1bits.TMR2IF = 0;     /* clear interrupt flag */

        static u16 CntTmrIncSec = 0;

        CntTmrIncSec++;

        if (CntTmrIncSec == 499){
            PIN_LED_SEC = 1;
        }
        else if (CntTmrIncSec == 499)
        {
            time_has_changed_timer = TRUE;
            PIN_LED_SEC = 0;
            CntTmrIncSec = 0;
        }
    }

    /*******************************************************/
    /* Timer 3 interrupt */
    /*******************************************************/
    else if (PIR2bits.TMR3IF && PIE2bits.TMR3IE){
        PIR2bits.TMR3IF = 0;     /* clear interrupt flag */

    }

    /*******************************************************/
    /* UART interrupt */
    /*******************************************************/
    else if (PIR1bits.RCIF && PIE1bits.RCIE){
        PIR1bits.RCIF = 0;     /* clear interrupt flag */
        u8 uart_rx_data = RCREG;
        // command_line_interpreter(UART_ID_1, uart_rx_data);
    }

}

/*****************************************************************************
* Low-priority interrupts (18F252)
******************************************************************************/
void __interrupt(low_priority) LowISR(void)
{
    if(PIR1bits.TMR1IF)
    {
        PIR1bits.TMR1IF = 0;

        // traitement
    }
}

#endif



/*****************************************************************************
* High-priority interrupts (18FxxKxx & 18FxxQxx)
******************************************************************************/
#if defined (_18F26K42) || defined (_18F57Q43)
void __interrupt(irq(TMR2), high_priority) HighISR(void)
{
    static u16 CntTmrIncSec = 0;

    /* Disable Timer 2 */
    T2CONbits.TMR2ON = 0;

    /* clear timer interrupt */
    #if defined (_18F26K42)
        PIR4bits.TMR2IF = 0;
    #elif defined (_18F57Q43)
        PIR3bits.TMR2IF = 0;
    #else
        #error -- processor ID not specified in generic header file
    #endif

    // NOP10; NOP10; NOP10; NOP10; NOP10; NOP10; NOP10; NOP10;

    /* enable timer 2 */
    T2CONbits.TMR2ON = 1;

    CntTmrIncSec++;

    if (CntTmrIncSec == 499){
        PIN_LED_SEC = !PIN_LED_SEC;
    }
    else if (CntTmrIncSec == 999)
    {
        time_has_changed_timer = TRUE;
        PIN_LED_SEC = !PIN_LED_SEC;
        CntTmrIncSec = 0;
    }
}
#endif
