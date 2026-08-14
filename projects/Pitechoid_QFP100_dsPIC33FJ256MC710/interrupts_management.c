/*****************************************************************************
* includes
******************************************************************************/
#include "hardware_profile.h"
#include "types.h"
#include <xc.h>


/*****************************************************************************
* Docs
******************************************************************************/
// Microchip/MPLABX/v6.20/packs/Microchip/dsPIC33F-GP-MC_DFP/1.4.235/xc16/docs/vector_docs


/*****************************************************************************
* Interrupt vector for External Interrupts
******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _INT0Interrupt(void)
{
    _INT0IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _INT1Interrupt(void)
{
    _INT1IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _INT2Interrupt(void)
{
    _INT2IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _INT3Interrupt(void)
{
    _INT3IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _INT4Interrupt(void)
{
    _INT4IF = 0;
}


/*****************************************************************************
* Interrupt vector for Timers
******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    _T1IF = 0;                      // clear IT flag
    T1CONbits.TON = 0;              // stop timer
    /****************************************************/

    /****************************************************/
    TMR1 = 0;                       // reset counter
    T1CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{
    _T2IF = 0;                      // clear IT flag
    T2CONbits.TON = 0;              // stop timer
    /****************************************************/

    /****************************************************/
    TMR2 = 0;                       // reset counter
    T2CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void)
{
    _T3IF = 0;                      // clear IT flag
    T3CONbits.TON = 0;              // stop timer
    /****************************************************/

    /****************************************************/
    TMR3 = 0;                       // reset counter
    T3CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void)
{
    _T4IF = 0;                      // clear IT flag
    T4CONbits.TON = 0;              // stop timer
    /****************************************************/

    /****************************************************/
    TMR4 = 0;                       // reset counter
    T4CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T5Interrupt(void)
{
    _T5IF = 0;                      // clear IT flag
    T5CONbits.TON = 0;              // stop timer
    /****************************************************/

    /****************************************************/
    TMR5 = 0;                       // reset counter
    T5CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T6Interrupt(void)
{
    _T6IF = 0;                      // clear IT flag
    T6CONbits.TON = 0;              // stop timer
    /****************************************************/

    /****************************************************/
    TMR6 = 0;                       // reset counter
    T6CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T7Interrupt(void)
{
    _T7IF = 0;                      // clear IT flag
    T7CONbits.TON = 0;              // stop timer
    /****************************************************/
PIN_LED2 = !PIN_LED2;
    /****************************************************/
    TMR7 = 0;                       // reset counter
    T7CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T8Interrupt(void)
{
    _T8IF = 0;                      // clear IT flag
    T8CONbits.TON = 0;              // stop timer
    /****************************************************/
PIN_LED_ERROR = !PIN_LED_ERROR;
    /****************************************************/
    TMR8 = 0;                       // reset counter
    T8CONbits.TON = 1;              // restart timer
}

void __attribute__((interrupt, no_auto_psv)) _T9Interrupt(void)
{
    _T9IF = 0;                      // clear IT flag
    T9CONbits.TON = 0;              // stop timer
    /****************************************************/
PIN_LED_ERROR = !PIN_LED_ERROR;
    /****************************************************/
    TMR9 = 0;                       // reset counter
    T9CONbits.TON = 1;              // restart timer
}


/*****************************************************************************
* Interrupt vector for UART
******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    _U1RXIF = 0;
    if (U1STAbits.URXDA)            // check if a data is present is the buffer
    {

    }
}

void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void)
{

}

void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void)
{
    _U2RXIF = 0;
    if (U2STAbits.URXDA)            // check if a data is present is the buffer
    {

    }
}

void __attribute__((interrupt, no_auto_psv)) _U2TXInterrupt(void)
{

}


/*****************************************************************************
* Interrupt vector for ADCs
******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _ADC1Interrupt(void)
{

}

void __attribute__((interrupt, no_auto_psv)) _ADC2Interrupt(void)
{

}


/*****************************************************************************
* Interrupt vector for Slave I2C
******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _SI2C1Interrupt(void)
{
    u8 tmp; //used for dummy read

    if((I2C1STATbits.R_W == 0)&&(I2C1STATbits.D_A == 0))        // reception of address
    {
        tmp = I2C1RCV;     //dummy read
    }
    else if((I2C1STATbits.R_W == 0)&&(I2C1STATbits.D_A == 1))   // master wants to write
    {
        //uart_write_char(I2C1RCV);
    }
    else if((I2C1STATbits.R_W == 1)&&(I2C1STATbits.D_A == 0))
    {
        tmp = I2C1RCV;
        //I2C1TRN = *RAMPtr;      //Read data from RAM & send data to I2C master device
        I2C1CONbits.SCLREL = 1; //Release SCL1 line
        while(I2C1STATbits.TBF);//Wait till all
    }
    _SI2C1IF = 0;               // clear IT flag
}

void __attribute__((interrupt, no_auto_psv)) _SI2C2Interrupt(void)
{
    _SI2C2IF = 0;               // clear IT flag
}


/*****************************************************************************
* Interrupt vector for Master I2C
******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _MI2C1Interrupt(void)
{
    _MI2C1IF = 0;               // clear IT flag
}

void __attribute__((interrupt, no_auto_psv)) _MI2C2Interrupt(void)
{
    _MI2C2IF = 0;               // clear IT flag
}


/*****************************************************************************
* Interrupt vector for SPI
******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _SPI1Interrupt(void)
{

}

void __attribute__((interrupt, no_auto_psv)) _SPI1ErrInterrupt(void)
{

}

void __attribute__((interrupt, no_auto_psv)) _SPI2ErrInterrupt(void)
{

}

void __attribute__((interrupt, no_auto_psv)) _SPI2Interrupt(void)
{

}
