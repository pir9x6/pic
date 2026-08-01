//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   Afficheur LCD                       &&&
//&&&                   Fichier     :   LCD_320x240.h                       &&&
//&&&                   Description :   prototypes des Fonctions LCD        &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Pierre BLACHÉ                       &&&
//&&&                   Date        :   Avril 2011                          &&&
//&&&                   Version     :   2.0                                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                                                                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Fichiers Requis :   LCD_320x240.c                       &&&
//&&&                                   LCD_320x240.h                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p33Fxxxx.h"
#include "Delays.h"
#include "Caracteres.h"
#include "Constantes.h"
#include "LCD_320x240.h"

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- Initialisation de l'afficheur ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void LCD_Init(void)
{

    LCD_Rst = 1;
    Delay_ms(5);
    LCD_Rst = 0;
    Delay_ms(10);
    LCD_Rst = 1;
    Delay_ms(20);

    //  VENDOR
    LCD_Write(0x0046,0x00A4);
    LCD_Write(0x0047,0x0053);
    LCD_Write(0x0048,0x0000);
    LCD_Write(0x0049,0x0044);
    LCD_Write(0x004a,0x0004);
    LCD_Write(0x004b,0x0067);
    LCD_Write(0x004c,0x0033);
    LCD_Write(0x004d,0x0077);
    LCD_Write(0x004e,0x0012);
    LCD_Write(0x004f,0x004C);
    LCD_Write(0x0050,0x0046);
    LCD_Write(0x0051,0x0044);

    //240x320 window setting
    LCD_Write(0x0002,0x0000); // Column address start2
    LCD_Write(0x0003,0x0000); // Column address start1
    LCD_Write(0x0004,0x0000); // Column address end2
    LCD_Write(0x0005,0x00ef); // Column address end1
    LCD_Write(0x0006,0x0000); // Row address start2
    LCD_Write(0x0007,0x0000); // Row address start1
    LCD_Write(0x0008,0x0001); // Row address end2
    LCD_Write(0x0009,0x003f); // Row address end1

    // Display Setting
    LCD_Write(0x0001,0x0006); // IDMON=0, INVON=1, NORON=1, PTLON=0
    LCD_Write(0x0016,0x00C8); // MY=0, MX=0, MV=0, ML=1, BGR=0, TEON=0   0048
    LCD_Write(0x0023,0x0095); // N_DC=1001 0101
    LCD_Write(0x0024,0x0095); // PI_DC=1001 0101
    LCD_Write(0x0025,0x00FF); // I_DC=1111 1111

    LCD_Write(0x0027,0x0002); // N_BP=0000 0010
    LCD_Write(0x0028,0x0002); // N_FP=0000 0010
    LCD_Write(0x0029,0x0002); // PI_BP=0000 0010
    LCD_Write(0x002a,0x0002); // PI_FP=0000 0010
    LCD_Write(0x002C,0x0002); // I_BP=0000 0010
    LCD_Write(0x002d,0x0002); // I_FP=0000 0010

    LCD_Write(0x003a,0x0001); // N_RTN=0000, N_NW=001    0001
    LCD_Write(0x003b,0x0000); // P_RTN=0000, P_NW=001
    LCD_Write(0x003c,0x00f0); // I_RTN=1111, I_NW=000
    LCD_Write(0x003d,0x0000); // DIV=00
    Delay_ms(1);
    LCD_Write(0x0035,0x0038); // EQS=38h
    LCD_Write(0x0036,0x0078); // EQP=78h
    LCD_Write(0x003E,0x0038); // SON=38h
    LCD_Write(0x0040,0x000F); // GDON=0Fh
    LCD_Write(0x0041,0x00F0); // GDOFF

    // Power Supply Setting
    LCD_Write(0x0019,0x0049); // CADJ=0100, CUADJ=100, OSD_EN=1 ,60Hz
    LCD_Write(0x0093,0x000F); // RADJ=1111, 100%
    Delay_ms(1);
    LCD_Write(0x0020,0x0040); // BT=0100
    LCD_Write(0x001D,0x0007); // VC1=111   0007
    LCD_Write(0x001E,0x0000); // VC3=000
    LCD_Write(0x001F,0x0004); // VRH=0011

    //VCOM SETTING
    LCD_Write(0x0044,0x004D); // VCM=101 0000  4D
    LCD_Write(0x0045,0x000E); // VDV=1 0001   0011
    Delay_ms(1);
    LCD_Write(0x001C,0x0004); // AP=100
    Delay_ms(2);

    LCD_Write(0x001B,0x0018); // GASENB=0, PON=0, DK=1, XDK=0, VLCD_TRI=0, STB=0
    Delay_ms(1);
    LCD_Write(0x001B,0x0010); // GASENB=0, PON=1, DK=0, XDK=0, VLCD_TRI=0, STB=0
    Delay_ms(1);
    LCD_Write(0x0043,0x0080); //set VCOMG=1
    Delay_ms(2);

    // Display ON Setting
    LCD_Write(0x0090,0x007F); // SAP=0111 1111
    LCD_Write(0x0026,0x0004); //GON=0, DTE=0, D=01
    Delay_ms(1);
    LCD_Write(0x0026,0x0024); //GON=1, DTE=0, D=01
    LCD_Write(0x0026,0x002C); //GON=1, DTE=0, D=11
    Delay_ms(1);
    LCD_Write(0x0026,0x003C); //GON=1, DTE=1, D=11

    // INTERNAL REGISTER SETTING
    LCD_Write(0x0057,0x0002); // TEST_Mode=1: into TEST mode
    LCD_Write(0x0095,0x0001); // SET DISPLAY CLOCK AND PUMPING CLOCK TO SYNCHRONIZE
    LCD_Write(0x0057,0x0000); // TEST_Mode=0: exit TEST mode

    //LCD_Write(0x0021,0x0000);
    LCD_Write_Cmd(0x0022);

}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Envoi d'une adresse à l'afficheur ----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void LCD_Adresse(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
    LCD_Write(0x0002, x1>>8);   // Column address start2
    LCD_Write(0x0003, x1);      // Column address start1
    LCD_Write(0x0004, x2>>8);   // Column address end2
    LCD_Write(0x0005, x2);      // Column address end1
    LCD_Write(0x0006, y1>>8);   // Row address start2
    LCD_Write(0x0007, y1);      // Row address start1
    LCD_Write(0x0008, y2>>8);   // Row address end2
    LCD_Write(0x0009, y2);      // Row address end1
    LCD_Write_Cmd(0x0022);

}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------ Envoi d'une commande + une donnée à l'afficheur ----------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void LCD_Write(unsigned int Cmd, unsigned int Data)
{
   LCD_Write_Cmd(Cmd);
   LCD_Write_Data(Data);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------- Envoi d'une commande à l'afficheur ---------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void LCD_Write_Cmd(unsigned int Cmd)
{
    LCD_RS = 0;
    LCD_CS = 0;
    LCD_Data = Cmd;
    LCD_WR = 0;
    LCD_WR = 1;
    LCD_CS = 1;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------------- Envoi d'une couleur ----------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void LCD_Write_Color(unsigned char H,unsigned char L)
{
    LCD_RS = 1;
    LCD_CS = 0;
    LCD_Data = ((H << 8) & 0xFF00) | (L & 0x00FF);
    LCD_WR = 0;
    LCD_WR = 1;
    LCD_CS = 1;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------------- Envoi d'une donnée ----------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void LCD_Write_Data(unsigned int Data)
{
    LCD_RS = 1;
    LCD_CS = 0;
    LCD_Data = Data;
    LCD_WR = 0;
    LCD_WR = 1;
    LCD_CS = 1;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- Affichage d'un rectangle plein -----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void LCD_Draw_FillRectangle(unsigned int Color)
{
    unsigned int i,j;
    LCD_Adresse(0, 0, 239, 319);

    for(i=0; i<320; i++)
    {
        for (j=0; j<240; j++)
        {
            LCD_Write_Data(Color);
        }
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------ Afficher chaine caractere --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void showzifustr(unsigned int x, unsigned int y, unsigned char *str, unsigned int dcolor, unsigned int bgcolor)
{
    unsigned int x1, y1;
    x1 = x;
    y1 = y;
    while(*str!='\0')
    {
        showzifu(x1, y1, *str, dcolor, bgcolor);
        x1 += 7;
        str++;
    }
}

void showzifu(unsigned int x, unsigned int y, unsigned char value, unsigned int dcolor, unsigned int bgcolor)
{
    unsigned char i, j;
    unsigned char *temp = font;
    LCD_Adresse(x,y,x+7,y+11);
    temp += (value-32)*12;

    for(j=0;j<12;j++)
    {
        for(i=0;i<8;i++)
        {
            if((*temp&(1<<(7-i)))!=0)
            {
                LCD_Write_Data(dcolor);
            }
            else
            {
                LCD_Write_Data(bgcolor);
            }
        }
        temp++;
     }
}
