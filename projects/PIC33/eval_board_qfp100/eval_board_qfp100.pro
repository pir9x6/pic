TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $(MCU_LIBRARIES)/lib_arithm
INCLUDEPATH += $(MCU_LIBRARIES)/lib_chips
INCLUDEPATH += $(MCU_LIBRARIES)/lib_lcd
INCLUDEPATH += $(MCU_LIBRARIES)/lib_misc
INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic
INCLUDEPATH += D:/Electronique/MCU/PIC/PIC33/eval_board_qfp100
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h"
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/generic/h"
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/include"

DEFINES += __dsPIC33F__
DEFINES += __dsPIC33FJ256MC710__
DEFINES += __LANGUAGE_C__
DEFINES += __C30__

SOURCES += \
    ../../../PIC/PIC33/eval_board_qfp100/main.c \
    ../../../PIC/PIC33/eval_board_qfp100/interrupts_management.c \
    $(MCU_LIBRARIES)/lib_pic/i2c.c \
    $(MCU_LIBRARIES)/lib_pic/adc.c \
    $(MCU_LIBRARIES)/lib_pic/dma.c \
    $(MCU_LIBRARIES)/lib_pic/ext_int.c \
    $(MCU_LIBRARIES)/lib_pic/mcu_config.c \
    $(MCU_LIBRARIES)/lib_pic/oscillator.c \
    $(MCU_LIBRARIES)/lib_pic/pwm.c \
    $(MCU_LIBRARIES)/lib_pic/spi.c \
    $(MCU_LIBRARIES)/lib_pic/timer.c \
    $(MCU_LIBRARIES)/lib_pic/uart.c \
    $(MCU_LIBRARIES)/lib_chips/cy22393.c \
    $(MCU_LIBRARIES)/lib_chips/max7311.c \
    $(MCU_LIBRARIES)/lib_misc/misc.c \
    $(MCU_LIBRARIES)/lib_chips/mma7660.c \
    $(MCU_LIBRARIES)/lib_chips/mmc_sd.c \
    $(MCU_LIBRARIES)/lib_chips/ov7670.c \
    $(MCU_LIBRARIES)/lib_chips/pcf8574.c \
    $(MCU_LIBRARIES)/lib_chips/tea5767.c \
    $(MCU_LIBRARIES)/lib_chips/tmp75.c \
    $(MCU_LIBRARIES)/lib_misc/delays.c \
    $(MCU_LIBRARIES)/lib_arithm/dft.c \
    $(MCU_LIBRARIES)/lib_chips/dht11.c \
    $(MCU_LIBRARIES)/lib_chips/ds1307.c \
    $(MCU_LIBRARIES)/lib_chips/ds1337.c \
    $(MCU_LIBRARIES)/lib_chips/ds1621.c \
    $(MCU_LIBRARIES)/lib_lcd/font.c \
    $(MCU_LIBRARIES)/lib_lcd/glcd_128x64.c \
    $(MCU_LIBRARIES)/lib_lcd/lcd.c \
    $(MCU_LIBRARIES)/lib_lcd/lcd_320x240.c \
    $(MCU_LIBRARIES)/lib_lcd/lcd_5110.c \
    $(MCU_LIBRARIES)/lib_chips/max6956.c \
    $(MCU_LIBRARIES)/lib_misc/console.c \
    $(MCU_LIBRARIES)/lib_chips/bh1750.c \
    $(MCU_LIBRARIES)/lib_chips/lm63.c \
    $(MCU_LIBRARIES)/lib_chips/bmp085.c \
    $(MCU_LIBRARIES)/lib_misc/i2c_tools.c \
    $(MCU_LIBRARIES)/lib_chips/max518.c \
    $(MCU_LIBRARIES)/lib_chips/mcp23009.c

HEADERS += \
    ../../../PIC/PIC33/eval_board_qfp100/main.h \
    ../../../PIC/PIC33/eval_board_qfp100/hardware_profile.h \
    ../../../PIC/PIC33/eval_board_qfp100/interrupts_management.h \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33FJ256MC710.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33Fxxxx.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/generic/h/libpic30.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/include/math.h" \
    $(MCU_LIBRARIES)/lib_pic/i2c.h \
    $(MCU_LIBRARIES)/lib_pic/adc.h \
    $(MCU_LIBRARIES)/lib_pic/dma.h \
    $(MCU_LIBRARIES)/lib_pic/ext_int.h \
    $(MCU_LIBRARIES)/lib_pic/io.h \
    $(MCU_LIBRARIES)/lib_pic/oscillator.h \
    $(MCU_LIBRARIES)/lib_pic/pwm.h \
    $(MCU_LIBRARIES)/lib_pic/pic_compiler.h \
    $(MCU_LIBRARIES)/lib_pic/spi.h \
    $(MCU_LIBRARIES)/lib_pic/timer.h \
    $(MCU_LIBRARIES)/lib_pic/uart.h \
    $(MCU_LIBRARIES)/lib_chips/bh1750.h \
    $(MCU_LIBRARIES)/lib_chips/bmp085.h \
    $(MCU_LIBRARIES)/lib_chips/cy22393.h \
    $(MCU_LIBRARIES)/lib_chips/ds1307.h \
    $(MCU_LIBRARIES)/lib_chips/ds1337.h \
    $(MCU_LIBRARIES)/lib_chips/ds1621.h \
    $(MCU_LIBRARIES)/lib_chips/lm63.h \
    $(MCU_LIBRARIES)/lib_chips/max6956.h \
    $(MCU_LIBRARIES)/lib_chips/max7311.h \
    $(MCU_LIBRARIES)/lib_chips/max518.h \
    $(MCU_LIBRARIES)/lib_chips/mcp23009.h \
    $(MCU_LIBRARIES)/lib_chips/mma7660.h \
    $(MCU_LIBRARIES)/lib_chips/mmc_sd.h \
    $(MCU_LIBRARIES)/lib_chips/ov7670.h \
    $(MCU_LIBRARIES)/lib_chips/pcf8574.h \
    $(MCU_LIBRARIES)/lib_chips/tea5767.h \
    $(MCU_LIBRARIES)/lib_chips/tmp75.h \
    $(MCU_LIBRARIES)/lib_misc/misc.h \
    $(MCU_LIBRARIES)/lib_misc/signaux.h \
    $(MCU_LIBRARIES)/lib_misc/delays.h \
    $(MCU_LIBRARIES)/lib_arithm/dft.h \
    $(MCU_LIBRARIES)/lib_chips/dht11.h \
    $(MCU_LIBRARIES)/lib_lcd/font.h \
    $(MCU_LIBRARIES)/lib_lcd/font_5x7.h \
    $(MCU_LIBRARIES)/lib_lcd/glcd_128x64.h \
    $(MCU_LIBRARIES)/lib_lcd/lcd.h \
    $(MCU_LIBRARIES)/lib_lcd/lcd_320x240.h \
    $(MCU_LIBRARIES)/lib_lcd/lcd_5110.h \
    $(MCU_LIBRARIES)/lib_misc/console.h \
    $(MCU_LIBRARIES)/lib_misc/types.h \
    $(MCU_LIBRARIES)/lib_misc/i2c_tools.h

