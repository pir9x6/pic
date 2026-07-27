//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//  v1.0    2020-05-10  Fixed 4 bits init (sent 4 bits data before 8 bits)
//  v1.1    2020-05-27  Removed days strings (now located in date_time.h)
//  v1.2    2026-07-26  Renaming
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "bcd.h"
#include "misc.h"
#include "date_time.h"
#include "lcd_hd44780.h"
#include "hardware_profile.h"
#include "delays.h"
#include "math.h"

static void _write(u8 data, u8 rs);
static void _write_4b(u8 data, u8 rs);

/*****************************************************************************
* Initialization of LCD
******************************************************************************/
void lcd_hd44780_init(LCD_HD44780_CONFIG_t config)
{

    /* wait > 15 ms @ 5V, > 40 ms @ 3.3V */
    delay_ms(60);

#if defined (LCD_4_BITS)

    /* init value */
    _write_4b(0x3, LCD_HD44780_CMD);

    /* wait > 4.1 ms */
    delay_ms(20);

    /* init value, second time */
    _write_4b(0x3, LCD_HD44780_CMD);

    /* wait > 100s */
    delay_ms(1);

    /* init value, third time */
    _write_4b(0x3, LCD_HD44780_CMD);

    /* Return home */
    _write_4b(0x2, LCD_HD44780_CMD);

#elif defined (LCD_8_BITS)

    /* init value */
    _write (0x30, LCD_HD44780_CMD);

    /* wait > 4.1 ms */
    delay_ms (20);

    /* init value, second time */
    _write (0x30, LCD_HD44780_CMD);

     /* wait > 100s */
    delay_ms(1);

    /* init value, third time */
    _write (0x30, LCD_HD44780_CMD);

#else

    #error - LCD width not defined

#endif

    /* nb bits data, nb lines */
    _write(LCD_HD44780_SET_FUNCTION | config.nb_lines | config.nb_bits, LCD_HD44780_CMD);

    /* right shift */
    _write(LCD_HD44780_CURSOR_SHIFT | config.shift, LCD_HD44780_CMD);

    /* Display ON, Cursor OFF, Blink OFF */
    _write (0x0C, LCD_HD44780_CMD);

    /* Increment, no display shift */
    _write (0x06, LCD_HD44780_CMD);

    delay_ms(1);

    /* clear */
    _write(0x01, LCD_HD44780_CMD);

    /* first line, first charactere */
    _write(0x80, LCD_HD44780_CMD);
}


/*****************************************************************************
* Write data to the LCD (4 bits mode)
******************************************************************************/
static void _write_4b(u8 data, u8 rs)
{
    PIN_LCD_HD44780_RS = rs;
    PIN_LCD_HD44780_D7 = (data >> 3) & 0x01;
    PIN_LCD_HD44780_D6 = (data >> 2) & 0x01;
    PIN_LCD_HD44780_D5 = (data >> 1) & 0x01;
    PIN_LCD_HD44780_D4 = (data >> 0) & 0x01;

    PIN_LCD_HD44780_E = 1;
    delay_us (1);
    PIN_LCD_HD44780_E = 0;
}


/*****************************************************************************
* Write data to the LCD
******************************************************************************/
static void _write (u8 data, u8 rs)
{
#if defined (LCD_4_BITS)

    PIN_LCD_HD44780_RS = rs;

    // Send MSB First
    PIN_LCD_HD44780_D7 = (data >> 7) & 0x01;
    PIN_LCD_HD44780_D6 = (data >> 6) & 0x01;
    PIN_LCD_HD44780_D5 = (data >> 5) & 0x01;
    PIN_LCD_HD44780_D4 = (data >> 4) & 0x01;

    PIN_LCD_HD44780_E = 1;
    delay_us (1);
    PIN_LCD_HD44780_E = 0;

    // Send LSB Last
    PIN_LCD_HD44780_D7 = (data >> 3) & 0x01;
    PIN_LCD_HD44780_D6 = (data >> 2) & 0x01;
    PIN_LCD_HD44780_D5 = (data >> 1) & 0x01;
    PIN_LCD_HD44780_D4 = (data >> 0) & 0x01;

    PIN_LCD_HD44780_E = 1;
    delay_us (1);
    PIN_LCD_HD44780_E = 0;
    delay_us (50);

#elif defined (LCD_8_BITS)

    PIN_LCD_HD44780_RS = rs;
    PIN_LCD_HD44780_D7 = (data >> 7) & 0x01;
    PIN_LCD_HD44780_D6 = (data >> 6) & 0x01;
    PIN_LCD_HD44780_D5 = (data >> 5) & 0x01;
    PIN_LCD_HD44780_D4 = (data >> 4) & 0x01;
    PIN_LCD_HD44780_D3 = (data >> 3) & 0x01;
    PIN_LCD_HD44780_D2 = (data >> 2) & 0x01;
    PIN_LCD_HD44780_D1 = (data >> 1) & 0x01;
    PIN_LCD_HD44780_D0 = (data >> 0) & 0x01;

    PIN_LCD_HD44780_E = 1;
    delay_us (1);
    PIN_LCD_HD44780_E = 0;
    delay_us (50);

#else

    #error - LCD width not defined

#endif

}


