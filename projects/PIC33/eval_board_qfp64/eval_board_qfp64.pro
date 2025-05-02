TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic
INCLUDEPATH += $(MCU_LIBRARIES)
INCLUDEPATH += D:/Electronique/MCU/PIC/PIC33/eval_board_qfp64
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h"

DEFINES += __dsPIC33F__
DEFINES += __dsPIC33FJ256GP506A__
DEFINES += __LANGUAGE_C__

SOURCES += \
    main.c \
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
    $(MCU_LIBRARIES)/ads7843.c \
    $(MCU_LIBRARIES)/max7311.c \
    $(MCU_LIBRARIES)/misc.c \
    $(MCU_LIBRARIES)/mma7660.c \
    $(MCU_LIBRARIES)/mmc_sd.c \
    $(MCU_LIBRARIES)/ov7670.c \
    $(MCU_LIBRARIES)/pcf8574.c \
    $(MCU_LIBRARIES)/tea5767.c \
    $(MCU_LIBRARIES)/tmp75.c \
    $(MCU_LIBRARIES)/clock.c \
    $(MCU_LIBRARIES)/delays.c \
    $(MCU_LIBRARIES)/dft.c \
    $(MCU_LIBRARIES)/dht11.c \
    $(MCU_LIBRARIES)/ds1307.c \
    $(MCU_LIBRARIES)/ds1337.c \
    $(MCU_LIBRARIES)/ds1621.c \
    $(MCU_LIBRARIES)/font.c \
    $(MCU_LIBRARIES)/glcd_128x64.c \
    $(MCU_LIBRARIES)/lcd.c \
    $(MCU_LIBRARIES)/glcd_320x240.c \
    $(MCU_LIBRARIES)/lcd_5110.c \
    $(MCU_LIBRARIES)/max6956.c \
    $(MCU_LIBRARIES)/console.c \
    $(MCU_LIBRARIES)/bh1750.c \
    $(MCU_LIBRARIES)/lm63.c \
    $(MCU_LIBRARIES)/bmp085.c \
    $(MCU_LIBRARIES)/i2c_tools.c

HEADERS += \
    main.h \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33FJ256GP506A.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33Fxxxx.h" \
    $(MCU_LIBRARIES)/lib_pic/i2c.h \
    $(MCU_LIBRARIES)/lib_pic/adc.h \
    $(MCU_LIBRARIES)/lib_pic/dma.h \
    $(MCU_LIBRARIES)/lib_pic/ext_int.h \
    $(MCU_LIBRARIES)/lib_pic/oscillator.h \
    $(MCU_LIBRARIES)/lib_pic/pwm.h \
    $(MCU_LIBRARIES)/lib_pic/spi.h \
    $(MCU_LIBRARIES)/lib_pic/timer.h \
    $(MCU_LIBRARIES)/lib_pic/uart.h \
    $(MCU_LIBRARIES)/ads7843.h \
    $(MCU_LIBRARIES)/max6956.h \
    $(MCU_LIBRARIES)/max7311.h \
    $(MCU_LIBRARIES)/misc.h \
    $(MCU_LIBRARIES)/mma7660.h \
    $(MCU_LIBRARIES)/mmc_sd.h \
    $(MCU_LIBRARIES)/ov7670.h \
    $(MCU_LIBRARIES)/pcf8574.h \
    $(MCU_LIBRARIES)/signaux.h \
    $(MCU_LIBRARIES)/tea5767.h \
    $(MCU_LIBRARIES)/tmp75.h \
    $(MCU_LIBRARIES)/clock.h \
    $(MCU_LIBRARIES)/delays.h \
    $(MCU_LIBRARIES)/dft.h \
    $(MCU_LIBRARIES)/dht11.h \
    $(MCU_LIBRARIES)/ds1307.h \
    $(MCU_LIBRARIES)/ds1337.h \
    $(MCU_LIBRARIES)/ds1621.h \
    $(MCU_LIBRARIES)/font.h \
    $(MCU_LIBRARIES)/font_5x7.h \
    $(MCU_LIBRARIES)/glcd_128x64.h \
    $(MCU_LIBRARIES)/lcd.h \
    $(MCU_LIBRARIES)/glcd_320x240.h \
    $(MCU_LIBRARIES)/lcd_5110.h \
    $(MCU_LIBRARIES)/console.h \
    $(MCU_LIBRARIES)/types.h \
    $(MCU_LIBRARIES)/lib_pic/Defines_EB_QFP64.h \
    $(MCU_LIBRARIES)/bh1750.h \
    $(MCU_LIBRARIES)/lm63.h \
    $(MCU_LIBRARIES)/bmp085.h \
    $(MCU_LIBRARIES)/i2c_tools.h

