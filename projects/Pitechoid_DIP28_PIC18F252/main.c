//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Project     :   Reference project for:                              &&&
//&&&                   Pitechoid Dev Board PIC18 DIP28                     &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   IDE         :   MPLABX v6.20                                        &&&
//&&&   Compiler    :   XC8 v3.10                                           &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&   Version     :                                                       &&&
//&&&   - 1.0    30 Apr 2020    Creation                                    &&&
//&&&   - 1.1    22 Jul 2026    Renamed lcd_2x16 to lcd_hd44780             &&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//------------------------- Remove useless warnings ---------------------------
#pragma warning disable 520     // function is never called
#pragma warning disable 759     // expression generates no code
#pragma warning disable 1311    // missing configuration setting
#pragma warning disable 1498    // pointer in expression may have no targets
#pragma warning disable 1510    // non-reentrant function
#pragma warning disable 2020

//-------------------------------- includes -----------------------------------
#include "config.h"
#include "xc.h"
#include "stdio.h"
#include "hardware_profile.h"

#include "bcd.h"
#include "bh1750.h"
#include "ccp.h"
// #include "console.h"
#include "date_time.h"
#include "delays.h"
#include "ds1307.h"
#include "ds1631.h"
#include "eeprom_i2c.h"
#include "i2c.h"
#include "i2c_tools.h"
#include "interrupts.h"
#include "io.h"
#include "lcd_hd44780.h"
#include "log.h"
#include "mma7660.h"
#include "pcf8574.h"
#include "pin_manager.h"
#include "pwm.h"
#include "timer.h"
#include "tmp75.h"
#include "types.h"
#include "uart.h"

//-------------------------------- Defines ------------------------------------
#define DEBOUNCE_DELAY  100

