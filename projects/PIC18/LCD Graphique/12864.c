//*******************************
//*   Lcd graphique GDM12864A   *
//*     avec pic16F876/04p      * 
//* Etude réaliser par Angeliz  *
//*       le 11 04 2002         *
//*******************************

#include <p18CXXX.h>
//#include "font5x7.c"
#pragma config WDT = OFF		// Watchdog OFF
#pragma config OSC = HS			// Quartz 20MHz
#pragma config LVP = OFF		// Low Power Prog OFF

#define LCD_E 	PORTCbits.RC7
#define LCD_RW 	PORTCbits.RC6
#define LCD_RS 	PORTCbits.RC5
#define LCD_CS1 PORTCbits.RC4
#define LCD_CS2 PORTCbits.RC3
#define LCD_RST PORTCbits.RC2

const char display[770]={

  /* partie gauche du lcd */

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80,
  0x60,0x18,6,1,1,6,0x18,0x60,
  0x80,0,0,0,0,0,0,0xC0,
  0,0x80,0x40,0x40,0x80,0,0,0,
  0,0,0,0,0x80,0x40,0x40,0x40,

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0xE0,0x18,6,3,
  2,2,2,2,2,2,2,2,
  3,6,0x18,0xE0,0,0,0,0xFF,
  1,0,0,0,0,1,0xFE,0,
  0,0,0x1E,0x21,0x40,0x80,0x88,0x88,

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0xFF,0x80,0x80,
  0x80,0x80,0,0,0,0x38,0x44,0x82,
  0x82,0x82,0,0,0,0xFE,0x82,0x82,
  0x44,0x38,0,0,0,0,0,0,
  0x38,0x44,0x82,0x92,0x72,0,0,0,
  0xFE,0x82,0x82,0x44,0x38,0,0,0,

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

  /* partie droite du lcd */

  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

  0x40,0,0,0,0,0,0,0x80,
  0x40,0x40,0x40,0x40,0x80,0,0,0,
  0xC0,0,0,0,0,0,0,0,
  4,0xCE,4,0,0,0x80,0x40,0x40,
  0x40,0x40,0x40,0x40,0x80,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,   

  0x48,0x30,0,0,0,0x1E,0x25,0x44,
  0x84,0x84,0x84,0x80,0x40,0,0,0,
  0x3F,0x40,0x80,0x80,0x80,0x80,0,0,
  0,0xFF,0,0,0,0x40,0xA0,0x90,
  0x88,0x84,0x82,0x81,0x40,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,

  0xFE,0x0C,0x10,0x0C,0xFE,0,0,0,
  0,0,0x10,8,4,2,0xFE,0,
  0,0x44,0xA2,0x92,0x8A,0x84,0,0,
  0x6C,0x92,0x92,0x92,0x6C,0,0,0x60,
  0x98,0x94,0x92,0x62,0,0,0x10,0x18,
  0x14,0xF2,0x10,0,0,0xFC,0x12,0x12,
  0x12,0xFC,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  };

unsigned char x,y,cs;
int ptr;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------------- Delay ----------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Delay (unsigned int Cnt)
	{
	unsigned int x, y;
	for (x = Cnt; x != 0; x--)		// Boucle executée Cnt fois
		{
		for (y = 332; y != 0; y--);	// Boucle executée Cnt fois
		}
	}


 void LCD(char cVar)  // envoi de l'octet dans le port B
   {
   PORTD=cVar;        
   LCD_E=1;           // validation de l'octet 
   LCD_E=0;
	Delay (1);
   }



void main(void)
 {
   LCD_E=0;              // variable validation octet  
   LCD_RW=0;             // variable écriture  
   
   TRISB=0;
   TRISC=0;
   
	Delay (2);
   
   LCD_RST=0;            // reset
   LCD_RST=1;  
   ptr=0;                // pointeur diplay
   for(cs=0;cs<=1;cs++)
      {
      LCD_RS=0;          // envoi instruction
      if(cs==1)
            {
            LCD_CS1=0;   // selection chip gauche
            LCD_CS2=1;  
            }
         else
            {
            LCD_CS1=1;  // selection chip droite
            LCD_CS2=0; 
            }
      LCD(0x3F);        // lcd allumé
      LCD(0xB8);        // page 0
      LCD(0xC0);        // pointe vers 1 ligne afficheur
      
      for(x=0;x<=7;x++) 
         {
         LCD_RS=0;      // envoi instruction          
         LCD(0x40);     // colonne 0         
         LCD(0xB8 + x); // page ++
         LCD_RS=1;      // envoi caractère
         for(y=0;y<=63;y++)
            {
            LCD(display[ptr]);  
            ptr++;            
            }
         }     
     }
     LCD_CS1=0;  
     LCD_CS2=0;       
   }

