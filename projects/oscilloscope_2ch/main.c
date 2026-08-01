//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   Oscilloscope 40MHz 2 voies          &&&
//&&&                   Fichier     :   main.c                              &&&
//&&&                   Description :   Programme principal                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Pierre BLACHÉ                       &&&
//&&&                   Date        :   Juillet 2012                        &&&
//&&&                   Version     :   1.0                                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//-------------------------------- Constants ----------------------------------
#define VERSION     (u8)0x12
#define NB_CHANNELS 2
//#define DEBUG

//----------------------- Configuration du processeur -------------------------
_FOSCSEL(FNOSC_PRI)                 // Primary (XT, HS, EC) Oscillator
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & POSCMD_EC)   // Clock Switching is enabled, OSC2 as digital IO, HS oscillator
_FWDT(FWDTEN_OFF)                   // watchdog is off
_FICD(JTAGEN_OFF)                   // disable JTAG module
_FPOR(ALTI2C_OFF)                   // pin SDA & SCL

//----------------------------- Global Variables ------------------------------
u16 state=IDLE;                     // mode 0=idle, 1=acquisition, 2=transmit
u16 channel=0;
u16 N=1000;                         // Nombres d'échantillons à acquérir
u32 SampleDelay=50;                 // time to acquire N points
u8  io_port2;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
    //-------------------------- Local Variables -----------------------------
    u16 i;
    u8 sine4 [1000], sine16[1000], sine_am[1000];

#ifdef DEBUG
    s16 random = 0;
