//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                       Titre   :   Horloge                             &&&
//&&&                       Auteur  :   Pierre Blaché                       &&&
//&&&                       Date    :   Janvier 2008                        &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"
#include "SousProg.h"           // LCD & Tempos
#include "I2C.h"                // Routines I2C

#pragma config WDT = OFF        // Watchdog OFF
#pragma config OSC = HS         // Quartz 20MHz
#pragma config LVP = OFF        // Low Power Prog OFF

#define LED     PORTDbits.RD0   // LED
#define ligne1  0x80
#define ligne2  0xC0
#define ligne3  0x94
#define ligne4  0xD4


unsigned char Ones, Tens, Hund; // Conv Bin vers BCD
unsigned char TempH, TempL;     // temperature sur 16 bits
unsigned char tab[12]={
0x80, 0x87, 0x8E, 0xC0, 0xC7, 0xCE, 0x94, 0x9B, 0xA2, 0xD4, 0xDB, 0xE2};


void DS1621 (unsigned char Adress);
void Bin2BCD (unsigned int data);


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------------------- Main Program -------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{   unsigned int i;
//--------------------------- Initialisation du PIC ---------------------------
    TRISA=1;                    // PORTA en sortie
    TRISB=0;                    //
    TRISC=0;                    //
    TRISD=0;                    //
    ADCON1=7;                   // PORTA en I/O Numériques
    Delay_ms (200);
    LCD_Init (4);               // 4 bit en 2 lignes 5x8
    I2C_Init (49);              // 100kHz @ 20MHz
    Delay_ms (100);

//-----------------------------------------------------------------------------
    while (1)
    {
        Delay_ms (100);
        LED = !LED;

        DS1621 (0x90);          // acquisition de la temperature sur le DS1621
        Bin2BCD (TempH);        // conversion binaire vers BCD

        for (i=0; i<13; i++)
        {
            WrLCD (tab[i], 0);      // adresse de depard
            WrLCD (Tens+0x30, 1);   // dizaines de degres
            WrLCD (Ones+0x30, 1);   // degres
            WrLCD (',', 1);         // virgule
            if (TempL!=0)   WrLCD ('5', 1);
            else            WrLCD ('0', 1);     // dixiemes
            WrLCD (0xDF, 1);        // °
            WrLCD ('C', 1);         // Celsius
            Delay_ms(10);
        }
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------- Lecture de la Temperature sur le DS1621 -------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void DS1621 (unsigned char Adress)
{
    I2C_Start ();               // Start Condition
    I2C_Write (Adress+0);       // Adresse + bit Write
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0xAC);           // Acces au registre de config.
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0x00);           // Configurer le capteur
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Stop ();                // Stop Condition

    I2C_Start ();               // Start Condition
    I2C_Write (Adress+0);       // Adresse + bit Write
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0xEE);           // Lancer la conversion
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Stop ();                // Stop Condition

    I2C_Start ();               // Start Condition
    I2C_Write (Adress+0);       // Adresse + bit Write
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Write (0xAA);           // Envoyer la commande "lire la temp"
    I2C_Ack ();                 // attente reception du Acknowledge
    I2C_Rstart ();              // Repeated Start-condition
    I2C_Write (Adress+1);       // Adresse + bit Read
    I2C_Ack ();                 // attente reception du Acknowledge
    TempH = I2C_Read ();        // Recuperer le Msb
    I2C_Nack (0);               // envoi d'un ack
    TempL = I2C_Read ();        // Recuperer le LSB
    I2C_Nack (1);               // envoi d'un no-ack
    I2C_Stop ();                // Stop Condition
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------- Conversion Binaire vers BCD ---------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Bin2BCD (unsigned int data)
{
    Ones=Tens=Hund = 0;
    while (data >= 100) {data -= 100; Hund++;}
    while (data >= 10)  {data -= 10; Tens++;}
    Ones = data;                // unités = reste
}