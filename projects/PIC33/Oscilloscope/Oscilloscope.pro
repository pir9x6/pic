TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic
INCLUDEPATH += $(MCU_LIBRARIES)
INCLUDEPATH += D:/Electronique/MCU/PIC/PIC33/Oscilloscope
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h"

DEFINES += __dsPIC33F__
DEFINES += __dsPIC33FJ128MC802__
DEFINES += __LANGUAGE_C__

SOURCES += \
    main.c \
    $(MCU_LIBRARIES)/lib_pic/i2c.c \
    $(MCU_LIBRARIES)/lib_pic/delays.c \
    $(MCU_LIBRARIES)/lib_pic/i2c.c \
    $(MCU_LIBRARIES)/lib_pic/uart.c \
    $(MCU_LIBRARIES)/max7311.c \
    $(MCU_LIBRARIES)/cy7c42x1.c \
    $(MCU_LIBRARIES)/max7311.c \
    $(MCU_LIBRARIES)/misc.c

HEADERS += \
    main.h \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33FJ128MC802.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h/p33Fxxxx.h" \
    $(MCU_LIBRARIES)/lib_pic/delays.h \
    $(MCU_LIBRARIES)/lib_pic/i2c.h \
    $(MCU_LIBRARIES)/lib_pic/io.h \
    $(MCU_LIBRARIES)/lib_pic/uart.h \
    $(MCU_LIBRARIES)/max7311.h \
    $(MCU_LIBRARIES)/types.h \
    $(MCU_LIBRARIES)/waves.h \
    $(MCU_LIBRARIES)/delays.h \
    $(MCU_LIBRARIES)/cy7c42x1.h \
    $(MCU_LIBRARIES)/types.h \
    $(MCU_LIBRARIES)/max7311.h \
    $(MCU_LIBRARIES)/misc.h

