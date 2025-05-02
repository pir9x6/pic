//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   Afficheur LCD Couleur 320x240       &&&
//&&&                   Fichier     :   main.c                              &&&
//&&&                   Description :   Programme principal                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Pierre BLACHÉ                       &&&
//&&&                   Date        :   Avril 2011                          &&&
//&&&                   Version     :   1.0                                 &&&
//&&&                   MCU         :   dsPIC33FJ256GP506A                  &&&
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
#include "Constantes.h"
#include "Init.h"
#include "Uart.h"


//----------------------- Configuration du processeur -------------------------
_FOSCSEL(FNOSC_PRI);                // Primary (XT, HS, EC) Oscillator
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON  & POSCMD_HS);
                                    // Clock Switching is enabled
                                    // OSC2 Pin Function : OSC2 is Clock Output
                                    // Primary Oscillator Mode : HS crystals
_FWDT(FWDTEN_OFF);                  // watchdog is off
_FICD(JTAGEN_OFF);                  // desactiver le module JTAG


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
//-------------------------- Configuration du MCU -----------------------------
    Init_Osc();
    Init_IO();
    Init_USART();
    LCD_Init();

    LCD_Draw_FillRectangle(4444);
//-----------------------------------------------------------------------------
    while (1)
    {
        tx232('a');
        //LCD_Adresse(10, 20, 50, 100);
        //LCD_Write_Data(456);
        //LCD_Adresse(90, 70, 180, 100);
        //LCD_Write_Data(456);

        LED1 = 1; LED2 = 0; Delay_ms (50);
        LED2 = 1; LED1 = 0; Delay_ms (50);
        LED3 = 1; LED2 = 0; Delay_ms (50);
        LED4 = 1; LED3 = 0; Delay_ms (50);
        LED5 = 1; LED4 = 0; Delay_ms (50);
        LED6 = 1; LED5 = 0; Delay_ms (50);
        LED5 = 1; LED6 = 0; Delay_ms (50);
        LED4 = 1; LED5 = 0; Delay_ms (50);
        LED3 = 1; LED4 = 0; Delay_ms (50);
        LED2 = 1; LED3 = 0; Delay_ms (50);
    }

    return 0;
}
