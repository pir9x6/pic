#ifndef _HARDWARE_PROFILE_H_
#define _HARDWARE_PROFILE_H_

//-------------------------------- Revision -----------------------------------
#define VERSION_MAJ             0x01
#define VERSION_MIN             0x00

//-----------------------------------------------------------------------------
#define DS1307_IS_PRESENT
#define DS1631_IS_PRESENT

//-------------------------- I2C device addresses -----------------------------
#define I2C_ADR_BH1750          0x23
#define I2C_ADR_PCF8574A        0x38
#define I2C_ADR_TMP75           0x48
#define I2C_ADR_DS1631          0x49
#define I2C_ADR_LM63            0x4C
#define I2C_ADR_MMA7660         0x4C
#define I2C_ADR_EEPROM          0x50
#define I2C_ADR_DS1307          0x68
#define I2C_ADR_BMP280          0x76
#define I2C_ADR_BMP180          0x77

//--------------------------------- GPIOs -------------------------------------
#define LCD_RS_DIR              TRISBbits.TRISB5
#define LCD_E_DIR               TRISBbits.TRISB4
#define LCD_D4_DIR              TRISBbits.TRISB0
#define LCD_D5_DIR              TRISBbits.TRISB1
#define LCD_D6_DIR              TRISBbits.TRISB2
#define LCD_D7_DIR              TRISBbits.TRISB3

#define PIN_LCD_HD44780_RS      LATBbits.LATB5
#define PIN_LCD_HD44780_E       LATBbits.LATB4
#define PIN_LCD_HD44780_D4      LATBbits.LATB0
#define PIN_LCD_HD44780_D5      LATBbits.LATB1
#define PIN_LCD_HD44780_D6      LATBbits.LATB2
#define PIN_LCD_HD44780_D7      LATBbits.LATB3

#define PIN_LED_ERROR           LATAbits.LATA0
#define PIN_LED_SEC             LATAbits.LATA1

#define PIN_SWITCH_1            PORTAbits.RA2
#define PIN_SWITCH_2            PORTAbits.RA3

#define LCD_5110_SCE            LATBbits.LATB0
#define LCD_5110_RST            LATBbits.LATB1
#define LCD_5110_RS             LATBbits.LATB3
#define LCD_5110_DATA           LATBbits.LATB4
#define LCD_5110_CLK            LATBbits.LATB5

//--------------------------- Peripherals speed -------------------------------
#define UART_FREQ               115200  /* actual bitrate is 125k for 18F252, 119k for 18F26K42*/
#define I2C_FREQ                100000
#define GetSystemClock()        10000000L
#define GetPeripheralClock()    GetSystemClock()

//--------------------------------- Misc --------------------------------------
#define LCD_4_BITS

#endif
