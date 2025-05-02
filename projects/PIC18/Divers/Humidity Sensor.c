//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Titre   :   Capteur D'humidité          &&&
//&&&               Auteur  :   Pierre Blaché               &&&
//&&&               Date    :   Juillet 2008                &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"
#include "SousProg.h"           // LCD & Tempos
#include "I2C.h"

#define LED             PORTAbits.RA2
#define SDA             PORTCbits.RC1
#define SCK             PORTCbits.RC0
#define STATUS_REG_W    0x06    //000 0011 0    adr cmd wr
#define STATUS_REG_R    0x07    //000 0011 1
#define MEASURE_TEMP    0x03    //000 0001 1
#define MEASURE_HUMI    0x05    //000 0010 1
#define RESET           0x1e    //000 1111 0

unsigned char Ones, Tens, Hund; // Conv Bin vers BCD
unsigned char Temp1, Temp2;

char SensorWr (unsigned char value);
char SensorRd (unsigned char ack);
void Cal_TH (float *p_humi ,float *p_temp);
void Measure (unsigned char *p_value, unsigned char *p_checksum, unsigned char mode);
void DS1621 (void);
void SensorStart (void);
char SensorSoftRst (void);
void SensorComRst (void);
char SensorRegWr (unsigned char *p_value);
char SensorRegRd (unsigned char *p_value, unsigned char *p_checksum);

typedef union
{
    unsigned int i;
    float f;
} value;


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Main Program ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{
    value Humi_Val, Temp_Val;
    unsigned char Checksum;
//------------------ Initialisation du PIC --------------------
    TRISA=0;                    // PORTA en sortie
    TRISB=0;                    //
    TRISC=0;                    //
    TRISD=0;                    //
    ADCON1=7;                   // PORTA en I/O Numériques
    LCD_Init ();                // 4 bit en 2 lignes 5x8
    I2C_Init (49);              // 100kHz

    while (1)
    {
        LED = !LED;
        Measure ((unsigned char*) &Humi_Val.i, & Checksum, 1);
        Measure ((unsigned char*) &Temp_Val.i, & Checksum, 0);
        Humi_Val.f = (float)Humi_Val.i;
        Temp_Val.f = (float)Temp_Val.i;
        Cal_TH (&Humi_Val.f, &Humi_Val.f);
        DS1621();
//------------------ Affichage des Données --------------------
        WrLCD (0x80, 0);
        WrLCD ('H', 1);
        WrLCD ('u', 1);
        WrLCD ('m', 1);
        WrLCD ('i', 1);
        WrLCD ('d', 1);
        WrLCD ('i', 1);
        WrLCD ('t', 1);
        WrLCD ('e', 1);
        WrLCD (' ', 1);
        Bin2BCD (Humi_Val.f);
        WrLCD (Hund+0x30, 1);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);
        WrLCD ('%', 1);

        WrLCD (0xC0, 0);
        WrLCD ('T', 1);
        WrLCD ('e', 1);
        WrLCD ('m', 1);
        WrLCD ('p', 1);
        WrLCD ('e', 1);
        WrLCD ('r', 1);
        WrLCD ('a', 1);
        WrLCD ('t', 1);
        WrLCD (' ', 1);
        Bin2BCD (Temp_Val.f);
        WrLCD (Hund+0x30, 1);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);
        WrLCD (' ', 1);
        Bin2BCD (Temp1);
        WrLCD (Hund+0x30, 1);
        WrLCD (Tens+0x30, 1);
        WrLCD (Ones+0x30, 1);
