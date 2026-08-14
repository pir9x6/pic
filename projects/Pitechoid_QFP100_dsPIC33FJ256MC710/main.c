/******************************************************************************
* Title:    Evaluation board with dsPIC33FJ256MC710
* MCU:      dsPIC33FJ256MC710
*******************************************************************************
* Versions: v1.0    01/08/2014  MPLAB: vx.x   XC16: vx.x
*                   Initial version
*           v1.1    08/08/2026  MPLAB: v6.20  XC-DSC: v4.0
******************************************************************************/


/******************************************************************************
* Includes
******************************************************************************/
#include "config.h"

#include "xc.h"
#include <libpic30.h>
#include <stdio.h>      /* printf */

#include "i2c_tools.h"
#include "log.h"
#include "misc.h"
#include "oscillator.h"
#include "types.h"

#include "date_time.h"
#include "delays.h"
//#include "dma.h"
//#include "ext_int.h"
#include "i2c.h"
#include "io.h"
#include "lcd_hd44780.h"
#include "glcd_320x240.h"
#include "pwm.h"
//#include "spi.h"
#include "timer.h"
#include "uart.h"

#include "bh1750.h"
#include "ds1337.h"
#include "ds1631.h"
#include "pcf8574.h"
#include "tmp75.h"

#include "hardware_profile.h"

#define LCD_2x16

/******************************************************************************
* Global variables
******************************************************************************/
UART_ID UART_ID_LOG = UART_ID_1;