#endif
    
    //------------------- Configuration du MCU (21µs)--------------------------
    PLLFBD=30;                      // Fosc= 10M*32/(2*2)=80Mhz = 40MIPS
    CLKDIVbits.PLLPOST=0;           // N1=2
    CLKDIVbits.PLLPRE=0;            // N2=2
    OSCTUN=0;                       // Tune FRC oscillator, if FRC is used
    RCONbits.SWDTEN=0;              // Disable Watch Dog Timer
    __builtin_write_OSCCONH(3);     // Initiate Clock Switch to FRC with PLL (NOSC=1)
    __builtin_write_OSCCONL(1);     // Start clock switching
    while (OSCCONbits.COSC!=3);     // Oscillateur externe + PLL
    while (OSCCONbits.LOCK!=1);     // Wait for PLL to be locked
    
    //------------------------ IO configuration -------------------------------
    TRISA=0x0000;                   //
    TRISB=0b0101110011111111;       //
    AD1PCFGL=0xFFFF;                // PORTB en  digital I/O
    RPINR18bits.U1RXR=14;           // UART1 receive (RPINR18), RX sur la broche RB14
    RPOR7bits.RP15R=3;              // UART1, TX sur RB15 (U1TX=3)

    //--------------------------- Periph init ---------------------------------
    i2c1_init(I2C_FREQ, I2C_MASTER, I2C_DIS_IT_MASTER, I2C_DIS_IT_SLAVE);
    uart_init(UART_FREQ);
    max7311_init(0x00, 0x00);       // port 1 & 2 as output

    //---------------------------- Init Board ---------------------------------
    cy7c42x1_reset();

    for (i=0; i<N; i++)
    {
        sine4[i]   = (u8)(127.5 + 127.5 * sin( 4 * 3.14 * i / N));
        sine16[i]  = (u8)(127.5 + 127.5 * sin(16 * 3.14 * i / N));
        sine_am[i] = (u8)(127.5 + 127.5 * sin( 8 * 3.14 * i / N)) * sin(128 * 3.14 * i / N);
    }

    //-------------------------------------------------------------------------
    while (1)
    {
        switch (state)
        {
            //-----------------------------------------------------------------
            case IDLE :
            {
                channel = 0;
                break;
            }

            //-----------------------------------------------------------------
            case ACQUI :
            {
                //channel = 0;
                cy7c42x1_flush();
                delay_ms(1);

                PIN_FIFO_WR_ENn = 0;

                // wait for acquisition to be done
                if (SampleDelay >= 1000) delay_ms((u16)(SampleDelay / 1000));
                else                     delay_us((u16)(SampleDelay));

                PIN_FIFO_WR_ENn = 1;
                state = TRANSMIT;
                break;
            }

            //-----------------------------------------------------------------
            case TRANSMIT :
            {
                switch (channel)
                {
                    case 1 :
                    {
                        FIFO_OE_1_ON;
                        FIFO_RD_EN_1_ON;
                        for (i=0; i<N; i++)
                        {
                            #ifdef DEBUG
                            uart_write (sine_am[i]);
                            #else
                            cy7c42x1_do_read_clock();
                            uart_write (FIFO_DATA);
                            #endif
                        }
                        channel = 0;
                        FIFO_RD_EN_OFF;
                        FIFO_OE_OFF;

                        if (NB_CHANNELS == 1)
                            state = IDLE;

                        break;
                    }

                    case 2 :
                    {
                        FIFO_OE_2_ON;
                        FIFO_RD_EN_2_ON;
                        for (i=0; i<N; i++)
                        {
                            #ifdef DEBUG
                            random = (sine16[i] - rand()%10);
                            if (random > 255)
                                random = 255;
                            else if (random < 0)
                                random = 0;
                            uart_write ((u8)random);
                            #else
                            cy7c42x1_do_read_clock();
                            uart_write (FIFO_DATA);
                            #endif
                        }
                        channel = 0;
                        FIFO_RD_EN_OFF;
                        FIFO_OE_OFF;

                        if (NB_CHANNELS == 2)
                            state = IDLE;

                        break;
                    }
                    default :
                    {
                        break;
                    }
                }

                break;
            }

            default :
            {
                break;
            }
        }
    }
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------ UART Interrupt Sub Routine -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void uart_isr()
{
    switch (U1RXREG)            // recuperer commande venant du PC
    {
        // select channel to convert
        case '0' : channel = 0; break;
        case '1' : channel = 1; break;            // entrée 1
        case '2' : channel = 2; break;            // entrée 2
        case '3' : channel = 3; break;            // entrée 3
        case '4' : channel = 4; break;            // entrée 4

        // soft reset
        case '5' : asm("reset"); break;

        // detection of the dsPIC
        case '6' : uart_write_string ("DSO_g2_c2_v2"); break;

        // version
        case 'v' : uart_write_char(VERSION); break;

        // Mode de fonctionnement du dsPIC
        case '7' : state = IDLE;     break;           // ne rien faire
        case '8' : state = ACQUI;    break;           // envoyer les données vers le PC

        // changement du nombre d'échantillons
        case 'a' : N =   100; break;
        case 'b' : N =   200; break;
        case 'c' : N =   400; break;
        case 'd' : N =  1000; break;
        case 'e' : N = 10000; break;

        // changement de la fréquence d'échantillonnage
        case 'A' : io_port2 = (io_port2 & 0xE0) | 0x00;  N =  100; max7311_write_port2(io_port2);  SampleDelay=5;        break;        // 500ns/div
        case 'B' : io_port2 = (io_port2 & 0xE0) | 0x00;  N =  200; max7311_write_port2(io_port2);  SampleDelay=10;       break;        //   1µs/div
        case 'C' : io_port2 = (io_port2 & 0xE0) | 0x00;  N =  400; max7311_write_port2(io_port2);  SampleDelay=20;       break;        //   2µs/div
        case 'D' : io_port2 = (io_port2 & 0xE0) | 0x00;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=50;       break;        //   5µs/div
        case 'E' : io_port2 = (io_port2 & 0xE0) | 0x01;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=100;      break;        //  10µs/div
        case 'F' : io_port2 = (io_port2 & 0xE0) | 0x02;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=200;      break;        //  20µs/div
        case 'G' : io_port2 = (io_port2 & 0xE0) | 0x04;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=500;      break;        //  50µs/div
        case 'H' : io_port2 = (io_port2 & 0xE0) | 0x05;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=1000;     break;        // 100µs/div
        case 'I' : io_port2 = (io_port2 & 0xE0) | 0x06;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=2000;     break;        // 200µs/div
        case 'J' : io_port2 = (io_port2 & 0xE0) | 0x08;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=5000;     break;        // 500µs/div
        case 'K' : io_port2 = (io_port2 & 0xE0) | 0x09;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=10000;    break;        //   1ms/div
        case 'L' : io_port2 = (io_port2 & 0xE0) | 0x0A;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=20000;    break;        //   2ms/div
        case 'M' : io_port2 = (io_port2 & 0xE0) | 0x0C;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=50000;    break;        //   5ms/div
        case 'N' : io_port2 = (io_port2 & 0xE0) | 0x0D;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=100000;   break;        //  10ms/div
        case 'O' : io_port2 = (io_port2 & 0xE0) | 0x0E;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=200000;   break;        //  20ms/div
        case 'P' : io_port2 = (io_port2 & 0xE0) | 0x10;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=500000;   break;        //  50ms/div
        case 'Q' : io_port2 = (io_port2 & 0xE0) | 0x11;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=1000000;  break;        // 100ms/div
        case 'R' : io_port2 = (io_port2 & 0xE0) | 0x12;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=2000000;  break;        // 200ms/div
        case 'S' : io_port2 = (io_port2 & 0xE0) | 0x14;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=5000000;  break;        // 500ms/div
        case 'T' : io_port2 = (io_port2 & 0xE0) | 0x15;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=10000000; break;        //    1s/div
        case 'U' : io_port2 = (io_port2 & 0xE0) | 0x16;  N = 1000; max7311_write_port2(io_port2);  SampleDelay=20000000; break;        //    2s/div
    }
}
