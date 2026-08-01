//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                       Titre   :   Horloge à LED                       &&&
//&&&                       Auteur  :   Pierre Blaché                       &&&
//&&&                       Date    :   Juin 2012                           &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "p18CXXX.h"
#include "i2c.h"
#include "math.h"
#include "delays.h"
#include "ds1621.h"
#include "ds1307.h"
#include "pcf8574.h"
#include "main.h"
#include "misc.h"

    
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//----------------------- Configuration du Processeur -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma config WDT = OFF        // Watchdog OFF
#pragma config OSC = HS         // Quartz 10MHz
#pragma config LVP = OFF        // Low Power Prog OFF


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------ Déclaration des constantes -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define BAUDS   100000          // frequence de l'I2C (100kHz)
#define FOSC    16000000        // frequence du quartz (16MHz)

#define DATE    PORTAbits.RA2   // affichage de la date
#define HEURE   PORTAbits.RA3   // affichage de l'heure
#define THERMO  PORTAbits.RA5   // affichage de la temperature

#define SW_SEL  PORTCbits.RC1   // bouton 1 (selection)
#define SW_M    PORTAbits.RA1   // bouton 2 (decrementation)
#define SW_P    PORTAbits.RA0   // bouton 3 (incrementation)

#define SCL     PORTCbits.RC3   // horloge du bus I2C
#define SDA     PORTCbits.RC4   // données du bus I2C

#define HERTZ   PORTBbits.RB0   // entrée 1 Hz provenant de la RTC (inutilisée)

#define PWM     PORTCbits.RC2   // PWM de commande tension LED

