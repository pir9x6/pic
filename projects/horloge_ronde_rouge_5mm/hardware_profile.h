#ifndef _HARDWARE_PROFILE_H_
#define _HARDWARE_PROFILE_H_

//#define GetSystemClock()        (16000000ul)
#define GetSystemClock()        (20000000ul)
#define GetInstructionClock()   (GetSystemClock()/4)
#define GetPeripheralClock()    GetInstructionClock()

#define I2C_FREQ                100000                  // i2c bus frequency
#define UART_FREQ               115200                  // uart frequency

#define DATE                    PORTAbits.RA0           // affichage de la date
#define HEURE                   PORTAbits.RA1           // affichage de l'heure
#define THERMO                  PORTAbits.RA2           // affichage de la temperature
#define SW_MINUS                PORTAbits.RA3           // bouton 1 (selection)
#define SW_PLUS                 PORTAbits.RA4           // bouton 2 (decrementation)
#define SW_SELECT               PORTAbits.RA5           // bouton 3 (incrementation)
#define STROBE                  PORTCbits.RC0           // validation des registres à décalage
#define DATA                    PORTCbits.RC1           // données des registres à décalage
#define CLOCK                   PORTCbits.RC2           // horloge des registres à décalage
#define PIN_SCL                 PORTCbits.RC3           // horloge du bus I2C
#define PIN_SDA                 PORTCbits.RC4           // données du bus I2C
#define AFF1                    PORTCbits.RC5           // selection de l'afficheur des 10zaines d'heures
#define AFF2                    PORTCbits.RC6           // selection de l'afficheur des heures
#define AFF3                    PORTCbits.RC7           // selection de l'afficheur des 10zaines de minutes
#define Seg_a                   PORTBbits.RB0           // segment a
#define Seg_b                   PORTBbits.RB1           // segment b
#define Seg_c                   PORTBbits.RB2           // segment c
#define Seg_d                   PORTBbits.RB3           // segment d
#define Seg_e                   PORTBbits.RB4           // segment e
#define Seg_f                   PORTBbits.RB5           // segment f
#define Seg_g                   PORTBbits.RB6           // segment g
#define AFF4                    PORTBbits.RB7           // selection de l'afficheur des minutes

#endif
