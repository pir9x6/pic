//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&					Titre 	: 	Thermomètre avec Aff 7 Seg		&&&
//&&&					Auteur 	: 	Pierre Blaché					&&&
//&&&					Date 	: 	Mai 2010						&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"
#include "I2C.h"
#include "math.h"

#pragma config WDT = OFF		// Watchdog OFF
#pragma config OSC = HS 		// Quartz 10MHz
#pragma config LVP = OFF		// Low Power Prog OFF

#define	Aff1	PORTCbits.RC0	// centaines/signe
#define	Aff2	PORTCbits.RC7	// dizaines
#define	Aff3	PORTCbits.RC6	// unités
#define	Aff4	PORTCbits.RC5	// dizièmes
#define N		50
#define	LED		PORTAbits.RA2

unsigned char i;
unsigned char ones=0, tens=0, hund=0, tenth=0;
signed char temp1=0, TempH=0;	// partie entiere de la température
signed char temp2=0, TempL=0;	// partie decimal de la température
unsigned char cmpt=0, cnt=0;
unsigned char tab[15]={		
0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 
0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000,
0b10111111, 0b11111111, 0b10000110, 0b10101111, 0b10000011};		// 0,1,2,3,4,5,6,7,8,9,-, ,E, r, o
float TEMP=0.00;

void Delay_ms (unsigned int Cnt);
void DS1621 (unsigned char Adress);
void Float2BCD (float data);

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------- Main Program ---------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{	float data;
//----------------------- Initialisation du PIC -----------------------
	TRISA=0;					// PORTA en sortie
	TRISB=0;					//  
	TRISC=0;
	ADCON1=0x0D;				// PORTA en I/O Numériques
	I2C_Init (24);				// 100kHz
	Delay_ms(10);
	DS1621 (0x90);				// acquisition de la temperature sur le DS1621
//---------------------------------------------------------------------
	for (i=0; i<100; i++)
	{
		Aff1=0; Aff2=1; Aff3=1; Aff4=1;		// affichage des centaines/signe -
		PORTB = tab[10];
		Delay_ms(2);
	
		Aff1=1; Aff2=0; Aff3=1; Aff4=1;		// affichage des dizaines
		PORTB = tab[10];
		Delay_ms(2);
	
		Aff1=1; Aff2=1; Aff3=0; Aff4=1;		// affichage des unités
		PORTB = tab[10];
		Delay_ms(2);
	
		Aff1=1; Aff2=1; Aff3=1; Aff4=0;		// affichage des dizièmes
		PORTB = tab[10];
		Delay_ms(2);
	}
//---------------------------------------------------------------------
	while (1)
	{
		DS1621 (0x90);			// acquisition de la temperature sur le DS1621
		
		if (cmpt < N)			// average sur N valeurs
		{
			cmpt++;
			if (temp2 == 0) TEMP += temp1;
			else TEMP += temp1 + 0.5;
		}
		else
		{
			cmpt=0;
			TEMP /= N;
			Float2BCD((char)fabs((float)TEMP));
			LED = !LED;
		}

		Aff1=0; Aff2=1; Aff3=1; Aff4=1;		// affichage des centaines/signe -
		if (temp1 < 0) PORTB = tab[10];		// on affiche le signe - ?
		else if (hund==0) PORTB = tab[11];	// si centaines = 0 alors on affiche rien
		else PORTB = tab[hund];				// sinon on affiche les centaines
		Delay_ms(2);

		Aff1=1; Aff2=0; Aff3=1; Aff4=1;		// affichage des dizaines
		PORTB = tab[tens];
		Delay_ms(2);

		Aff1=1; Aff2=1; Aff3=0; Aff4=1;		// affichage des unités
		PORTB = tab[ones];
		Delay_ms(2);

		Aff1=1; Aff2=1; Aff3=1; Aff4=0;		// affichage des dizièmes
		PORTB = tab[tenth];
		Delay_ms(2);
	}
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------- Lecture de la Temperature sur le DS1621 -----------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void DS1621 (unsigned char Adress)
{
	I2C_Start ();				// Start Condition
	I2C_Write (Adress+0);		// Adresse + bit Write
	I2C_Ack ();					// attente reception du Acknowledge
	I2C_Write (0xAC);			// Acces au registre de config.
	I2C_Ack ();					// attente reception du Acknowledge
	I2C_Write (0x00);			// Configurer le capteur
	I2C_Ack ();					// attente reception du Acknowledge
	I2C_Stop ();				// Stop Condition
	
	I2C_Start ();				// Start Condition
	I2C_Write (Adress+0);		// Adresse + bit Write
	I2C_Ack ();					// attente reception du Acknowledge
	I2C_Write (0xEE);			// Lancer la conversion
	I2C_Ack ();					// attente reception du Acknowledge
	I2C_Stop ();				// Stop Condition
	
	I2C_Start ();				// Start Condition
	I2C_Write (Adress+0);		// Adresse + bit Write
	I2C_Ack ();					// attente reception du Acknowledge
	I2C_Write (0xAA);			// Envoyer la commande "lire la temp"
	I2C_Ack ();					// attente reception du Acknowledge
	I2C_Rstart ();				// Repeated Start-condition
	I2C_Write (Adress+1);		// Adresse + bit Read
	I2C_Ack ();					// attente reception du Acknowledge
	temp1 = I2C_Read ();		// Recuperer le Msb
	I2C_Nack (0);				// envoi d'un ack
	temp2 = I2C_Read ();		// Recuperer le LSB
	I2C_Nack (1);				// envoi d'un no-ack
	I2C_Stop ();				// Stop Condition
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------- Conversion Binaire vers BCD ---------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Float2BCD (float data)
{
	ones=tens=hund=0; 
	while (data >= 100)	{data -= 100; hund++;}
	while (data >= 10)	{data -= 10; tens++;}
	while (data >= 1)	{data -= 1; ones++;}
	tenth = (char)(10*(fabs(TEMP) - hund*100 - tens*10 - ones*1));
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------------- Temporisations --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Delay_ms (unsigned int Cnt)
{
	unsigned int x, y;
	for (x = Cnt; x != 0; x--)		// Boucle executée Cnt fois
	{
		for (y = 332; y != 0; y--);	// 332 @ 20MHz
	}
}




