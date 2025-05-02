//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Titre   :   Multimetre 2.0              &&&
//&&&               Auteur  :   Pierre Blaché               &&&
//&&&               Date    :   Septembre 2008              &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"

#pragma config WDT = OFF        // Watchdog OFF
#pragma config OSC = HS         // Quartz 20MHz
#pragma config LVP = OFF        // Low Power Prog OFF

#define LCD_RS  PORTBbits.RB4   // broche RS du LCD
#define LCD_E   PORTBbits.RB5   // broche Enable du LCD
#define Capa    PORTCbits.RC0
#define Select  PORTCbits.RC1
#define LED     PORTAbits.RA2

void WrLCD (unsigned char Data, unsigned char RS);
void Delay_us (unsigned int Cnt);
void Delay_ms (unsigned int Cnt);
void LCD_Init (void);
void Bin2BCD (unsigned long Temp);

unsigned char Ones, Tens, Hund, Thou, TenK, HunK, Mill;
unsigned int temp;
unsigned long Cmpt;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Main Program ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{
//------------------ Initialisation du PIC --------------------
    TRISA = 0x01;               // RA0 en entrée (voltmetre)
    TRISB = 0x00;               // PORTB en sortie (LCD)
    TRISC = 0xFF;               // RC0 & RC1 en entrées (capa + select)
//------------------ Configuration du CAN ---------------------
    ADCON0 = 0x01;              // ADC is ON
    ADCON1 = 0x8E;              // RA0 as an analog input, Right justified
    LCD_Init ();                // Initialisation de l'afficheur LCD
//----------------- Commencement du programme -----------------
    WrLCD (0x80, 0);            // affiche "Volt" sur la 1ere ligne
    WrLCD ('V', 1);
    WrLCD ('o', 1);
    WrLCD ('l', 1);
    WrLCD ('t', 1);
    WrLCD (0xC0, 0);            // affiche "Capa" sur la 2e ligne
    WrLCD ('C', 1);
    WrLCD ('a', 1);
    WrLCD ('p', 1);
    WrLCD ('a', 1);

    while (1)
    {
        if (!Select)                // si entrée de selection (RC1) = 1 alors -> voltmetre
        {
            // Voltmètre --------------------------------------
            ADCON0bits.GO = 1;          // lancer la conversion
            while (ADCON0bits.GO != 0); // attendre fin de la conversion
            temp = ADRESH;
            temp = (temp<<8) | ADRESL;
            Bin2BCD (temp*9.765);       // *9.765 pour faire correspondre 1024 à 10V
            WrLCD (0x8B, 0);            // adresse de debut d'affichage
            if (Thou != 0)              // determine s'il faut afficher en V ou en mV
            {
                WrLCD (Thou+0x30, 1);
                WrLCD (',', 1 );
                WrLCD (Hund+0x30, 1);   // +0x30 pour convertir en ASCII
                WrLCD (Tens+0x30, 1);
                WrLCD ('V', 1);
            }
            else
            {
                WrLCD (Hund+0x30, 1);
                WrLCD (Tens+0x30, 1);
                WrLCD (Ones+0x30, 1);
                WrLCD ('m', 1);
                WrLCD ('V', 1);
            }
        }
        else                            // si entrée de selection (RC1) = 0 alors -> capacimetre
        {
            // Capacimètre ------------------------------------
            Cmpt=0;
            while (Capa != 1);          // attendre un front montant
            while (Capa != 0)   { Cmpt++; } // attends fin de l'impulsion
            Bin2BCD (Cmpt);

            WrLCD (0xC8, 0);            // adresse du 1er caractere sur LCD
            if (Thou != 0)              // determine s'il faut affiché en µF ou en nF
            {
                if (Mill!=0)    WrLCD (Mill+0x30, 1);   // milliers de micro-farad
                else {WrLCD (' ', 1);}                  // mettre un espace si nbre =0
                if ((HunK|Mill)!=0) WrLCD (HunK+0x30, 1);// centaines de micro-farad
                else {WrLCD (' ', 1);}
                if ((TenK|HunK)!=0) WrLCD (TenK+0x30, 1);// dizaines de micro-farad
                else {WrLCD (' ', 1);}
                WrLCD (Thou+0x30, 1);   // micros farad
                WrLCD (',', 1);
                WrLCD (Hund+0x30, 1);   // centaines de nano-farad
                WrLCD (0xE4, 1);        // µ
                WrLCD ('F', 1);
            }
            else
            {
                WrLCD (' ', 1);
                WrLCD (' ', 1);
                WrLCD (' ', 1);
                if (Hund!=0)    WrLCD (Hund+0x30, 1);   // centaines de nano-farad
                else {WrLCD (' ', 1);}
                WrLCD (Tens+0x30, 1);   // dizaines de nano-farad
                WrLCD (Ones+0x30, 1);   // nano-farad
                WrLCD ('n', 1);
                WrLCD ('F', 1);
            }
        }
        LED=!LED;
        Delay_ms (500);
    }
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------- Envoi de Données à l'afficheur en 4 bits ----------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void WrLCD (unsigned char Data, unsigned char RS)
{
    LCD_RS = RS;                // Registre de données/instructions
    PORTB = (PORTB & 0xF0) | (Data >> 4);   // Envoyer MSB
    LCD_E = 1;
    Delay_us (10);
    LCD_E = 0;
    PORTB = (PORTB & 0xF0) | (Data & 0x0F); // Envoyer LSB
    LCD_E = 1;
    Delay_us (10);
    LCD_E = 0;
    Delay_us (500);             // Delay entre 2 envois
}

//-------------------- Initialisation LCD ---------------------
void LCD_Init (void)
{
    WrLCD (0x30, 0);            // Valeur d'initialisation
    WrLCD (0x30, 0);            // a repeter 3 fois
    WrLCD (0x30, 0);            // 3e fois
    WrLCD (0x28, 0);            // Données en 8 Bits sur 2 lignes en 5x8
    WrLCD (0x28, 0);            // Données en 8 Bits sur 2 lignes en 5x8
    WrLCD (0x14, 0);            // $14, Deplacement vers la droite
    WrLCD (0x0C, 0);            // $0C, Display ON, Cursor OFF, Blink OFF
    WrLCD (0x06, 0);            // $06, Increment, no display shift
    WrLCD (0x01, 0);            // Effacer l'afficheur
    Delay_ms (10);
    WrLCD (0x80, 0);            // Se positionner sur la 1ere Ligne
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------- Conversion Binaire vers BCD -----------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Bin2BCD (unsigned long Temp)   // temp=nombre à convertir
{
    Ones=Tens=Hund=Thou=TenK=HunK=Mill=0;
    while (Temp >= 1000000) {Temp -= 1000000;Mill++;}
    while (Temp >= 100000)  {Temp -= 100000;HunK++; }
    while (Temp >= 10000)   {Temp -= 10000; TenK++; }
    while (Temp >= 1000)    {Temp -= 1000;  Thou++; }
    while (Temp >= 100)     {Temp -= 100;   Hund++; }
    while (Temp >= 10)      {Temp -= 10;    Tens++; }
    Ones = Temp;                // unités = le reste
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Temporisations ----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Delay_ms (unsigned int Cnt)
{
    unsigned int x, y;
    for (x=Cnt; x!=0; x--)      // Boucle executée Cnt fois
    {
        for (y=332; y!=0; y--); // Boucle executée Cnt fois
    }
}

void Delay_us (unsigned int Cnt)
{
    unsigned int i;
    for (i = (Cnt>>2); i != 0; i--);// Boucle executée Cnt/4 fois
}