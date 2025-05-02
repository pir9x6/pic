TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic
INCLUDEPATH += $(MCU_LIBRARIES)/lib_pic/TCP-IP
INCLUDEPATH += $(MCU_LIBRARIES)
INCLUDEPATH += D:/Electronique/MCU/PIC/PIC24/ENC28J60
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/dsPIC33F/h"
INCLUDEPATH += "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/PIC24F/h"

#DEFINES += __PIC24F__
DEFINES += __dsPIC33F__

#DEFINES += __PIC24FJ64GB002__
#DEFINES += __PIC24FJ256GB210__
DEFINES += __dsPIC33FJ256MC710__

DEFINES += __LANGUAGE_C__
DEFINES += __C30__

SOURCES += main.c \
    CustomHTTPApp.c \
    $(MCU_LIBRARIES)/ds1621.c \
    $(MCU_LIBRARIES)/lib_pic/i2c.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Announce.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ARCFOUR.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ARP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/AutoIP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/BerkeleyAPI.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/BigInt.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Delay.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DHCP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DHCPs.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DNS.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DNSs.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DynDNS.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ENC28J60.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/FileSystem.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/FTP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Hashes.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Helpers.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/HTTP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/HTTP2.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ICMP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/IP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/MPFS.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/MPFS2.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/NBNS.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Random.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Reboot.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/RSA.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SMTP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SNMP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SNMPv3.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SNMPv3USM.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SNTP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SSL.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/StackTsk.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/TCP.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/TCPPerformanceTest.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Telnet.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/TFTPc.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Tick.c \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/UDP.c \
    $(MCU_LIBRARIES)/lib_pic/adc.c \
    $(MCU_LIBRARIES)/lib_pic/oscillator.c \
    $(MCU_LIBRARIES)/lib_pic/pic_config.c \
    $(MCU_LIBRARIES)/lib_pic/uart.c \
    $(MCU_LIBRARIES)/ds1337.c \
    $(MCU_LIBRARIES)/lcd.c \
    $(MCU_LIBRARIES)/bh1750.c \
    $(MCU_LIBRARIES)/bmp085.c \
    $(MCU_LIBRARIES)/clock.c \
    $(MCU_LIBRARIES)/console.c \
    $(MCU_LIBRARIES)/delays.c \
    $(MCU_LIBRARIES)/i2c_tools.c \
    $(MCU_LIBRARIES)/lm63.c \
    $(MCU_LIBRARIES)/max6956.c \
    $(MCU_LIBRARIES)/misc.c \
    $(MCU_LIBRARIES)/mma7660.c

OTHER_FILES += \
    HTTPPrint.idx

HEADERS += \
    Compiler.h \
    GenericTypeDefs.h \
    HTTPPrint.h \
    main.h \
    TCPIPConfig.h \
    $(MCU_LIBRARIES)/ds1621.h \
    $(MCU_LIBRARIES)/types.h \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/PIC24F/h/p24FJ64GB002.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/PIC24F/h/p24FJ256GB210.h" \
    "C:/Program Files (x86)/Microchip/mplabc30/v3.31/support/PIC24F/h/p24Fxxxx.h" \
    $(MCU_LIBRARIES)/lib_pic/i2c.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/_HTTP2.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Announce.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ARCFOUR.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ARP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/AutoIP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/BerkeleyAPI.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/BigInt.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Delay.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DHCP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DNS.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/DynDNS.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ENC28J60.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/FileSystem.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/FTP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Hashes.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Helpers.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/HTTP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/HTTP2.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/ICMP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/IP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/MAC.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/MPFS.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/MPFS2.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/NBNS.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Random.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Reboot.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/regdef.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/RSA.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SMTP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SNMP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SNMPv3.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SNTP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/SSL.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/StackTsk.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/TCP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/TCPIP.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/TCPPerformanceTest.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Telnet.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/TFTPc.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/Tick.h \
    $(MCU_LIBRARIES)/lib_pic/TCP-IP/UDP.h \
    $(MCU_LIBRARIES)/lib_pic/adc.h \
    $(MCU_LIBRARIES)/lib_pic/io.h \
    $(MCU_LIBRARIES)/lib_pic/oscillator.h \
    $(MCU_LIBRARIES)/lib_pic/pic_compiler.h \
    $(MCU_LIBRARIES)/lib_pic/uart.h \
    $(MCU_LIBRARIES)/ds1337.h \
    $(MCU_LIBRARIES)/lcd.h \
    $(MCU_LIBRARIES)/bh1750.h \
    $(MCU_LIBRARIES)/bmp085.h \
    $(MCU_LIBRARIES)/clock.h \
    $(MCU_LIBRARIES)/console.h \
    $(MCU_LIBRARIES)/delays.h \
    $(MCU_LIBRARIES)/i2c_tools.h \
    $(MCU_LIBRARIES)/lm63.h \
    $(MCU_LIBRARIES)/max6956.h \
    $(MCU_LIBRARIES)/misc.h \
    $(MCU_LIBRARIES)/mma7660.h \
    $(MCU_LIBRARIES)/lib_pic/Defines_EB_QFP100.h \
    $(MCU_LIBRARIES)/lib_pic/Defines_EB_ENC28J60.h

