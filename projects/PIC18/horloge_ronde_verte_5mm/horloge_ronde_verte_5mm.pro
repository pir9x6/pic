TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic
INCLUDEPATH += $(MCU_LIBRARIES)
INCLUDEPATH += D:/Electronique/MCU/PIC/PIC18/horloge_ronde_verte_5mm
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc18/v3.43/h/"

DEFINES += __18CXX
DEFINES += __18F258
DEFINES += __LANGUAGE_C__

SOURCES += \
    main.c \
    $(MCU_LIBRARIES)/lib_pic/i2c.c \
    $(MCU_LIBRARIES)/lib_pic/uart.c \
    $(MCU_LIBRARIES)/delays.c \
    $(MCU_LIBRARIES)/ds1307.c \
    $(MCU_LIBRARIES)/ds1621.c \
    $(MCU_LIBRARIES)/misc.c \
    $(MCU_LIBRARIES)/pcf8574.c

HEADERS += \
    main.h \
    "C:/Program Files (x86)/Microchip/mplabc18/v3.43/h/p18cxxx.h" \
    $(MCU_LIBRARIES)/lib_pic/i2c.h \
    $(MCU_LIBRARIES)/lib_pic/uart.h \
    $(MCU_LIBRARIES)/delays.h \
    $(MCU_LIBRARIES)/ds1307.h \
    $(MCU_LIBRARIES)/ds1621.h \
    $(MCU_LIBRARIES)/misc.h \
    $(MCU_LIBRARIES)/pcf8574.h