#define NOP10   Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
#define NOP50   NOP10; NOP10; NOP10; NOP10; NOP10; 

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------ Déclaration des variables --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
u8 cnt_timer = 0;
u8 select_display=0;
u8 Seg [13] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10, 0x1C, 0x3F, 0xFF};
u8 on   [8] = {0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00};
u8 off  [8] = {0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
t_time time;
u8 pcf_sec;


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------- Sous-Prog D'interruption --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#pragma interrupt InterruptTimer2
void InterruptTimer2 ()
{  
    T2CONbits.TMR2ON = 0;           // Timer 2 off
    
    // tempo pour faire une seconde pile
    NOP50; NOP50; NOP50; NOP50; NOP50; 
    NOP50; NOP50; NOP50; NOP50;
    Nop(); Nop(); Nop(); Nop();

    // compensation de la dérive du quartz
    Nop(); Nop(); //Nop(); Nop(); //Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //- moins 2 linges (trop lent) 12/12/01
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    //Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    
    PIR1bits.TMR2IF = 0;            // RAZ du Timer
    T2CONbits.TMR2ON = 1;           // Timer 2 on
    
    if ((cnt_timer == 10) || (cnt_timer == 37)) HEURE = !HEURE;
        
    cnt_timer++;
    if (cnt_timer > 55) 
    {
        cnt_timer = 0;
        time.sec++;

        if (time.sec > 59) 
        {
            time.sec = 0;
            time.min++;
            if (time.min > 59)
            {
                time.min = 0;
                time.hrs++;
                if (time.hrs > 23)
                {
                    time.hrs = 0;
                    time.day++;
                    if (time.day > 31)
                    {
                        time.day = 1;
                        time.mth++;
                        //ds1307_get_time(&time);
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
    u16 sel_sw = 0;
    u8 en_disp_hrs = 1;
    u8 en_disp_min = 1;
    u8 bcd[5];
    time.hrs =  0;
    time.min = 16;
    time.sec =  0;
    time.dow =  1;
    time.day =  2;
    time.mth = 12;
    time.yrs = 13;
//--------------------------- Initialisation du PIC ---------------------------
    TRISA = 0b00010011;         // RA3,4,5 en entrée (switches) + RA4!!
    TRISB = 0x01;               // PORTB en sortie
    TRISC = 0x02;               // SCl et SDA en entrée
    ADCON1 = 0x07;              // PORTA en I/O Numériques
    i2c1_init(I2C_FREQ, I2C_MASTER, I2C_DIS_IT_MASTER, I2C_DIS_IT_SLAVE);
//----------------- Configuration de l'interruption TIMER 2 -------------------
    PR2 = 250;                  // Valeur de debordement du Timer 2
    cnt_timer = 0;              // 1s = 100x250x10x16x0.25us
    T2CONbits.TOUTPS3 = 1;      // Postscaler is 1:10
    T2CONbits.TOUTPS2 = 0;
    T2CONbits.TOUTPS1 = 1;
    T2CONbits.TOUTPS0 = 0;
    T2CONbits.T2CKPS1 = 1;      // Prescaler is 16
    T2CONbits.T2CKPS0 = 1;
    T2CONbits.TMR2ON = 1;       // Timer 2 on
    PIE1bits.TMR2IE = 1;        // Enabled Timer 2 interrupt
    RCONbits.IPEN = 1;          // Interruption prioritaires activées
    INTCONbits.GIE = 1;         // Enabled interrupts
//------------------------------- RTC Configuration ---------------------------
    //ds1307_init();
    //ds1307_set_time(time);
    //ds1307_get_time(&time);
//-----------------------------------------------------------------------------
    delay_ms (50);
    DATE = 0;
    THERMO = 0;
    HEURE = 1;
    pcf8574_write_port (I2C_ADR_PCF8574A+0, Seg[11]);
    pcf8574_write_port (I2C_ADR_PCF8574A+1, Seg[11]);
    pcf8574_write_port (I2C_ADR_PCF8574A+2, Seg[11]);
    pcf8574_write_port (I2C_ADR_PCF8574A+3, Seg[11]);
    pcf7485_sec_raz();
    delay_ms (50);
//----------------------------------------------------------------------------- 
    while (1)
    {
        // selection button
        if (!SW_SEL)
        {
            delay_ms(100);
            if (!SW_SEL)
            {
                sel_sw++;
                if (sel_sw >= 3)
                    sel_sw = 0;
            }   
        }   
        
        // decrement button
        if (!SW_M)
        {
            delay_ms(100);
            if (!SW_M)
            {
                if (sel_sw == 1) time.min--;
                if (sel_sw == 2) time.hrs--;
                if (time.min >= 60) {time.min = 59; time.hrs--;}
                if (time.hrs >= 24) {time.hrs = 23;}
            }
        }        
            
        // increment button
        if (!SW_P)
        {
            delay_ms(100);
            if (!SW_P)
            {
                if (sel_sw == 1) time.min++;
                if (sel_sw == 2) time.hrs++;
                if (time.min >= 60) {time.min = 0; time.hrs++;}
                if (time.hrs >= 24) {time.hrs = 0;}
            }
        }       
        
       if (sel_sw == 1){
           en_disp_hrs = 0;
           en_disp_min = 1;
       }
       else if (sel_sw == 2){
           en_disp_hrs = 1;
           en_disp_min = 0;
       }    
       else{
            en_disp_hrs = 1;
            en_disp_min = 1;
       }    
        
        // display hour
        if (select_display == 0)
        {
            dec_2_bcd ((u16)time.hrs, bcd);
            
            if (en_disp_hrs){
                // afficheur éteint si dizaines nulles
                if (bcd[1]==0) pcf8574_write_port (I2C_ADR_PCF8574A, Seg[12]);
                else           pcf8574_write_port (I2C_ADR_PCF8574A, Seg[bcd[1]]);
                    
                pcf8574_write_port (I2C_ADR_PCF8574A+1, Seg[bcd[0]]);
            }
            else{
                pcf8574_write_port (I2C_ADR_PCF8574A+0, 0xFF);
                pcf8574_write_port (I2C_ADR_PCF8574A+1, 0xFF);
            }    
            
            if (en_disp_min){
                dec_2_bcd ((u16)time.min, bcd);
                pcf8574_write_port (I2C_ADR_PCF8574A+2, Seg[bcd[1]]);
                pcf8574_write_port (I2C_ADR_PCF8574A+3, Seg[bcd[0]]);
            }
            else{
                pcf8574_write_port (I2C_ADR_PCF8574A+2, 0xFF);
                pcf8574_write_port (I2C_ADR_PCF8574A+3, 0xFF);
            }    
        }

        // allumage des led pour les minutes impaires, extinction pour les paires
        // >> 3 pour faire (1, 2, 3, 4...)
        // << 1 pour faire (2, 4, 6, 8...)
        // + 0x20 pour faire (0x20, 0x21, 0x22, 0x23)
        if (time.min % 2)
            pcf8574_write_port(((time.sec >> 3) + I2C_ADR_PCF8574), on[time.sec%8]);
        else
            pcf8574_write_port(((time.sec >> 3) + I2C_ADR_PCF8574), off[time.sec%8]);

        /*// display date
        else if (select_display == 1) 
        {
            HEURE=0;  DATE=1; THERMO=1;
            dec_2_bcd (Day);
            pcf8574_write_port (0x70, Seg[Tens]);
            pcf8574_write_port (0x72, Seg[Ones]);
            Dec2BCD (Mth);
            pcf8574_write_port (0x74, Seg[Tens]);
            pcf8574_write_port (0x76, Seg[Ones]);
        }      
        // display temperature
        else if (select_display == 2) 
        {
            // lecture de la temperature
            //if ((CntTmr == 10) | (CntTmr == 20))
            DS1621_Read_Temp (0x90);
            HEURE=0;  DATE=0; THERMO=1;
            dec_2_bcd (TempH-5);
            pcf8574_write_port (0x70, Seg[Tens]);
            pcf8574_write_port (0x72, Seg[Ones]);
            pcf8574_write_port (0x74, Seg[5]);
            pcf8574_write_port (0x76, Seg[10]);
        }  */
    }
}


void pcf7485_sec_raz ()
{
    u8 i;
    u8 nb = (time.sec >> 3);
    u8 rest = time.sec - 8 * nb;
    
    if (time.min % 2 == 0)  // paire = led off
    {
        for(i = 0; i < 8; i++)
            pcf8574_write_port (i + I2C_ADR_PCF8574, 0x00);  // led off
            
        for(i = 0; i < nb; i++)
            pcf8574_write_port (i + I2C_ADR_PCF8574, 0xFF);

        pcf8574_write_port (i + I2C_ADR_PCF8574, off[rest-1]);
    } 
    else
    {
        for(i = 0; i < 8; i++)
            pcf8574_write_port (i + I2C_ADR_PCF8574, 0xFF);

        for(i = 0; i < nb; i++)
            pcf8574_write_port (i + I2C_ADR_PCF8574, 0x00);

        pcf8574_write_port (i + I2C_ADR_PCF8574, on[rest-1]);
    } 
}
