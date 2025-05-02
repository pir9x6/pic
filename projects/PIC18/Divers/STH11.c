//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Titre   :   Capteur d'humidité SHT11            &&&
//&&&               Auteur  :   Pierre BLACHÉ                       &&&
//&&&               Date    :   Décembre 2008                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"
#include "SousProg.h"
#include "RS232.h"              // Routines RS232
#include "I2C.h"                // Routines I2C
#include "math.h"

#pragma config WDT = OFF        // Watchdog OFF
#pragma config OSC = HS         // Quartz 20MHz
#pragma config LVP = OFF        // Low Power Prog OFF

#define LED1    PORTDbits.RD0
#define LED2    PORTAbits.RA2
#define HumidRd 0b00000101
#define TempRd  0b00000011
#define StatRd  0b00000111
#define StatWr  0b00000110
#define reset   0b00011110

unsigned char Ones, Tens, Hund; // Conv Bin vers BCD
unsigned char Dixiemes, Centiemes, Milliemes;
unsigned char TempH, TempL;     // temperature sur 16 bits
unsigned char HumH, HumL;       // humidité sur 16 bits
void DS1621 (void);

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------- Main Program ---------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{
//----------------------- Initialisation du PIC -----------------------
    TRISA=0;                    // PORTA en sortie
    TRISB=0;                    //
    TRISC=0;                    //
    TRISD=0;                    //
    ADCON1=7;                   // PORTA en I/O Numériques
    LCD_Init (4);               // 4 bit en 2 lignes 5x8
    I2C_Init (49);              // 100kHz
//---------------------------------------------------------------------
    while (1)
    {
        Delay_ms (300);
        LED1 = !LED1;

        // acquisition et affichage de la temperature du DS1621
        DS1621 ();                  // acquisition de la temperature sur le DS1621
        Bin2BCD (TempH);
        WrLCD (0x80, 0);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);
        WrLCD (',', 1);
        if (TempL!=0)
            WrLCD ('5', 1);
        else
            WrLCD ('0', 1);
        WrLCD (0xDF, 1);            // °
        WrLCD ('C', 1);             // Celsius

        // acquisition et affichage du taux d'humidité du SHT11
        I2C_Start();
        I2C_Write (HumidRd);
        Delay_ms (300);
        HumH = I2C_Read ();
        I2C_Nack (0);               // envoi d'un ack
        HumL = I2C_Read ();
        I2C_Nack (1);               // envoi d'un no-ack
        I2C_Stop ();                // Stop Condition

        Bin2BCD (HumH);
        WrLCD (0x88, 0);
        WrLCD ('H', 1);
        WrLCD ('=', 1);
        WrLCD (Hund+0x30, 1);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);
        Bin2BCD (HumL);
        WrLCD (Hund+0x30, 1);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);

        // acquisition et affichage de la temperature du SHT11
        I2C_Start();
        I2C_Write (TempRd);
        Delay_ms (300);
        TempH = I2C_Read ();
        I2C_Nack (0);               // envoi d'un ack
        TempL = I2C_Read ();
        I2C_Nack (1);               // envoi d'un no-ack
        I2C_Stop ();                // Stop Condition

        Bin2BCD (TempH);
        WrLCD (0xC8, 0);
        WrLCD ('T', 1);
        WrLCD ('=', 1);
        WrLCD (Hund+0x30, 1);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);
        Bin2BCD (TempL);
        WrLCD (Hund+0x30, 1);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);

    }
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------- Lecture de la Temperature sur le DS1621 ---------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void DS1621 (void)
{
    I2C_Start ();               // Start Condition
    I2C_Write (0x90);           // Adresse + bit Write
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0xAC);           // Acces au registre de config.
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0x00);           // Configurer le capteur
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Stop ();                // Stop Condition

    I2C_Start ();               // Start Condition
    I2C_Write (0x90);           // Adresse + bit Write
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0xEE);           // Lancer la conversion
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Stop ();                // Stop Condition

    I2C_Start ();               // Start Condition
    I2C_Write (0x90);           // Adresse + bit Write
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0xAA);           // Envoyer la commande "lire la temp"
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Rstart ();              // Repeated Start-condition
    I2C_Write (0x91);           // Adresse + bit Read
    I2C_Ack ();                 // attente reception du Acknowledge
    TempH = I2C_Read ();        // Recuperer le Msb
    I2C_Nack (0);               // envoi d'un ack
    TempL = I2C_Read ();        // Recuperer le LSB
    I2C_Nack (1);               // envoi d'un no-ack
    I2C_Stop ();                // Stop Condition
}