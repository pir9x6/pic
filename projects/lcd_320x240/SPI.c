//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   Afficheur LCD                       &&&
//&&&                   Fichier     :   LCD_320x240.h                       &&&
//&&&                   Description :   prototypes des Fonctions LCD        &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Dr Pierre BLACHÉ                    &&&
//&&&                   Date        :   Octobre 2010                        &&&
//&&&                   Version     :   1.0                                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Fichiers Requis :   LCD_320x240.c                       &&&
//&&&                                   LCD_320x240.h                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "Constantes.h"


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- initialisation de la liaison SPI ---------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void SPI_Init (void)
{
    SPI1CON1 = 0x0000;
    SPI1CON1bits.MSTEN = 1;         // Master Mode Enabled
    SPI1CON1bits.PPRE = 0;          // prescaler primaire, clock = Fcyc/64 (625kHz)
    SPI1CON1bits.SPRE = 0;          // prescaler secondaire, clock = 625k/8 (78.125kHz)
    SPI1CON1bits.MODE16 = 0;        // 8 bits operation
    SPI1CON1bits.CKE = 0;           // Dout changes on transition from active clock state to Idle clock state
    SPI1CON1bits.CKP = 0;           // clock idle state is low
    SPI1CON2 = 0x0000;
    SPI1STAT = 0x0000;
    SPI1STATbits.SPIEN = 1;         // Enable SPI module
    IFS0bits.SPI1IF = 0;            // clear interrupt flag
    IEC0bits.SPI1IE = 0;            // clear interrupt
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------- Envoi d'une donnée -----------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void SPI_Write (unsigned int Data)
{
    unsigned int temp;
    temp = SPI1BUF;             // dummy read to clear the flag
    SPI1BUF = Data;
    while(!SPI1STATbits.SPIRBF)
    {
        Nop();
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------------- Réception d'une donnée ---------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
unsigned int SPI_Read (void)
{
    unsigned int temp;
//  unsigned int dum1, dum2;

    temp = SPI1BUF;         // dummy read of the SPI1BUF register
                            // to clear the SPIRBF flag
    SPI1BUF = 0xFFFF;         // write the data out to the SPI peripheral

    while(!SPI1STATbits.SPIRBF)
    {
        Nop();
    }

    temp = 0xFFFF & SPI1BUF;          // read result
    return temp;
}