//      WrLCD (0xDF, 1);
//      WrLCD ('C', 1);
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Ecriture Capteur ----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
char SensorWr(unsigned char value)
{
    unsigned char i, error=0;

    for (i=0x80; i>0; i/=2)     //shift bit for masking
    {
        if (i & value)
            SDA=1; //masking value with i , write to SENSI-BUS
        else
            SDA=0;
        SCK=1;                  //clk for SENSI-BUS
        _asm nop nop nop nop nop _endasm;
        SCK=0;
    }
    SDA=1;                      //release DATA-line
    SCK=1;                      //clk #9 for ack
    error=SDA;                  //check ack (DATA will be pulled down by SHT11)
    SCK=0;
    return error;               //error=1 in case of no acknowledge
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------------- Lecture Capteur ----------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
char SensorRd(unsigned char ack)
{
    unsigned char i, val=0;
    SDA=1;                      //release DATA-line
    TRISCbits.TRISC1=1;
    for (i=0x80; i>0; i/=2)     //shift bit for masking
    {
        SCK=1;                  //clk for SENSI-BUS
        if (SDA) val=(val | i); //read bit
        SCK=0;
    }
    TRISCbits.TRISC1=0;
    SDA=!ack;                   //in case of "ack==1" pull down DATA-Line
    SCK=1;                      //clk #9 for ack
    _asm nop nop nop nop nop _endasm;
    SCK=0;
    SDA=1;                      //release DATA-line
    return val;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------- Envoi du bit de Start au Capteur --------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void SensorStart(void)
{
    SDA=1; SCK=0;                   // Initial state
    _asm nop _endasm;
    SCK=1;
    _asm nop _endasm;
    SDA=0;
    _asm nop _endasm;
    SCK=0;
    _asm nop nop nop _endasm;
    SCK=1;
    _asm nop _endasm;
    SDA=1;
    _asm nop _endasm;
    SCK=0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------- Reset de la communication du Capteur ------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void SensorComRst(void)
{
    unsigned char i;
    SDA=1; SCK=0;               // Initial state
    for(i=0; i<9; i++)          // 9 SCK cycles
    {
        SCK=1;
        SCK=0;
    }
    SensorStart();              // transmission start
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------- Reset du Capteur par le soft -----------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
char SensorSoftRst(void)
{
    unsigned char error=0;
    SensorComRst();             //reset communication
    error += SensorWr (RESET);  //send RESET-command to sensor
    return error;               //error=1 in case of no response
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------- Lecture du registre Status ------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
char SensorRegRd (unsigned char *p_value, unsigned char *p_checksum)
{
    unsigned char error=0;
    SensorStart();                  //transmission start
    error = SensorWr (STATUS_REG_R);//send command to sensor
    *p_value = SensorRd(1);         //read status register (8-bit) (ack)
    *p_checksum = SensorRd (0);     //read checksum (8-bit) (noack
    return error;                   //error=1 in case of no response
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------- Ecriture du registre Status -----------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
char SensorRegWr (unsigned char *p_value)
{
    unsigned char error=0;
    SensorStart();                  //transmission start
    error += SensorWr (STATUS_REG_W);//send command to sensor
    error += SensorWr (*p_value);   //send value of status register
    return error;                   //error>=1 in case of no response
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------ Humidity & Temperature Calculation -------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Cal_TH(float *p_humi ,float *p_temp)
{
    const float C1=-4.0;        // for 12 Bit
    const float C2= 0.0405;     // for 12 Bit
    const float C3=-0.0000028;  // for 12 Bit
    const float T1=0.01;        // for 14 Bit @ 5V
    const float T2=0.00008;     // for 14 Bit @ 5V
    float rh=*p_humi;           // rh: Humidity [Ticks] 12 Bit
    float t=*p_temp;            // t: Temperature [Ticks] 14 Bit
    float rh_lin;               // rh_lin: Humidity linear
    float rh_true;              // rh_true: Temperature compensated humidity
    float t_C;                  // t_C : Temperature [°C]

    t_C = t*0.01 - 40;              //calc. Temperature from ticks to [°C]
    rh_lin = C3*rh*rh + C2*rh + C1; //calc. Humidity from ticks to [%RH]
    rh_true = (t_C-25)*(T1+T2*rh)+rh_lin; //calc. Temperature compensated humidity [%RH]
    if(rh_true>100)rh_true = 100;   //cut if the value is outside of
    if(rh_true<0.1)rh_true = 0.1;   //the physical possible range
    *p_temp = t_C;                  //return temperature [°C]
    *p_humi = rh_true;              //return humidity[%RH]
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------- Lectures des Données --------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void Measure(unsigned char *p_value, unsigned char *p_checksum, unsigned char mode)
{
    unsigned int i;

    I2CStart();                 //transmission start
    switch(mode)
    {                           //send command to sensor
        case 0 : SensorWr (MEASURE_TEMP); break;    // demande temp
        case 1 : SensorWr (MEASURE_HUMI); break;    // demande humi
        default : break;
    }

    Delay_ms(100);              //wait until sensor has finished the measurement
    *(p_value) = SensorRd(0);   //read the first byte (MSB)
    *(p_value+1)= SensorRd(0);  //read the second byte (LSB)
    *p_checksum = SensorRd(1);  //read checksum
}

