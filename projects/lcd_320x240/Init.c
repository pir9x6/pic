//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   Initialisation                      &&&
//&&&                   Fichier     :   Init.c                              &&&
//&&&                   Description :   initialisation du PIC et périph     &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Pierre BLACHÉ                       &&&
//&&&                   Date        :   Avril 2011                          &&&
//&&&                   Version     :   2.0                                 &&&
//&&&                   MCU         :   dsPIC33FJ256GP506A                  &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                                                                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Fichiers Requis :   Init.c & Init.h                     &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p33Fxxxx.h"

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- Configuration de l'oscillateur -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Init_Osc (void)
{
    PLLFBD = 30;                    // Fosc= 10M*32/(2*2)=80Mhz = 40MIPS
    CLKDIVbits.PLLPOST = 0;         // N1=2
    CLKDIVbits.PLLPRE = 0;          // N2=2
    OSCTUN = 0;                     // Tune FRC oscillator, if FRC is used
    RCONbits.SWDTEN = 0;            // Disable Watch Dog Timer
    __builtin_write_OSCCONH(3);     // Initiate Clock Switch to FRC with PLL (NOSC=1)
    __builtin_write_OSCCONL(1);     // Start clock switching
    while (OSCCONbits.COSC!=3);     // Oscillateur externe + PLL
    while (OSCCONbits.LOCK!=1);     // Wait for PLL to lock
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------- Configuration des I/O ---------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Init_IO (void)
{
    TRISB = 0x0000;                 // tout en sortie (data LCD)
    TRISC = 0x0000;
    TRISD = 0x0000;
    TRISDbits.TRISD9 = 1;           // entrée Busy
    TRISDbits.TRISD10 = 1;          // entrée IRQ
    TRISF = 0x0014;                 // RF4 en entrée (RX) et RF2 (SDI)
    TRISG = 0x0000;
    AD1PCFGL = 0xFFFF;              // PORTB en  digital I/O
}

