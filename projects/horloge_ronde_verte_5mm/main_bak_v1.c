//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&					    Titre 	: 	Horloge à LED			    		&&&
//&&&					    Auteur 	: 	Pierre Blaché			    		&&&
//&&&					    Date 	: 	Juin 2012				    		&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"
#include "i2c.h"
#include "math.h"
#include "delays.h"
#include "ds1621.h"
#include "ds1307.h"
#include "pcf8574.h"
#include "main.h"
#include "Conversion.h"

    
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Configuration du Processeur -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma config WDT = OFF		// Watchdog OFF
#pragma config OSC = HS 		// Quartz 10MHz
#pragma config LVP = OFF		// Low Power Prog OFF


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------ Déclaration des constantes -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define	BAUDS	100000			// frequence de l'I2C (100kHz)
#define	FOSC	16000000		// frequence du quartz (16MHz)

#define	DATE	PORTAbits.RA2	// affichage de la date
#define	HEURE	PORTAbits.RA3	// affichage de l'heure
#define	THERMO	PORTAbits.RA5	// affichage de la temperature

#define	SW2		PORTCbits.RC1	// bouton 1 (selection)
#define	SW3		PORTAbits.RA1	// bouton 2 (decrementation)
#define	SW1		PORTAbits.RA0	// bouton 3 (incrementation)

#define	SCL		PORTCbits.RC3	// horloge du bus I2C
#define	SDA		PORTCbits.RC4	// données du bus I2C

#define	HERTZ   PORTBbits.RB0   // entrée 1 Hz provenant de la RTC (inutilisée)

#define PWM     PORTCbits.RC2   // PWM de commande tension LED

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------ Déclaration des variables --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
unsigned int Ones=0, Tens=0, Hund=0;		// conversion decimal vers BCD
unsigned char Hrs=22, Min=31, Sec=30, Dow=6, Day=27, Mth=10, Yrs=12;
signed char TempL=0, TempH=0;				// partie entiere de la température
unsigned char CntTmr=0;
unsigned char select_display=0;
unsigned char Seg [13] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10, 0x1C, 0x3F, 0xFF};
unsigned char on   [8] = {0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00};
unsigned char off  [8] = {0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};

