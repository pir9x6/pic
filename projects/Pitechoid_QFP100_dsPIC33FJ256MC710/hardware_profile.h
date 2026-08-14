#ifndef _HARDWARE_PROFILE_H_
#define _HARDWARE_PROFILE_H_

/*****************************************************************************
* includes
******************************************************************************/
#include <xc.h>


/*****************************************************************************
* Version
******************************************************************************/
#define VERSION_MAJ             0x01
#define VERSION_MIN             0x01


/*****************************************************************************
* Constants
******************************************************************************/
#define GetSystemClock()        (80000000ul)
#define GetInstructionClock()   (GetSystemClock()/2)
#define GetPeripheralClock()    GetInstructionClock()
#define FCY                     GetInstructionClock()

#define I2C_FREQ        100000        // i2c bus frequency
#define UART_FREQ       115200        // uart frequency
#define I2C_SLAVE_ADDR  0x54


/*****************************************************************************
* I2C device addresses
******************************************************************************/
#define I2C_ADR_BH1750          0x23
#define I2C_ADR_PCF8574A        0x38
#define I2C_ADR_TMP75           0x48
#define I2C_ADR_DS1631          0x49
#define I2C_ADR_MMA7660         0x4C
#define I2C_ADR_EEPROM          0x50
#define I2C_ADR_DS1307          0x68
#define I2C_ADR_DS1337          0x68
#define I2C_ADR_BMP180          0x77


/*****************************************************************************
* Configuration
******************************************************************************/
#define LCD_4_BITS


/*****************************************************************************
* Pin Assignments
******************************************************************************/
/* il vaut mieux utiliser les LAT plutot que les PORT pour les sorties */

#define PIN_LED_ERROR       _LATE5
#define PIN_LED2            _LATG15

/* LCD 2x16 */
#define PIN_LCD_HD44780_RS  _LATB1
#define PIN_LCD_HD44780_E   _LATB0
#define PIN_LCD_HD44780_D4  _LATB3
#define PIN_LCD_HD44780_D5  _LATB2
#define PIN_LCD_HD44780_D6  _LATB5
#define PIN_LCD_HD44780_D7  _LATB4

// GLCD 320x240
#define PIN_GLCD_RD         _LATD15
#define PIN_GLCD_RD_DIR     _TRISD15
#define PIN_GLCD_WR         _LATD14
#define PIN_GLCD_WR_DIR     _TRISD14
#define PIN_GLCD_RS         _LATF5
#define PIN_GLCD_RS_DIR     _TRISF5
#define PIN_GLCD_CS         _LATF4
#define PIN_GLCD_CS_DIR     _TRISF4
#define PIN_GLCD_LATCH      LATB
#define PIN_GLCD_PORT       PORTB
#define PIN_GLCD_PORT_DIR   TRISB

// 7-seg displays
#define SEG7_A              _LATF4      // LCD_CS
#define SEG7_B              _LATF5      // LCD_RS
#define SEG7_C              _LATB11     // LCD_D11
#define SEG7_D              _LATB14     // LCD_D14
#define SEG7_E              _LATB15     // LCD_D15
#define SEG7_F              _LATA3      // TS_IRQ
#define SEG7_G              _LATA4      // LCD_RST
#define SEG7_H              _LATB10     // LCD_D10

#define SEG7_DIS1           _LATB6      // LCD_D6
#define SEG7_DIS2           _LATB7      // LCD_D7
#define SEG7_DIS3           _LATB8      // LCD_D8
#define SEG7_DIS4           _LATB9      // LCD_D9
#define SEG7_DIS5           _LATD14     // LCD_WR
#define SEG7_DIS6           _LATD15     // LCD_RD

#endif
