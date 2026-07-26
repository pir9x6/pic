#ifndef _LCD_hd44780_H_
#define _LCD_hd44780_H_

#include "date_time.h"
#include "types.h"

/* Settings */
#define LCD_HD44780_NB_BITS     4        // number of bits of data bus (4 or 8)
#define LCD_HD44780_BLINKING    0        // blinking cursor (0 or 1)
#define LCD_HD44780_CURSOR      0        // display cursor (0 or 1)
#define LCD_HD44780_LIGNES      2        // number of lines (1 or 2)
#define LCD_HD44780_DOT         0        // size of caracters 5x8, 5x10 (0 or 1)
#define LCD_HD44780_SHIFT_RIGHT (1 << 2) // display from left to right
#define LCD_HD44780_SHIFT_LEFT  0        // display from right to left

/* Commands / Data*/
#define LCD_HD44780_DATA        1
#define LCD_HD44780_CMD         0

/* set function */
#define LCD_HD44780_CURSOR_SHIFT    0x10
#define LCD_HD44780_SET_FUNCTION    0x20
#define LCD_HD44780_NB_LINES_1      0x00
#define LCD_HD44780_NB_LINES_2      0x08
#define LCD_HD44780_NB_BITS_4       0x00
#define LCD_HD44780_NB_BITS_8       0x10

/* Line */
#define LCD_HD44780_LINE_1          0
#define LCD_HD44780_LINE_2          1
#define LCD_HD44780_LINE_3          2
#define LCD_HD44780_LINE_4          3

typedef struct{
    u8 nb_lines;
    u8 nb_bits;
    u8 shift;   /* 0 = left, 1 = right */
}LCD_HD44780_CONFIG_t;

typedef enum
{
    LCD_HD44780_DATE_LETTERS,
    LCD_HD44780_DATE_NUMBERS
}LCD_HD44780_DATE_FORMAT_t;

void lcd_hd44780_init(LCD_HD44780_CONFIG_t config);
void lcd_hd44780_set_position(u8 line, u8 pos);
void lcd_hd44780_clear(void);
void lcd_hd44780_write_hex8(u8 data);
void lcd_hd44780_write_hex16(u16 data);
void lcd_hd44780_write_binary(u8 data);
void lcd_hd44780_write_1digit(u8 data);
void lcd_hd44780_write_2digit(u8 data);
void lcd_hd44780_write_u8(u8 data);
void lcd_hd44780_write_u16(u16 data);
void lcd_hd44780_write_u32(u32 data);
void lcd_hd44780_write_float(f32 data);
void lcd_hd44780_write_string(const char *string);
void lcd_hd44780_scroll_line(u8 row, const char *text, u8 offset);
void lcd_hd44780_write_temperature(float temp, u8 line, u8 pos);
void lcd_hd44780_write_date(date_time_t t, u8 line, u8 pos, LCD_HD44780_DATE_FORMAT_t format);
void lcd_hd44780_write_time(date_time_t t, u8 line, u8 pos);

#endif