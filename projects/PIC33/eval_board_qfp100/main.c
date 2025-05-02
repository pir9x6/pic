//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Titre           :   test carte avec boitier QFP         &&&
//&&&               Fichier         :   main.c                              &&&
//&&&               Description     :   Programme principal                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Auteur          :   Pierre BLACHÉ                       &&&
//&&&               Date            :   Fevrier 2012                        &&&
//&&&               Version         :   2.0                                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Ajout de l'heure et date avec RTC                       &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Fichiers Requis :   main.c                              &&&
//&&&                                   p33FJ256MC710.gld                   &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "main.h"
#include "string.h"


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
    //u8 cnt=0;
    //t_bmp085 bmp085_data;
    //u8 lm63_temp = 0;
    //u16 lm63_speed = 0;
    u8 temperature[2] = {0, 0};
    t_time t;
    __C30_UART = 1;

//-------------------- configuration de l'oscillateur -------------------------
#if defined (__dsPIC33FJ256MC710__)
    oscillator_init(OSC_100MHZ);
#endif
//-------------------- configuration des IO et remappage ----------------------
    io_config();
//---------------------------------- init uart --------------------------------
    uart_init(UART_FREQ, UART_EN_IT_RX);
    //dma_from_uart1_init();
//---------------------------------- init i2c ---------------------------------
    i2c_init(I2C_BUS_2, I2C_FREQ, I2C_MASTER);
    i2c_detect(I2C_BUS_2);
//---------------------------------- init lcd ---------------------------------
    lcd_2x16_init();
    lcd_2x16_clear();
    //lcd_5110_init();
    //lcd_5110_clear();
//--------------------------------- init chips --------------------------------
    //mma7660_init(I2C_BUS_2);
    //bh1750_init(I2C_BUS_2);
    //max6956_init(I2C_BUS_2);
    ds1337_init(I2C_BUS_2);
    //tea5767_init();
    //timer1_init(TMR_PRES_256, 250);     // prescaler=256, PR1=250
    uart_write_string (INVITE_CMD);
//-----------------------------------------------------------------------------
//    t.sec = 0;
//    t.min = 25;
//    t.hrs = 22;
//    t.dow = 4;
//    t.day = 15;
//    t.mth = 1;
//    t.yrs = 15;
//    ds1337_set_time(I2C_BUS_2, t);

    while (1)
    {
        LED1 = 1;   delay_ms (100);   LED1 = 0;
        LED2 = 1;   delay_ms (100);   LED2 = 0;
        LED3 = 1;   delay_ms (100);   LED3 = 0;
        LED4 = 1;   delay_ms (100);   LED4 = 0;
        LED3 = 1;   delay_ms (100);   LED3 = 0;
        LED2 = 1;   delay_ms (100);   LED2 = 0;

        /////////////////////////////////////////////////
        ds1621_read_temp(I2C_BUS_2, temperature);
        uart_write_temperature(temperature);
        lcd_write_temperature(temperature, LCD_LINE_1, 5);

        ds1337_get_time(I2C_BUS_2, &t);
        uart_write_date(t);
        lcd_write_date(t, LCD_LINE_2, 1);

        /////////////////////////////////////////////////
        //bh1750_get_light(ADR_BH1750, light);
        //uart_write_int(light[1]);

        /////////////////////////////////////////////////
        /*bmp085_init(I2C_BUS_2, &bmp085_data);
        bmp085_get_calibration_coef(I2C_BUS_2, &bmp085_data);
        bmp085_get_uncompensated_temperature(I2C_BUS_2, &bmp085_data);
        bmp085_get_uncompensated_pressure(I2C_BUS_2, &bmp085_data);
        bmp085_calculate_temp_pressure(I2C_BUS_2, &bmp085_data);

        lcd_2x16_position(1, 1);
        lcd_2x16_write_s32(bmp085_data.temp);

        lcd_2x16_position(2, 1);
        lcd_2x16_write_s32(bmp085_data.pressure);*/

        /////////////////////////////////////////////////
        //lm63_read_temp(&lm63_temp);
        //lcd_2x16_position(2, 1);
        //lcd_2x16_write_2bcd(lm63_temp);

        /*lm63_read_speed(&lm63_speed);
        lcd_2x16_position(1, 1);
        lcd_2x16_write_u16(lm63_speed);
        lcd_2x16_write_string(" RPM");*/

        /////////////////////////////////////////////////
        //lcd_2x16_position(1, 1);
        //lcd_2x16_write_double(123456.12345);

        /////////////////////////////////////////////////
        //cnt += 5;
        //if (cnt > 63) cnt = 0;
        //lm63_set_fan_speed(cnt);
    }
    return 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//--------------------- Init all IO of the MCU ------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void io_config(void)
{
    set_port_A_input(BIT11 | BIT5 | BIT1);
    TRISA = 0x0000;
    TRISB = 0x0000;                     //
    TRISC = 0x0000;
    TRISD = 0x0000;
    TRISE = 0x0000;
    TRISF = 0x0000;                     //
    TRISG = 0x0000;
    U1RX_TRIS = IO_IN;
    SW1_TRIS = IO_IN;
    SW2_TRIS = IO_IN;
    SW3_TRIS = IO_IN;
    SW4_TRIS = IO_IN;
#if defined(__PIC24FJ64GB002__)
    AD1PCFG = 0xFFFF
#elif defined(__PIC24FJ256GB210__)
    ANSA = 0x0000;
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSE = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;
#elif defined(__dsPIC33FJ256MC710__)
    AD1PCFGL = 0xFFFF;                  // PORTB as digital I/O
#endif
}
