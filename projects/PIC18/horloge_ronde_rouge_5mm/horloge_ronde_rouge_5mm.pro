TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $(MCU_LIBRARIES)/lib_arithm
INCLUDEPATH += $(MCU_LIBRARIES)/lib_chips
INCLUDEPATH += $(MCU_LIBRARIES)/lib_lcd
INCLUDEPATH += $(MCU_LIBRARIES)/lib_misc
INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic
INCLUDEPATH += D:/Electronique/MCU/PIC/PIC18/horloge_ronde_rouge_5mm
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc18/v3.43/h/"

DEFINES += __18CXX
DEFINES += __18F252
DEFINES += __LANGUAGE_C__

SOURCES += \
    main.c \
    interrupts_management.c \
    $(MCU_LIBRARIES)/lib_pic/i2c.c \
    $(MCU_LIBRARIES)/lib_pic/uart.c \
    $(MCU_LIBRARIES)/lib_chips/ds1307.c \
    $(MCU_LIBRARIES)/lib_chips/ds1621.c \
    $(MCU_LIBRARIES)/lib_misc/clock.c \
    $(MCU_LIBRARIES)/lib_misc/delays.c \
    $(MCU_LIBRARIES)/lib_misc/i2c_tools.c \
    $(MCU_LIBRARIES)/lib_misc/misc.c

HEADERS += \
    main.h \
    interrupts_management.h \
    hardware_profile.h \
    "C:/Program Files (x86)/Microchip/mplabc18/v3.43/h/p18cxxx.h" \
    $(MCU_LIBRARIES)/lib_pic/i2c.h \
    $(MCU_LIBRARIES)/lib_pic/pic_compiler.h \
    $(MCU_LIBRARIES)/lib_pic/uart.h \
    $(MCU_LIBRARIES)/lib_chips/ds1307.h \
    $(MCU_LIBRARIES)/lib_chips/ds1621.h \
    $(MCU_LIBRARIES)/lib_misc/i2c_tools.h \
    $(MCU_LIBRARIES)/lib_misc/clock.h \
    $(MCU_LIBRARIES)/lib_misc/delays.h \
    $(MCU_LIBRARIES)/lib_misc/misc.h \
    $(MCU_LIBRARIES)/lib_misc/types.h

