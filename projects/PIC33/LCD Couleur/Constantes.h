//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   Constantes                          &&&
//&&&                   Fichier     :   Constantes.h                        &&&
//&&&                   Description :   Constantes                          &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Pierre BLACHÉ                       &&&
//&&&                   Date        :   Avril 2011                          &&&
//&&&                   Version     :   2.0                                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                                                                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Fichiers Requis :   Constantes.h                        &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p33Fxxxx.h"


// LED
#define LED1        LATCbits.LATC1
#define LED2        LATCbits.LATC2
#define LED3        LATGbits.LATG6
#define LED4        LATGbits.LATG7
#define LED5        LATGbits.LATG8
#define LED6        LATGbits.LATG9

// afficheur LCD
#define LCD_Data    LATB
#define LCD_Rst     LATFbits.LATF0
#define LCD_CS      LATFbits.LATF1  // chip select du LCD actif à "0"
#define LCD_WR      LATGbits.LATG0
#define LCD_RD      LATGbits.LATG1
#define LCD_RS      LATGbits.LATG14

// controlleur écran tactile - ADS7843
#define Touch_CS    LATDbits.LATD8
#define Touch_Dout  LATFbits.LATF2  // données serie allant du PIC vers le LCD
#define Touch_Din   LATFbits.LATF3  // données série provenant du LCD
#define Touch_Clk   LATFbits.LATF6
#define Touch_Busy  PORTDbits.RD9
#define Touch_IRQ   PORTDbits.RD10

//extern volatile unsigned int  LEDS __attribute__((__sfr__));
//typedef struct tagLEDSBITS {
//  unsigned LED0:1;
//  unsigned LED1;
//  unsigned LED2:1;
//  unsigned LED3:1;
//  unsigned LED4:1;
//  unsigned LED5:1;
//} LEDSBITS;
//extern volatile LEDSBITS LATxbits __attribute__((__sfr__));
