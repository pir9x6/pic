//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Titre       :   test carte avec boitier QFP         &&&
//&&&                   Fichier     :   main.c                              &&&
//&&&                   Description :   Programme principal                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                   Auteur      :   Pierre BLACHÉ                       &&&
//&&&                   Date        :   Octobre 2010                        &&&
//&&&                   Version     :   1.0                                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&                                                                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Fichiers Requis :   main.c                              &&&
//&&&                                   p33FJ256GP506A.gld                  &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "main.h"


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
    u16 device_id = 0;
    u16 tmp = 0;

    oscillator_init(30, 0, 0);

    TRISB = 0x0000;                   // tout en sortie (data LCD)
    TRISC = 0x0000;
    TRISD = 0x0000;
    TRISF = 0x0014;                   // RF4 en entrée (RX) et RF2 (SDI)
    TRISG = 0x0000;
    AD1PCFGL = 0xFFFF;                // PORTB en  digital I/O
    DIR_ADS7843_INT = 1;

    ext_int0_init(EXT_INT_NEG);
    i2c1_init(I2C_FREQ, I2C_MASTER);
    uart_init(UART_FREQ, UART_EN_IT_RX);

    ads7843_init();

    glcd_init(&device_id);
    glcd_clear(WHITE);
    glcd_colorbar();
    glcd_string(60, 50, "Pi to the R", 16, PINK, GREEN);
    glcd_register(60, 150, 12345, 5, 16, PINK, GREEN);
    glcd_draw_line(20, 50, 180, 10, RED);
    glcd_draw_line(180, 10, 230, 300, RED);
    glcd_draw_line(230, 300, 20, 50, RED);
    glcd_draw_circle(150, 150, 50, YELLOW);
    glcd_draw_full_rectangle(30 , 100, 50, 30, BLUE);

    glcd_rd_reg (GLCD_SSD1298_REG_DRIVER_OUT, &tmp);
    uart_write_string("GLCD_SSD1298_REG_DRIVER_OUT = ");
    uart_write_hexa_u16(tmp, UART_0x | UART_LF);

    glcd_rd_reg (GLCD_SSD1298_REG_V_RAM_ADR_E, &tmp);
    uart_write_string("GLCD_SSD1298_REG_V_RAM_ADR_E = ");
    uart_write_hexa_u16(tmp, UART_0x | UART_LF);

    uart_write_string("GLCD device ID = ");
    uart_write_hexa_u16(device_id, UART_0x | UART_LF);

    while (1)
    {

//        LED1 = 1; LED2 = 0; delay_ms (100);
//        LED2 = 1; LED1 = 0; delay_ms (100);
        LED3 = 1; LED2 = 0; delay_ms (100);
        LED4 = 1; LED3 = 0; delay_ms (100);
        LED5 = 1; LED4 = 0; delay_ms (100);
        LED6 = 1; LED5 = 0; delay_ms (100);
        LED5 = 1; LED6 = 0; delay_ms (100);
        LED4 = 1; LED5 = 0; delay_ms (100);
        LED3 = 1; LED4 = 0; delay_ms (100);
        LED2 = 1; LED3 = 0; delay_ms (100);
    }

    return 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//---------------- External Interrupt 0 Interrupt Sub Routine -----------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void ext_int0_isr()
{
    u16 x=0, y=0;
    LED1 = !LED1;
    Read_ADS(&x, &y);
    uart_write_string("ADS7843 X = ");
    uart_write_u16(x);
    uart_write_string("  Y = ");
    uart_write_u16(y);
    uart_write('\n');
}

void ext_int1_isr()
{

}

void ext_int2_isr()
{

}

void ext_int3_isr()
{

}

void ext_int4_isr()
{

}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Timer 1 Interrupt Sub Routine -------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void timer1_isr ()
{
    LED1 = 1; LED2 = 0; delay_ms (50);
    LED2 = 1; LED1 = 0; delay_ms (50);
    LED3 = 1; LED2 = 0; delay_ms (50);
    LED4 = 1; LED3 = 0; delay_ms (50);
    LED5 = 1; LED4 = 0; delay_ms (50);
    LED6 = 1; LED5 = 0; delay_ms (50);
    LED5 = 1; LED6 = 0; delay_ms (50);
    LED4 = 1; LED5 = 0; delay_ms (50);
    LED3 = 1; LED4 = 0; delay_ms (50);
    LED2 = 1; LED3 = 0; delay_ms (50);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Uart 1 Interrupt Sub Routine --------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void uart_isr ()
{


}
