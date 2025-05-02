//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Titre           :   test carte avec boitier DIP         &&&
//&&&               Fichier         :   main.c                              &&&
//&&&               Description     :   Programme principal                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&               Auteur          :   Pierre BLACHÉ                       &&&
//&&&               Date            :   Aout 2014                           &&&
//&&&               Version         :   1.0                                 &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "main.h"

u16 ir_address;
u8 ir_command;
u8 ir_new_cmd;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//------------------------------ Main Program ---------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
int main (void)
{
    //------------------------- Local Variables -------------------------------
    u8 temperature[2] = {0, 0};
    t_time t;
    __C30_UART = 1;
    u8 volume = 0;  // in dB (eg. 5 means -5dB)

    //------------------- Configuration du MCU (21µs)--------------------------
    oscillator_init (OSC_80MHZ);

    //------------------------ IO configuration -------------------------------
    TRISA = 0;
    TRISB = 0;
    _TRISB7 = IO_IN;            // Infra-red input
    _TRISB14 = IO_IN;           // Uart RX

    AD1PCFGL = 0xFFFF;          // PORTA & PORTB as digital I/O

    //--------------------------- Periph init ---------------------------------
    // external int on negative edge
    ext_int0_init(EXT_INT_NEG);

    // init UART @ 115200
    delay_ms(100);
    uart_init(UART_FREQ, UART_EN_IT_RX);

    // init I2C master @ 100kHz
    i2c_init(I2C_BUS_1, I2C_FREQ, I2C_MASTER);
    i2c_detect(I2C_BUS_1);

    // init RTC
    t.hrs = 22;     t.min = 53;     t.sec = 0;
    t.dow = 3;      t.day = 14;     t.mth = 1;      t.yrs = 15;
    ds1337_init(I2C_BUS_1);
//    i2c_dump(I2C_BUS_1, I2C_ADR_TDA7468);
//    i2c_detect(I2C_BUS_1);
//    ds1337_set_time(I2C_BUS_1, t);

    // init TDA7309
    tda7439_init(I2C_BUS_1, TDA7439_IN_1, 0x08);

    //---------------------------- Main Loop ----------------------------------
    while (1)
    {
        LED1 = 1;
        LED2 = 0;
        delay_ms (75);

        LED1 = 0;
        LED2 = 1;
        delay_ms (75);

        ds1621_read_temp(I2C_BUS_1, temperature);
//        uart_write_temperature(temperature);

        ds1337_get_time(I2C_BUS_1, &t);
//        uart_write_date(t);

        if (ir_new_cmd){
            ir_new_cmd = 0;

            switch(ir_command){
                case 0x45 : printf("CH- \n"); break;
                case 0x46 : printf("CH \n");  break;
                case 0x47 : printf("CH+ \n"); break;
                case 0x44 : printf("Previous \n"); break;
                case 0x40 : printf("Next \n"); break;
                case 0x43 : printf("Pause/Play \n"); break;
                case 0x07 : {
                    printf("- \n");
                    if (volume < 40){
                        volume += 8;
                    }
                    tda7439_volume(I2C_BUS_1, volume);
                    break;
                }
                case 0x15 : {
                    printf("+ \n");
                    if (volume >= 8){
                        volume -= 8;
                    }
                    tda7439_volume(I2C_BUS_1, volume);
                    break;
                }
                case 0x09 : printf("EQ \n"); break;
                case 0x16 : printf("0 \n"); break;
                case 0x19 : printf("100+ \n"); break;
                case 0x0D : printf("200+ \n"); break;
                case 0x0C : printf("1 \n"); tda7439_input(I2C_BUS_1, TDA7439_IN_1); break;
                case 0x18 : printf("2 \n"); tda7439_input(I2C_BUS_1, TDA7439_IN_2); break;
                case 0x5E : printf("3 \n"); tda7439_input(I2C_BUS_1, TDA7439_IN_3); break;
                case 0x08 : printf("4 \n"); break;
                case 0x1C : printf("5 \n"); break;
                case 0x5A : printf("6 \n"); break;
                case 0x42 : printf("7 \n"); break;
                case 0x52 : printf("8 \n"); break;
                case 0x4A : printf("9 \n"); break;
                default   : printf("Unknown command: %02X\n", ir_command); break;
            }
        }

        /*
        //====================
        LED1 = 1;
        LED2 = 0;
        delay_ms (150);

        RAM_CS = 0;
        serial_sram_wr_byte(ram_addr, 0x56);
        RAM_CS = 1;

        //====================
        LED1 = 0;
        LED2 = 1;
        delay_ms (150);
        RAM_CS = 0;
        ram_rd = serial_sram_rd_byte(ram_addr);        // get data
        RAM_CS = 1;

        uart_write_hexa_u8(UART_ID_1, ram_rd, UART_0x);
        */

    }

    return 0;
}