/*****************************************************************************
* Set position
******************************************************************************/
void lcd_hd44780_set_position(u8 line, u8 pos)
{
    static const u8 addr[] =
    {
        0x00,
        0x40,
        0x14,
        0x54
    };

    _write(0x80 | (addr[line] + (pos - 1)), LCD_HD44780_CMD);

}


/*****************************************************************************
* Clear LCD
******************************************************************************/
void lcd_hd44780_clear(void)
{
    _write (0x01, LCD_HD44780_CMD);
}


/*****************************************************************************
* Send string to LCD
******************************************************************************/
void lcd_hd44780_write_string(const char *string)
{
    while (*string)
    {
        _write (*string++, LCD_HD44780_DATA);
    }
}


/*****************************************************************************
* Scroll line
* works partially, not finished
******************************************************************************/
void lcd_hd44780_scroll_line(u8 row, const char *text, u8 offset)
{
    u8 i;

    lcd_hd44780_set_position(row, 0);

    for(i = 0; i < 20 /*LCD_HD44780_WIDTH*/; i++)
    {
        char c = text[offset + i];

        if(c == '\0')
            c = ' ';

        _write(c, LCD_HD44780_DATA);
    }
}


/*****************************************************************************
* Display a hex digit
******************************************************************************/
static void _write_hex_digit (u8 data)
{
    data &= 0x0F;

    if (data < 10)
        _write(data + '0', LCD_HD44780_DATA);
    else
        _write(data + 'A' - 10, LCD_HD44780_DATA);
}

void lcd_hd44780_write_hex8 (u8 data)
{
    _write_hex_digit(data >> 4);
    _write_hex_digit(data);
}

void lcd_hd44780_write_hex16 (u16 data)
{
    _write_hex_digit((u8)data >> 12);
    _write_hex_digit((u8)data >> 8);
    _write_hex_digit((u8)data >> 4);
    _write_hex_digit((u8)data);
}


/*****************************************************************************
* Display an unsigned number with a binary representation
******************************************************************************/
void lcd_hd44780_write_1digit(u8 data)
{
    u8 bcd[5];
    dec_2_bcd (data, bcd);
    _write (bcd[0] + 0x30, LCD_HD44780_DATA);
}

void lcd_hd44780_write_2digit(u8 data)
{
    u8 bcd[5];
    dec_2_bcd (data, bcd);
    _write (bcd[1] + 0x30, LCD_HD44780_DATA);
    _write (bcd[0] + 0x30, LCD_HD44780_DATA);
}

/*****************************************************************************
* Display an unsigned number with a binary representation
******************************************************************************/
void lcd_hd44780_write_binary (u8 data)
{
    u8 i;

    for (i = 0; i < 8; i++)
    {
        _write((data & 0x80) ? '1' : '0', LCD_HD44780_DATA);
        data <<= 1;
    }
}


/*****************************************************************************
* Display Decimal number
******************************************************************************/
void lcd_hd44780_write_float (f32 data)
{
    u8 bcd_int[10], bcd_dec[5];

    if (data < 0){
        _write ('-', LCD_HD44780_DATA);
    }

    float_2_bcd (data, bcd_int, bcd_dec);
    _write (bcd_int[9] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[8] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[7] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[6] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[5] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[4] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[3] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[2] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[1] + 0x30, LCD_HD44780_DATA);
    _write (bcd_int[0] + 0x30, LCD_HD44780_DATA);
    _write (',', LCD_HD44780_DATA);
    _write (bcd_dec[0] + 0x30, LCD_HD44780_DATA);
    _write (bcd_dec[1] + 0x30, LCD_HD44780_DATA);
}


