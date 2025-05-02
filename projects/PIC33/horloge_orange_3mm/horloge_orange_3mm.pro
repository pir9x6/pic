TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic
INCLUDEPATH += $(MCU_LIBRARIES)
INCLUDEPATH += D:/Electronique/MCU/PIC/PIC33/horloge_orange_3mm
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h"
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/generic/h"

DEFINES += __dsPIC33F__
DEFINES += __dsPIC33FJ12GP201__
DEFINES += __LANGUAGE_C__
DEFINES += __C30__

SOURCES += \
    ../../../PIC/PIC33/horloge_orange_3mm/main.c \
    ../../../PIC/PIC33/horloge_orange_3mm/interrupts_management.c \
    $(MCU_LIBRARIES)/lib_pic/i2c.c \
    $(MCU_LIBRARIES)/lib_pic/ext_int.c \
    $(MCU_LIBRARIES)/lib_pic/pic_config.c \
    $(MCU_LIBRARIES)/lib_pic/oscillator.c \
    $(MCU_LIBRARIES)/lib_pic/pwm.c \
    $(MCU_LIBRARIES)/lib_pic/timer.c \
    $(MCU_LIBRARIES)/lib_pic/uart.c \
    $(MCU_LIBRARIES)/misc.c \
    $(MCU_LIBRARIES)/pcf8574.c \
    $(MCU_LIBRARIES)/delays.c \
    $(MCU_LIBRARIES)/ds1337.c \
    $(MCU_LIBRARIES)/ds1621.c \
    $(MCU_LIBRARIES)/console.c \
    $(MCU_LIBRARIES)/i2c_tools.c

HEADERS += \
    ../../../PIC/PIC33/horloge_orange_3mm/hardware_profile.h \
    ../../../PIC/PIC33/horloge_orange_3mm/main.h \
    ../../../PIC/PIC33/horloge_orange_3mm/interrupts_management.h \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33FJ12GP201.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33Fxxxx.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/generic/h/libpic30.h" \
    $(MCU_LIBRARIES)/lib_pic/i2c.h \
    $(MCU_LIBRARIES)/lib_pic/ext_int.h \
    $(MCU_LIBRARIES)/lib_pic/io.h \
    $(MCU_LIBRARIES)/lib_pic/oscillator.h \
    $(MCU_LIBRARIES)/lib_pic/pic_compiler.h \
    $(MCU_LIBRARIES)/lib_pic/pwm.h \
    $(MCU_LIBRARIES)/lib_pic/timer.h \
    $(MCU_LIBRARIES)/lib_pic/uart.h \
    $(MCU_LIBRARIES)/misc.h \
    $(MCU_LIBRARIES)/pcf8574.h \
    $(MCU_LIBRARIES)/delays.h \
    $(MCU_LIBRARIES)/ds1337.h \
    $(MCU_LIBRARIES)/ds1621.h \
    $(MCU_LIBRARIES)/console.h \
    $(MCU_LIBRARIES)/types.h \
    $(MCU_LIBRARIES)/i2c_tools.h