//---------------------------- Global variables -------------------------------
bool_t time_has_changed_timer = FALSE;
bool_t time_has_changed_user = FALSE;
UART_ID UART_ID_LOG = UART_ID_1;
const u8 pcf8574_values[14] = {
    0b01111111,
    0b10111111,
    0b11011111,
    0b11101111,
    0b11110111,
    0b11111011,
    0b11111101,
    0b11111110,
    0b11111101,
    0b11111011,
    0b11110111,
    0b11101111,
    0b11011111,
    0b10111111,
};

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//-------------------------------- Main Program -------------------------------
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void main (void)
{
    u8 i, j;
    u8 cnt = 0;
    float light;
    s8 x = 0; s8 y = 0; s8 z = 0;
    date_time_t t = {
            t.hrs = 18,
            t.min = 16,
            t.sec =  0,
            t.dow =  6,
            t.day = 26,
            t.mth = 07,
            t.yrs = 26
    };
    LCD_HD44780_CONFIG_t lcd_hd44780_config = {
        .nb_lines = LCD_HD44780_NB_LINES_2,
        .nb_bits = LCD_HD44780_NB_BITS_4,
        .shift = LCD_HD44780_SHIFT_RIGHT
    };
    float tmp75_temp;
    float ds1631_temp = -12.5;
    u8 eeprom_data = 0x55;
    u32 eeprom_addr = 0x00;
    UART_CFG_t uart_1_cfg = {
        .uart_id = UART_ID_1,
        .baudrate = UART_FREQ
    };
    I2C_CFG_t i2c_1_cfg = {
        .bus_id = I2C_BUS_1,
        .freq = I2C_FREQ,
        .slave0_master1 = 1,
        .en_master_it = 0,
        .en_slave_it = 0,
        .slave_addr = 0x00
    };
    TIMER_CFG_t timer_2_cfg = {
        .timer_id = TIMER_ID_2,
        .timer_prescaler = TMR_PRESCALER_1,
        .timer_postscaler = TMR_POSTSCALER_10,
        .period = 49
    };

//--------------------------------- GPIO init ---------------------------------
    pin_manager_init();

    /* default values */
    PIN_LED_ERROR = 0;
    PIN_LED_SEC = 0;

//----------------------------------- UART ------------------------------------
    /* At 10 MHz the actual bitrate is 125k. Putty must be set to 125000
       or a 11.0592 MHz crystal must be used otherwise it won't work */
    if (uart_init(&uart_1_cfg) != SUCCESS){
        LOG_ERROR("UART initialization failed");
        PIN_LED_ERROR = 1;
    }
    printf("\nCoucou \n");

//--------------------- i2c, bus & devices initialization ---------------------
    if (i2c_init(&i2c_1_cfg) != SUCCESS){
        LOG_ERROR("I2C initialization failed");
        PIN_LED_ERROR = 1;
    }

    i2c_detect(I2C_BUS_1);

//-------------------------- Interruption sur Timer 2 -------------------------
    /* Timer period = Fosc(10M) / 4 /  Prescaler(1) / Postscaler(10) / Timer(250) / Cnt(1000) = 1s */
    if (timer_init(&timer_2_cfg) != SUCCESS){
        LOG_ERROR("Timer 2 initialization failed");
        PIN_LED_ERROR = 1;
    }

//---------------- 3-Axis Orientation/Motion/Detection Sensor -----------------
    mma7660_init(I2C_BUS_1, I2C_ADR_MMA7660);

//------------------------ CCP Configuration (PWM mode) -----------------------
    // if (ccp_init(CCP_ID_1, TIMER_ID_2, 0/*freq*/, 255/*duty*/) != SUCCESS){
    //     LOG_ERROR("CCP #1 initialization failed");
    //     PIN_LED_ERROR = 1;
    // }
    // ccp_set_pwm_duty(CCP_ID_1, 512);

    // if (ccp_init(CCP_ID_2, TIMER_ID_4, 0/*freq*/, 255/*duty*/) != SUCCESS){
    //     LOG_ERROR("CCP #2 initialization failed");
    //     PIN_LED_ERROR = 1;
    // }
    // ccp_set_pwm_duty(CCP_ID_2, 512);

    // if (ccp_init(CCP_ID_3, TIMER_ID_2, 0/*freq*/, 255/*duty*/) != SUCCESS){
    //     LOG_ERROR("CCP #3 initialization failed");
    //     PIN_LED_ERROR = 1;
    // }
    // ccp_set_pwm_duty(CCP_ID_3, 512);

    // if (ccp_init(CCP_ID_4, TIMER_ID_2, 0/*freq*/, 255/*duty*/) != SUCCESS){
    //     LOG_ERROR("CCP #4 initialization failed");
    //     PIN_LED_ERROR = 1;
    // }
    // ccp_set_pwm_duty(CCP_ID_4, 512);

//--------------------------------- LCD Init ----------------------------------
    lcd_hd44780_init(lcd_hd44780_config);

//------------------------------------ RTC ------------------------------------
    if (ds1307_init(I2C_BUS_1, I2C_ADR_DS1307) != SUCCESS){
        LOG_ERROR("DS1307 initialization failed");
        PIN_LED_ERROR = 1;
    }
    if (ds1307_set_time(I2C_BUS_1, I2C_ADR_DS1307, t) != SUCCESS){
        LOG_ERROR("Unable to set RTC date & time");
        PIN_LED_ERROR = 1;
    }
    if (ds1307_get_time(I2C_BUS_1, I2C_ADR_DS1307, &t) != SUCCESS){
        LOG_ERROR("Unable to get RTC date & time");
        PIN_LED_ERROR = 1;
    }

//---------------------------------- Sensors ----------------------------------
    if (tmp75_configure(I2C_BUS_1, I2C_ADR_TMP75) != SUCCESS){
        LOG_ERROR("TMP75 initialization failed");
        PIN_LED_ERROR = 1;
    }

    if (bh1750_init(I2C_BUS_1, I2C_ADR_BH1750) != SUCCESS){
        LOG_ERROR("BH1750 initialization failed");
        PIN_LED_ERROR = 1;
    }

    /* Configure DS1631 in continuous mode */
    if (ds1631_config(I2C_BUS_1, I2C_ADR_DS1631, DS1631_CFG_RES_12B | DS1631_CFG_CONTINUOUS) == SUCCESS){
        /* start temperature conversion */
        if (ds1631_start_conv(I2C_BUS_1, I2C_ADR_DS1631) != SUCCESS)
        {
            PIN_LED_ERROR = 1;
        }
    }else{
        LOG_ERROR("DS1631 initialization failed");
        PIN_LED_ERROR = 1;
    }

    //---------------------------------- EEPROM ----------------------------------
    // if (eeprom_i2c_write_byte(I2C_BUS_1, &EEPROM_24LC1025, I2C_ADR_EEPROM, 0x00008, 0x23) != SUCCESS){
    //     LOG_ERROR("Unable to write to EEPROM");
    //     PIN_LED_ERROR = 1;
    // }

    // if (eeprom_i2c_write_byte(I2C_BUS_1, &EEPROM_24LC1025, I2C_ADR_EEPROM, 0x00010, 0x5A) != SUCCESS){
    //     LOG_ERROR("Unable to write to EEPROM");
    //     PIN_LED_ERROR = 1;
    // }

//----------------------------- Global Interrupts -----------------------------
    enable_global_interrupts();

//-----------------------------------------------------------------------------
    while (1){
        delay_ms(400);

        pcf8574_write_port(I2C_BUS_1, I2C_ADR_PCF8574A, pcf8574_values[cnt]);
        if (++cnt > 13){
            cnt = 0;
        }

        // lcd_hd44780_write_time(t, LCD_HD44780_LINE_1, 1/*position*/);
        // lcd_hd44780_write_date(t, LCD_HD44780_LINE_2, 1/*position*/, LCD_HD44780_DATE_LETTERS);
        printf("Time: %02d:%02d:%02d   ", t.hrs, t.min, t.sec);

        ds1631_read_temp(I2C_BUS_1, I2C_ADR_DS1631, &ds1631_temp);
        lcd_hd44780_write_temperature(ds1631_temp, LCD_HD44780_LINE_1, 10/*position*/);
        printf("Temp(DS1631): %2.1fC   ", ds1631_temp);

        tmp75_read_temp(I2C_BUS_1, I2C_ADR_TMP75, &tmp75_temp);
        lcd_hd44780_write_temperature(tmp75_temp, LCD_HD44780_LINE_2, 10/*position*/);
        printf("Temp(TMP75): %2.1fC   ", tmp75_temp);

        bh1750_get_light(I2C_BUS_1, I2C_ADR_BH1750, &light);
        printf("Light: %2.1f lx    ",  light);

        // mma7660_read_angles(I2C_BUS_1, I2C_ADR_MMA7660, &x, &y, &z);
        // printf("MMA7660: X=%d, Y=%d, Z=%d", x, y, z);

        if(eeprom_i2c_read_byte(I2C_BUS_1, &EEPROM_24LC1025, I2C_ADR_EEPROM, eeprom_addr, &eeprom_data) != SUCCESS){
            LOG_ERROR("Unable to read from EEPROM");
            PIN_LED_ERROR = 1;
        }else{
            LOG_INFO("EEPROM: Addr=0x%08lX Data=0x%02X    ", eeprom_addr, eeprom_data);
        }
        eeprom_addr++;

        // printf("\r\n");

        if (time_has_changed_user || time_has_changed_timer){
            if (time_has_changed_user){
                time_has_changed_user = FALSE;
            }

            if (time_has_changed_timer){
                time_has_changed_timer = FALSE;
                datetime_increase_seconds(&t);
            }
        }

        if (!PIN_SWITCH_1){
            delay_ms(25);
            if (!PIN_SWITCH_1){
                datetime_increase_minutes(&t);
                time_has_changed_user = TRUE;
                i2c_dump(I2C_BUS_1, I2C_ADR_DS1631, 0x00/*start*/, 256/*length*/);
            }
        }

        if (!PIN_SWITCH_2){
            delay_ms(25);
            if (!PIN_SWITCH_2){
                datetime_decrease_minutes(&t);
                time_has_changed_user = TRUE;
                i2c_dump(I2C_BUS_1, I2C_ADR_TMP75, 0x00/*start*/, 256/*length*/);
            }
        }
    }

}

