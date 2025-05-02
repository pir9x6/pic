//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   Afficheur LCD Couleur 320x240       &&&
//&&&                   Fichier     :   main.c                              &&&
//&&&                   Description :   Programme principal                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Pierre BLACHÉ                       &&&
//&&&                   Date        :   Avril 2011                          &&&
//&&&                   Version     :   1.0                                 &&&
//&&&                   MCU         :   dsPIC33FJ128MC802                   &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                                                                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Fichiers Requis :   main.c                              &&&
//&&&                                   Delays.c & Delays.h                 &&&
//&&&                                   p33FJ128MC802.gld                   &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p33Fxxxx.h"
#include "Delays.h"
#include "LCD_320x240.h"


//----------------------- Configuration du processeur -------------------------
_FOSCSEL(FNOSC_PRI);                // Primary (XT, HS, EC) Oscillator
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON  & POSCMD_HS);
                                    // Clock Switching is enabled
                                    // OSC2 Pin Function : OSC2 is Clock Output
                                    // Primary Oscillator Mode : HS crystals
_FWDT(FWDTEN_OFF);                  // watchdog is off
_FICD(JTAGEN_OFF);                  // desactiver le module JTAG

//-------------------------------- Constantes ---------------------------------
#define LED     LATAbits.LATA0

// afficheur LCD
#define LCD_Rst     LATAbits.LATA0
//#define   LCD_CS      LATFbits.LATF1  // chip select du LCD actif à "0"
#define LCD_WR      LATAbits.LATA1
//#define   LCD_RD      LATGbits.LATG1
#define LCD_RS      LATAbits.LATA4
#define LCD_Data    LATB
//-------------------------------- Variables ----------------------------------


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
    unsigned int x;
//-------------------------- Configuration du MCU -----------------------------
    PLLFBD = 30;                    // Fosc= 10M*32/(2*2)=80Mhz = 40MIPS
    CLKDIVbits.PLLPOST = 0;         // N1=2
    CLKDIVbits.PLLPRE = 0;          // N2=2
    OSCTUN = 0;                     // Tune FRC oscillator, if FRC is used
    RCONbits.SWDTEN = 0;            // Disable Watch Dog Timer
    __builtin_write_OSCCONH(3);     // Initiate Clock Switch to FRC with PLL (NOSC=1)
    __builtin_write_OSCCONL(1);     // Start clock switching
    while (OSCCONbits.COSC!=3);     // Oscillateur externe + PLL
    while (OSCCONbits.LOCK!=1);     // Wait for PLL to lock
//-----------------------------------------------------------------------------
    TRISA = 0x0000;                 // RA0 en entrée (D0)
    TRISB = 0x0000;                 // RB0 à RB7 et RB9 en entrée (RX)
    AD1PCFGL = 0xFFFF;              // PORTB en  digital I/O
//-----------------------------------------------------------------------------
    LCD_Init();

    LCD_Draw_FillRectangle(4444);

    while (1)
    {
        Delay_ms (300);
        LCD_Adresse(10, 10, 100, 100);
        LCD_Write_Data(x);
        x = x + 100;
//      for(x=0; x<190; x++)
//      {
//          showzifustr(x,155,"Arduino",0,0xffff);
//          Delay_ms(300);
//      }

//      for(x=190; x>0; x-=1)
//      {
//          showzifustr(x,155,"Arduino",0,0xffff);
//          Delay_ms(10);
//
//      }
    }

    return 0;
}
