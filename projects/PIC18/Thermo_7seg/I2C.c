//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&					Titre 	: 	Routines I2C					&&&
//&&&					Auteur 	: 	Pierre Blaché					&&&
//&&&					Date 	: 	Janvier 2008					&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"
#include "I2C.h"

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------- Initialisation du bus I2C -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// @ 20 MHz : 100kHz -> Freq = 49
//			  400kHz -> Freq = 12
// @ 16 MHz : 100kHz -> Freq = 39
//			  400kHz -> Freq = 9
void I2C_Init(unsigned char Freq) 
{
	TRISCbits.TRISC3=1;	
	TRISCbits.TRISC4=1;	
	SSPCON1 = 0x28;				// set I2C master mode
	SSPCON2 = 0x00;					
	SSPADD = Freq;
	SSPSTATbits.SMP = 1;
}
	

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Envoi du Start-Condition -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2C_Start(void) 
{
	SSPSTATbits.CKE = 1;
	SSPCON2bits.SEN = 1;
	while (SSPCON2bits.SEN);
	PIR1bits.SSPIF = 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------- Envoi du Reapeted Start-Condition -------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2C_Rstart(void) 
{
	SSPSTATbits.CKE = 1;
	SSPCON2bits.RSEN = 1;
	while (SSPCON2bits.RSEN);
	PIR1bits.SSPIF = 0;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Envoi du Not Acknowledge -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2C_Nack(unsigned char Ack) 
{
	SSPCON2bits.ACKEN = 1;			// envoi du Nack
	SSPCON2bits.ACKDT = Ack;					
	while (!PIR1bits.SSPIF);		// attendre que SSPIF=1
	PIR1bits.SSPIF = 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Reception du Acknowledge -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2C_Ack(void) 
{
	while (SSPSTATbits.R_W);		// fin de la transmission
	while (SSPCON2bits.ACKSTAT);	// boucler jusqu'à reception du ACK
	PIR1bits.SSPIF = 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- Lecture du bus I2C ---------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int I2C_Read(void)
{
	SSPCON2bits.RCEN = 1;
	while (!PIR1bits.SSPIF);		// attendre que SSPIF=1
	PIR1bits.SSPIF = 0;
	return(SSPBUF);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Ecriture sur le bus I2C ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2C_Write(unsigned char i2cWriteData)
{
	SSPBUF = i2cWriteData;
	PIR1bits.SSPIF = 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Envoi du Stop-Condition ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void I2C_Stop(void)
{		
	SSPCON2bits.PEN = 1;
	while (SSPCON2bits.PEN)
	PIR1bits.SSPIF = 0;
}