/*****************************************************************************
* Display unsigned numbers
******************************************************************************/
void lcd_hd44780_write_u8 (u8 data)
{
    u8 bcd[5];
    dec_2_bcd (data, bcd);
    _write (bcd[2] + 0x30, LCD_HD44780_DATA);
    _write (bcd[1] + 0x30, LCD_HD44780_DATA);
    _write (bcd[0] + 0x30, LCD_HD44780_DATA);
}


void lcd_hd44780_write_u16 (u16 data)
{
    u8 bcd[5];
    dec_2_bcd (data, bcd);
    _write (bcd[4] + 0x30, LCD_HD44780_DATA);
    _write (bcd[3] + 0x30, LCD_HD44780_DATA);
    _write (bcd[2] + 0x30, LCD_HD44780_DATA);
    _write (bcd[1] + 0x30, LCD_HD44780_DATA);
    _write (bcd[0] + 0x30, LCD_HD44780_DATA);
}


void lcd_hd44780_write_u32 (u32 data)
{
    u8 bcd[9];
    dec_2_bcd32 (data, bcd);
    _write (bcd[8] + 0x30, LCD_HD44780_DATA);
    _write (bcd[7] + 0x30, LCD_HD44780_DATA);
    _write (bcd[6] + 0x30, LCD_HD44780_DATA);
    _write (bcd[5] + 0x30, LCD_HD44780_DATA);
    _write (bcd[4] + 0x30, LCD_HD44780_DATA);
    _write (bcd[3] + 0x30, LCD_HD44780_DATA);
    _write (bcd[2] + 0x30, LCD_HD44780_DATA);
    _write (bcd[1] + 0x30, LCD_HD44780_DATA);
    _write (bcd[0] + 0x30, LCD_HD44780_DATA);
}


/*****************************************************************************
* Display temperature on LCD
******************************************************************************/
void lcd_hd44780_write_temperature (float temp, u8 line, u8 pos)
{
    u8 integer = (u8)temp;
    u8 decimal = (u8)((temp - integer) * 10.0f);

    /* set position */
    lcd_hd44780_set_position (line, pos);

    /* Handle negative temperatures */
    if (temp < 0)
    {
        _write('-', LCD_HD44780_DATA);
        temp = -temp;
    }

    lcd_hd44780_write_2digit (integer);
    _write (',', LCD_HD44780_DATA);
    _write (decimal + '0', LCD_HD44780_DATA);

    /* ° */
    _write (0xdf, LCD_HD44780_DATA);

    /* Celsius */
    _write ('C', LCD_HD44780_DATA);

    /* Blank caractere to erase potential previous content */
    _write (' ', LCD_HD44780_DATA);
}


/*****************************************************************************
* Display Date on LCD
******************************************************************************/
void lcd_hd44780_write_date (date_time_t t, u8 line, u8 pos, LCD_HD44780_DATE_FORMAT_t format)
{
    u8 bcd[5];

    if (format == LCD_HD44780_DATE_LETTERS){
        lcd_hd44780_set_position (line, pos);
        dec_2_bcd (t.dow, bcd);
        if (bcd[0] > 7 || bcd[0] < 1){
            bcd[0] = 1;
        }
        lcd_hd44780_write_string(day_of_week_short[bcd[0]-1]);
        lcd_hd44780_write_string (" ");
        lcd_hd44780_write_2digit (t.day);
        lcd_hd44780_write_string (" ");
        dec_2_bcd (t.mth, bcd);
        lcd_hd44780_write_string(month_short[bcd[0]-1]);
    }
    else{
        lcd_hd44780_set_position (line, pos);
        lcd_hd44780_write_2digit (t.day);
        lcd_hd44780_write_string ("/");
        lcd_hd44780_write_2digit (t.mth);
        lcd_hd44780_write_string ("/");
        lcd_hd44780_write_2digit (t.yrs);
        lcd_hd44780_write_string (" ");
    }
}


/*****************************************************************************
* Display Hour on LCD
******************************************************************************/
void lcd_hd44780_write_time (date_time_t t, u8 line, u8 pos)
{
    lcd_hd44780_set_position (line, pos);

    lcd_hd44780_write_2digit (t.hrs);
    lcd_hd44780_write_string (":");
    lcd_hd44780_write_2digit (t.min);
    lcd_hd44780_write_string (":");
    lcd_hd44780_write_2digit (t.sec);
}