/******************************************************************************
* Main program
******************************************************************************/
int main (void)
{
    float light = 132.0;
    float tmp75_temp = -10.0;
    float ds1631_temp = -12.5;
    u8 pwm_duty = 0;
    LCD_HD44780_CONFIG_t lcd_hd44780_config = {
        .nb_lines = LCD_HD44780_NB_LINES_2,
        .nb_bits = LCD_HD44780_NB_BITS_4,
        .shift = LCD_HD44780_SHIFT_RIGHT
    };
    UART_CFG_t uart_1_cfg = {
        .uart_id = UART_ID_1,
        .baudrate = UART_FREQ,
        .system_clock = GetSystemClock()
    };
    I2C_CFG_t i2c_1_cfg = {
        .bus_id = I2C_BUS_1,
        .freq = I2C_FREQ,
        .slave_or_master = I2C_MASTER,
        .en_master_it = 1,
        .en_slave_it = 0,
        .slave_addr = 0x00
    };
    date_time_t t = {
        .hrs = 18,
        .min = 16,
        .sec =  0,
        .dow =  6,
        .day = 26,
        .mth = 07,
        .yrs = 26
    };
    TIMER_CFG_t timer_7_cfg = {
        .timer_id = TIMER_ID_7,
        .timer_prescaler = TMR_PRESCALER_256,
        .timer_postscaler = TMR_POSTSCALER_NONE,
        .period = 50000
    };
    TIMER_CFG_t timer_9_cfg = {
        .timer_id = TIMER_ID_9,
        .timer_prescaler = TMR_PRESCALER_256,
        .timer_postscaler = TMR_POSTSCALER_NONE,
        .period = 25000
    };
    PWM_CFG_t pwm_1_cfg = {
        .pwm_id = PWM_ID_1,
        .duty = 50,
        .freq = 10000,
        .timer_source = PWM_FROM_TMR2
    };

    u16 glcd_device_id = 0;
    __C30_UART = 1;

    //--------------------- Oscillator Initialization -------------------------
    oscillator_init (OSC_80MHZ);
    delay_ms(10);

    //------------------------ IO configuration -------------------------------
    TRISA = 0xFFFF;         // all ports as input by default
    _TRISA4 = 0;            // GLCD RST
    TRISB = 0x0000;         // PORTB as output (LCD data bus)
    TRISC = 0xFFFF;
    TRISD = 0xFFFF;
    _TRISD5 = 0;            // GLCD RD
    _TRISD14 = 0;           // GLCD WR
    TRISE = 0xFFFF;
    _TRISE5 = 0;            // LED 1
    TRISF = 0xFFFF;
    _TRISF3 = 0;            // UART TX
    _TRISF4 = 0;            // GLCD CS
    _TRISF5 = 0;            // GLCD RS
    _TRISF6 = 0;            // SPI CLOCK
    _TRISF8 = 0;            // SPI MOSI
    TRISG = 0xFFFF;
    _TRISG15 = 0;           // LED 2
    AD1PCFGL = 0xFFFF;      // PORTA & PORTB as digital I/O

    /* GPIO configured as Open Drain */
    ODCGbits.ODCG2 = 1;
    ODCGbits.ODCG3 = 1;

    //------------------------ Init IT on external event ----------------------
    // external int on negative edge
    //ext_int0_init(EXT_INT_NEG);

    //--------------------------------- LCD Init ------------------------------
    uart_init(&uart_1_cfg);
    LOG_YEL("------ Welcome on this Pitechoid board ------\r\n");

#ifdef LCD_2x16
    lcd_hd44780_init(&lcd_hd44780_config);
#else
    glcd_init(&glcd_device_id);
    glcd_clear(WHITE);
    glcd_colorbar();
    glcd_string(60, 50, "Pi to the R", 16, PINK, GREEN);
    LOG_WARNING("GLCD device ID: 0x%04X\r\n", glcd_device_id);
#endif

    i2c_init(&i2c_1_cfg);
    i2c_detect(i2c_1_cfg.bus_id);

    timer_init(&timer_7_cfg);
    timer_init(&timer_9_cfg);

    pwm_init(&pwm_1_cfg);

    //---------------------------------- Sensors ------------------------------
    if (tmp75_configure(I2C_BUS_1, I2C_ADR_TMP75) != SUCCESS){
        LOG_ERROR("TMP75 initialization failed");
        PIN_LED_ERROR = 1;
    }

    if (bh1750_init(I2C_BUS_1, I2C_ADR_BH1750) != SUCCESS){
        LOG_ERROR("BH1750 initialization failed");
        PIN_LED_ERROR = 1;
    }

    /* Configure DS1631 in continuous mode */
    // if (ds1631_config(I2C_BUS_1, I2C_ADR_DS1631, DS1631_CFG_RES_12B | DS1631_CFG_CONTINUOUS) == SUCCESS){
    //     /* start temperature conversion */
    //     if (ds1631_start_conv(I2C_BUS_1, I2C_ADR_DS1631) != SUCCESS)
    //     {
    //         PIN_LED_ERROR = 1;
    //     }
    // }else{
    //     LOG_ERROR("DS1631 initialization failed");
    //     PIN_LED_ERROR = 1;
    // }

    // init RTC
    //ds1337_init(I2C_BUS_1);
//    ds1337_set_time(I2C_BUS_1, t);


    //---------------------------- Main Loop ----------------------------------
    while (1)
    {

        pwm_set_duty(&pwm_1_cfg);
        if (pwm_duty < 100){
            pwm_duty++;
        }else{
            pwm_duty = 0;
        }
        pwm_1_cfg.duty = pwm_duty;
        LOG_WARNING("%u", pwm_duty);

        // PIN_LED_ERROR = 1;
        // PIN_LED2 = 0;
        // delay_ms (350);

        // PIN_LED_ERROR = 0;
        // PIN_LED2 = 1;
        delay_ms (100);

        t.sec++;
        if (t.sec >= 60){
            t.sec = 0;
            t.min++;
            if (t.min >= 60){
                t.min = 0;
                t.hrs++;
                if (t.hrs >= 24){
                    t.hrs = 0;
                    t.day++;
                    if (t.day > 31){
                        t.day = 1;
                        t.mth++;
                        if (t.mth > 12){
                            t.mth = 1;
                            t.yrs++;
                        }
                    }
                }
            }
        }

        lcd_hd44780_write_time(t, LCD_HD44780_LINE_1, 1/*position*/);
        lcd_hd44780_write_date(t, LCD_HD44780_LINE_2, 1/*position*/, LCD_HD44780_DATE_LETTERS);
        printf("Time: %02d:%02d:%02d   ", t.hrs, t.min, t.sec);

        // ds1631_read_temp(I2C_BUS_1, I2C_ADR_DS1631, &ds1631_temp);
        // lcd_hd44780_write_temperature(ds1631_temp, LCD_HD44780_LINE_1, 10/*position*/);
        // printf("Temp(DS1631): %2.1fC   ", (double)ds1631_temp);

        tmp75_read_temp(I2C_BUS_1, I2C_ADR_TMP75, &tmp75_temp);
        lcd_hd44780_write_temperature(tmp75_temp, LCD_HD44780_LINE_2, 10/*position*/);
        printf("Temp(TMP75): %2.1fC   ", (double)tmp75_temp);

        bh1750_get_light(I2C_BUS_1, I2C_ADR_BH1750, &light);
        printf("Light: %2.1f lx    ",  (double)light);

        printf("\r\n");

    }

    return 0;
}