unsigned char pcf_sec;
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------------- prototypes --------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void InterruptTimer2 (void);		// interruption sur le Timer 2
void PCF_sec_raz (void);

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------- Sous-Prog D'interruption --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma interrupt InterruptTimer2
void InterruptTimer2 (void)
{  
	T2CONbits.TMR2ON = 0; 			// Timer 2 off
	
	// tempo pour faire une seconde pile
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); 
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop();

    // compensation de la dérive du quartz
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //- moins 2 linges (trop lent) 12/12/01
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    
	PIR1bits.TMR2IF = 0;			// RAZ du Timer
	T2CONbits.TMR2ON = 1; 			// Timer 2 on
	
	if ((CntTmr == 10) || (CntTmr == 37)) HEURE = !HEURE;
	    
	CntTmr++;
	if (CntTmr > 55) 
	{
    	CntTmr = 0;
	    Sec++;

        if (Sec > 59) 
        {
            Sec = 0;
            Min++;
            if (Min > 59)
            {
                Min = 0;
                Hrs++;
                if (Hrs > 23)
                {
                    Hrs = 0;
                    Day++;
                    if (Day > 31)
                    {
                        Day = 1;
                        Mth++;
                        DS1307_GetTime();
                    }    
                }
            }
        } 
    }   
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- High priority interrupt vector -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma code VectorHigh = 0x08
void InterruptVectorHigh(void)
{
	_asm goto InterruptTimer2 _endasm
}
#pragma code


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------------------- Main Program -------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{    
//--------------------------- Initialisation du PIC ---------------------------
	TRISA = 0b00010011;			// RA3,4,5 en entrée (switches) + RA4!!
	TRISB = 0x01;				// PORTB en sortie
	TRISC = 0x02;				// SCl et SDA en entrée
	ADCON1 = 0x07;				// PORTA en I/O Numériques
	I2C_Init (100000);			// 100kHz @ Fosc=16MHz
//----------------- Configuration de l'interruption TIMER 2 -------------------
	PR2 = 250;					// Valeur de debordement du Timer 2
	CntTmr = 0;					// 1s = 100x250x10x16x0.25us
	T2CONbits.TOUTPS3 = 1;		// Postscaler is 1:10
	T2CONbits.TOUTPS2 = 0;
	T2CONbits.TOUTPS1 = 1;
	T2CONbits.TOUTPS0 = 0;
	T2CONbits.T2CKPS1 = 1;		// Prescaler is 16
	T2CONbits.T2CKPS0 = 1;
	T2CONbits.TMR2ON = 1; 		// Timer 2 on
	PIE1bits.TMR2IE = 1;		// Enabled Timer 2 interrupt
	RCONbits.IPEN = 1; 			// Interruption prioritaires activées
	INTCONbits.GIE = 1;			// Enabled interrupts
//------------------------------- RTC Configuration ---------------------------
	//DS1307_Init();
	//DS1307_SetTime(); 
	DS1307_GetTime();
//-----------------------------------------------------------------------------
    Delay_ms (50);
	DATE = 0;
	THERMO = 0;
	HEURE = 1;
    PCF8574_Write (0x70, Seg[11]);
    PCF8574_Write (0x72, Seg[11]);
    PCF8574_Write (0x74, Seg[11]);
    PCF8574_Write (0x76, Seg[11]);
    PCF_sec_raz();
    Delay_ms (50);
//-----------------------------------------------------------------------------	
	while (1)
	{
    	// display hour
    	if (select_display == 0)
    	{
        	Dec2BCD (Hrs);
        	
        	// afficheur éteint si dizaines nulles
        	if (Tens==0) PCF8574_Write (0x70, Seg[12]);
            else         PCF8574_Write (0x70, Seg[Tens]);
                
            PCF8574_Write (0x72, Seg[Ones]);
            Dec2BCD (Min);
			PCF8574_Write (0x74, Seg[Tens]);
            PCF8574_Write (0x76, Seg[Ones]);
        }

        // allumage des led pour les minutes impaires, extinction pour les paires
        if (Min % 2)
            PCF8574_Write((((Sec >> 3) << 1) + 0x40), on[Sec%8]);
        else
            PCF8574_Write((((Sec >> 3) << 1) + 0x40), off[Sec%8]);

        /*// display date
        else if (select_display == 1) 
        {
            HEURE=0;  DATE=1; THERMO=1;
        	Dec2BCD (Day);
            PCF8574_Write (0x70, Seg[Tens]);
            PCF8574_Write (0x72, Seg[Ones]);
            Dec2BCD (Mth);
            PCF8574_Write (0x74, Seg[Tens]);
            PCF8574_Write (0x76, Seg[Ones]);
        }      
        // display temperature
        else if (select_display == 2) 
        {
           	// lecture de la temperature
    	    //if ((CntTmr == 10) | (CntTmr == 20))
    	    DS1621_Read_Temp (0x90);
            HEURE=0;  DATE=0; THERMO=1;
        	Dec2BCD (TempH-5);
            PCF8574_Write (0x70, Seg[Tens]);
            PCF8574_Write (0x72, Seg[Ones]);
            PCF8574_Write (0x74, Seg[5]);
            PCF8574_Write (0x76, Seg[10]);
        }  */
    }
}


void PCF_sec_raz (void)
{
    PCF8574_Write (0x40, 0xFF);
	PCF8574_Write (0x42, 0xFF);
	PCF8574_Write (0x44, 0xFF);
	PCF8574_Write (0x46, 0xFF);
	PCF8574_Write (0x48, 0xFF);
	PCF8574_Write (0x4A, 0xFF);
	PCF8574_Write (0x4C, 0xFF);
	PCF8574_Write (0x4E, 0xFF);
}