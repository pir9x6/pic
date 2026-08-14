#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../libraries/lib_comp/bh1750.c ../../libraries/lib_comp/bmp085.c ../../libraries/lib_comp/ds1337.c ../../libraries/lib_comp/ds1631.c ../../libraries/lib_comp/eeprom_i2c.c ../../libraries/lib_comp/mma7660.c ../../libraries/lib_comp/pcf8574.c ../../libraries/lib_comp/tmp75.c ../../libraries//lib_lcd/glcd_320x240.c ../../libraries/lib_lcd/lcd_hd44780.c ../../libraries//lib_misc/delays.c ../../libraries//lib_misc/i2c_tools.c ../../libraries/lib_misc/date_time.c ../../libraries/lib_misc/bcd.c ../../libraries//lib_pic/timer.c ../../libraries//lib_pic/oscillator.c ../../libraries//lib_pic/i2c.c ../../libraries/lib_pic/uart.c ../../libraries//lib_pic/pic_config.c ../../libraries//lib_misc/misc.c interrupts_management.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/779364575/bh1750.o ${OBJECTDIR}/_ext/779364575/bmp085.o ${OBJECTDIR}/_ext/779364575/ds1337.o ${OBJECTDIR}/_ext/779364575/ds1631.o ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o ${OBJECTDIR}/_ext/779364575/mma7660.o ${OBJECTDIR}/_ext/779364575/pcf8574.o ${OBJECTDIR}/_ext/779364575/tmp75.o ${OBJECTDIR}/_ext/412712538/glcd_320x240.o ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o ${OBJECTDIR}/_ext/90777089/delays.o ${OBJECTDIR}/_ext/90777089/i2c_tools.o ${OBJECTDIR}/_ext/779656892/date_time.o ${OBJECTDIR}/_ext/779656892/bcd.o ${OBJECTDIR}/_ext/412716567/timer.o ${OBJECTDIR}/_ext/412716567/oscillator.o ${OBJECTDIR}/_ext/412716567/i2c.o ${OBJECTDIR}/_ext/113394246/uart.o ${OBJECTDIR}/_ext/412716567/pic_config.o ${OBJECTDIR}/_ext/90777089/misc.o ${OBJECTDIR}/interrupts_management.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/779364575/bh1750.o.d ${OBJECTDIR}/_ext/779364575/bmp085.o.d ${OBJECTDIR}/_ext/779364575/ds1337.o.d ${OBJECTDIR}/_ext/779364575/ds1631.o.d ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o.d ${OBJECTDIR}/_ext/779364575/mma7660.o.d ${OBJECTDIR}/_ext/779364575/pcf8574.o.d ${OBJECTDIR}/_ext/779364575/tmp75.o.d ${OBJECTDIR}/_ext/412712538/glcd_320x240.o.d ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o.d ${OBJECTDIR}/_ext/90777089/delays.o.d ${OBJECTDIR}/_ext/90777089/i2c_tools.o.d ${OBJECTDIR}/_ext/779656892/date_time.o.d ${OBJECTDIR}/_ext/779656892/bcd.o.d ${OBJECTDIR}/_ext/412716567/timer.o.d ${OBJECTDIR}/_ext/412716567/oscillator.o.d ${OBJECTDIR}/_ext/412716567/i2c.o.d ${OBJECTDIR}/_ext/113394246/uart.o.d ${OBJECTDIR}/_ext/412716567/pic_config.o.d ${OBJECTDIR}/_ext/90777089/misc.o.d ${OBJECTDIR}/interrupts_management.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/779364575/bh1750.o ${OBJECTDIR}/_ext/779364575/bmp085.o ${OBJECTDIR}/_ext/779364575/ds1337.o ${OBJECTDIR}/_ext/779364575/ds1631.o ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o ${OBJECTDIR}/_ext/779364575/mma7660.o ${OBJECTDIR}/_ext/779364575/pcf8574.o ${OBJECTDIR}/_ext/779364575/tmp75.o ${OBJECTDIR}/_ext/412712538/glcd_320x240.o ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o ${OBJECTDIR}/_ext/90777089/delays.o ${OBJECTDIR}/_ext/90777089/i2c_tools.o ${OBJECTDIR}/_ext/779656892/date_time.o ${OBJECTDIR}/_ext/779656892/bcd.o ${OBJECTDIR}/_ext/412716567/timer.o ${OBJECTDIR}/_ext/412716567/oscillator.o ${OBJECTDIR}/_ext/412716567/i2c.o ${OBJECTDIR}/_ext/113394246/uart.o ${OBJECTDIR}/_ext/412716567/pic_config.o ${OBJECTDIR}/_ext/90777089/misc.o ${OBJECTDIR}/interrupts_management.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=../../libraries/lib_comp/bh1750.c ../../libraries/lib_comp/bmp085.c ../../libraries/lib_comp/ds1337.c ../../libraries/lib_comp/ds1631.c ../../libraries/lib_comp/eeprom_i2c.c ../../libraries/lib_comp/mma7660.c ../../libraries/lib_comp/pcf8574.c ../../libraries/lib_comp/tmp75.c ../../libraries//lib_lcd/glcd_320x240.c ../../libraries/lib_lcd/lcd_hd44780.c ../../libraries//lib_misc/delays.c ../../libraries//lib_misc/i2c_tools.c ../../libraries/lib_misc/date_time.c ../../libraries/lib_misc/bcd.c ../../libraries//lib_pic/timer.c ../../libraries//lib_pic/oscillator.c ../../libraries//lib_pic/i2c.c ../../libraries/lib_pic/uart.c ../../libraries//lib_pic/pic_config.c ../../libraries//lib_misc/misc.c interrupts_management.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ256MC710
MP_LINKER_FILE_OPTION=,--script=p33FJ256MC710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/779364575/bh1750.o: ../../libraries/lib_comp/bh1750.c  .generated_files/flags/default/118d7548ad9cf71949d513212805aaae21bda290 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/bh1750.c  -o ${OBJECTDIR}/_ext/779364575/bh1750.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/bh1750.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/bmp085.o: ../../libraries/lib_comp/bmp085.c  .generated_files/flags/default/7424d4ecf5d3150d4c918b834a3bef940f16f3aa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/bmp085.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/bmp085.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/bmp085.c  -o ${OBJECTDIR}/_ext/779364575/bmp085.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/bmp085.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/ds1337.o: ../../libraries/lib_comp/ds1337.c  .generated_files/flags/default/5f747645abf98eea77af3892c749a0af7972b263 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/ds1337.c  -o ${OBJECTDIR}/_ext/779364575/ds1337.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/ds1337.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/ds1631.o: ../../libraries/lib_comp/ds1631.c  .generated_files/flags/default/e41356c3f1d083230f93198aac130838e63ae4e8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/ds1631.c  -o ${OBJECTDIR}/_ext/779364575/ds1631.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/ds1631.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/eeprom_i2c.o: ../../libraries/lib_comp/eeprom_i2c.c  .generated_files/flags/default/ae54ffcf39e42ca83ac10bca1aa5a9a16b142854 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/eeprom_i2c.c  -o ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/eeprom_i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/mma7660.o: ../../libraries/lib_comp/mma7660.c  .generated_files/flags/default/cab6f5ba08f58dbdd2f70d6544f23fa3e837a79c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/mma7660.c  -o ${OBJECTDIR}/_ext/779364575/mma7660.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/mma7660.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/pcf8574.o: ../../libraries/lib_comp/pcf8574.c  .generated_files/flags/default/940114e9dd6514e24b3654aa258f5ff760e8a61b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/pcf8574.c  -o ${OBJECTDIR}/_ext/779364575/pcf8574.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/pcf8574.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/tmp75.o: ../../libraries/lib_comp/tmp75.c  .generated_files/flags/default/93a1927d4f250009bdddef6880cd89d9aeb3cf1a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/tmp75.c  -o ${OBJECTDIR}/_ext/779364575/tmp75.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/tmp75.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412712538/glcd_320x240.o: ../../libraries//lib_lcd/glcd_320x240.c  .generated_files/flags/default/2cfbe0800455c86c363780a70e7310b30c0ac8f1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412712538" 
	@${RM} ${OBJECTDIR}/_ext/412712538/glcd_320x240.o.d 
	@${RM} ${OBJECTDIR}/_ext/412712538/glcd_320x240.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_lcd/glcd_320x240.c  -o ${OBJECTDIR}/_ext/412712538/glcd_320x240.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412712538/glcd_320x240.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/113398275/lcd_hd44780.o: ../../libraries/lib_lcd/lcd_hd44780.c  .generated_files/flags/default/ad508a3ee351681bd7a3c2ab1af812cc9331c643 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/113398275" 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o.d 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_lcd/lcd_hd44780.c  -o ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/113398275/lcd_hd44780.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/90777089/delays.o: ../../libraries//lib_misc/delays.c  .generated_files/flags/default/64db51ee476bcdcac228361b8d594925099519e9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/90777089" 
	@${RM} ${OBJECTDIR}/_ext/90777089/delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/90777089/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_misc/delays.c  -o ${OBJECTDIR}/_ext/90777089/delays.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/90777089/delays.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/90777089/i2c_tools.o: ../../libraries//lib_misc/i2c_tools.c  .generated_files/flags/default/e924f8c98034951ef166682fbd1cfdfe74d1e831 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/90777089" 
	@${RM} ${OBJECTDIR}/_ext/90777089/i2c_tools.o.d 
	@${RM} ${OBJECTDIR}/_ext/90777089/i2c_tools.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_misc/i2c_tools.c  -o ${OBJECTDIR}/_ext/90777089/i2c_tools.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/90777089/i2c_tools.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779656892/date_time.o: ../../libraries/lib_misc/date_time.c  .generated_files/flags/default/8b4837ed40a21dd7d9172ced1f7d4da8ad8f957f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_misc/date_time.c  -o ${OBJECTDIR}/_ext/779656892/date_time.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779656892/date_time.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779656892/bcd.o: ../../libraries/lib_misc/bcd.c  .generated_files/flags/default/dfb8db7a64e82251bf53efbed31306ecdda6409a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_misc/bcd.c  -o ${OBJECTDIR}/_ext/779656892/bcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779656892/bcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/timer.o: ../../libraries//lib_pic/timer.c  .generated_files/flags/default/b89b24445550896c38e7eac79a9d4972bbb0505b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/timer.c  -o ${OBJECTDIR}/_ext/412716567/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/oscillator.o: ../../libraries//lib_pic/oscillator.c  .generated_files/flags/default/5c424448fe9b1aba0b6601b071991d7027450b4a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/oscillator.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/oscillator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/oscillator.c  -o ${OBJECTDIR}/_ext/412716567/oscillator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/oscillator.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/i2c.o: ../../libraries//lib_pic/i2c.c  .generated_files/flags/default/a36249e0aa074b3db9a9ba08b3921aa747f8a48e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/i2c.c  -o ${OBJECTDIR}/_ext/412716567/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/113394246/uart.o: ../../libraries/lib_pic/uart.c  .generated_files/flags/default/f069ba0263f01328df8ff80ffc711cfd5db519d9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_pic/uart.c  -o ${OBJECTDIR}/_ext/113394246/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/113394246/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/pic_config.o: ../../libraries//lib_pic/pic_config.c  .generated_files/flags/default/c309ef69c809c54f196865922da02f02b59feea0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/pic_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/pic_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/pic_config.c  -o ${OBJECTDIR}/_ext/412716567/pic_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/pic_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/90777089/misc.o: ../../libraries//lib_misc/misc.c  .generated_files/flags/default/71be0f08dcb9bf93bb130ba2905a31e086b0219 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/90777089" 
	@${RM} ${OBJECTDIR}/_ext/90777089/misc.o.d 
	@${RM} ${OBJECTDIR}/_ext/90777089/misc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_misc/misc.c  -o ${OBJECTDIR}/_ext/90777089/misc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/90777089/misc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/interrupts_management.o: interrupts_management.c  .generated_files/flags/default/a0ac468cf4fca6ced1eeb39c3645f2ae3fdb4623 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts_management.o.d 
	@${RM} ${OBJECTDIR}/interrupts_management.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupts_management.c  -o ${OBJECTDIR}/interrupts_management.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupts_management.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/1bda0d6bf449ee3c34c677459178ee1995d153d8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/_ext/779364575/bh1750.o: ../../libraries/lib_comp/bh1750.c  .generated_files/flags/default/d36395130fe163c7e8c87129d9e8ea78d993bf7c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/bh1750.c  -o ${OBJECTDIR}/_ext/779364575/bh1750.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/bh1750.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/bmp085.o: ../../libraries/lib_comp/bmp085.c  .generated_files/flags/default/23b6fef936a10877cfaee4a7394f895e53180c40 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/bmp085.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/bmp085.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/bmp085.c  -o ${OBJECTDIR}/_ext/779364575/bmp085.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/bmp085.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/ds1337.o: ../../libraries/lib_comp/ds1337.c  .generated_files/flags/default/9b27e681d3aa3817c652809360772448bc85ee19 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/ds1337.c  -o ${OBJECTDIR}/_ext/779364575/ds1337.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/ds1337.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/ds1631.o: ../../libraries/lib_comp/ds1631.c  .generated_files/flags/default/34607cf78b84fefb1446f8d9299c394b7a0b0c86 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/ds1631.c  -o ${OBJECTDIR}/_ext/779364575/ds1631.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/ds1631.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/eeprom_i2c.o: ../../libraries/lib_comp/eeprom_i2c.c  .generated_files/flags/default/e38280c6f99388b78d85ceeda9efc99e6eefa221 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/eeprom_i2c.c  -o ${OBJECTDIR}/_ext/779364575/eeprom_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/eeprom_i2c.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/mma7660.o: ../../libraries/lib_comp/mma7660.c  .generated_files/flags/default/908ff5ba6a3013ec92dad745c69b51650d943e7e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/mma7660.c  -o ${OBJECTDIR}/_ext/779364575/mma7660.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/mma7660.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/pcf8574.o: ../../libraries/lib_comp/pcf8574.c  .generated_files/flags/default/16fa5dd7a82b6276ef11277374533bf802fda4c1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/pcf8574.c  -o ${OBJECTDIR}/_ext/779364575/pcf8574.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/pcf8574.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779364575/tmp75.o: ../../libraries/lib_comp/tmp75.c  .generated_files/flags/default/c774444bf00024cc16aa736c83c2ffdb9fa8adfe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.o.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_comp/tmp75.c  -o ${OBJECTDIR}/_ext/779364575/tmp75.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779364575/tmp75.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412712538/glcd_320x240.o: ../../libraries//lib_lcd/glcd_320x240.c  .generated_files/flags/default/db78ba93cabc8e40bac6a3ed8d4ee183cecb49fc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412712538" 
	@${RM} ${OBJECTDIR}/_ext/412712538/glcd_320x240.o.d 
	@${RM} ${OBJECTDIR}/_ext/412712538/glcd_320x240.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_lcd/glcd_320x240.c  -o ${OBJECTDIR}/_ext/412712538/glcd_320x240.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412712538/glcd_320x240.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/113398275/lcd_hd44780.o: ../../libraries/lib_lcd/lcd_hd44780.c  .generated_files/flags/default/2d21d3602cf41489d52ab6b0cfac1cef5fdecfed .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/113398275" 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o.d 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_lcd/lcd_hd44780.c  -o ${OBJECTDIR}/_ext/113398275/lcd_hd44780.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/113398275/lcd_hd44780.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/90777089/delays.o: ../../libraries//lib_misc/delays.c  .generated_files/flags/default/3e6355aed45af3819d7d40b4f4498f0bf5ef86eb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/90777089" 
	@${RM} ${OBJECTDIR}/_ext/90777089/delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/90777089/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_misc/delays.c  -o ${OBJECTDIR}/_ext/90777089/delays.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/90777089/delays.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/90777089/i2c_tools.o: ../../libraries//lib_misc/i2c_tools.c  .generated_files/flags/default/2a40121d767f8b8a37f2c77b19233b62843480a4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/90777089" 
	@${RM} ${OBJECTDIR}/_ext/90777089/i2c_tools.o.d 
	@${RM} ${OBJECTDIR}/_ext/90777089/i2c_tools.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_misc/i2c_tools.c  -o ${OBJECTDIR}/_ext/90777089/i2c_tools.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/90777089/i2c_tools.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779656892/date_time.o: ../../libraries/lib_misc/date_time.c  .generated_files/flags/default/11344878c7be7599ae40ffa49115471bf4a4ff6b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_misc/date_time.c  -o ${OBJECTDIR}/_ext/779656892/date_time.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779656892/date_time.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/779656892/bcd.o: ../../libraries/lib_misc/bcd.c  .generated_files/flags/default/688b0165ea162f8f9e54c116ba9fb8b8838af6d0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_misc/bcd.c  -o ${OBJECTDIR}/_ext/779656892/bcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/779656892/bcd.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/timer.o: ../../libraries//lib_pic/timer.c  .generated_files/flags/default/7d82be56ad272e9c16d72234da751e5396a7f0da .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/timer.c  -o ${OBJECTDIR}/_ext/412716567/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/oscillator.o: ../../libraries//lib_pic/oscillator.c  .generated_files/flags/default/81dd5fef00d95e339936aaffd1fef1135de1724d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/oscillator.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/oscillator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/oscillator.c  -o ${OBJECTDIR}/_ext/412716567/oscillator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/oscillator.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/i2c.o: ../../libraries//lib_pic/i2c.c  .generated_files/flags/default/60a80fedc824cad608a277e822ac5bd0e27bcbe1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/i2c.c  -o ${OBJECTDIR}/_ext/412716567/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/i2c.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/113394246/uart.o: ../../libraries/lib_pic/uart.c  .generated_files/flags/default/6d23e16f41bd3563fe5974f7080e47dfdb475280 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries/lib_pic/uart.c  -o ${OBJECTDIR}/_ext/113394246/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/113394246/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/412716567/pic_config.o: ../../libraries//lib_pic/pic_config.c  .generated_files/flags/default/642f5897a1e095cae31dbc8438439766d961527b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/412716567" 
	@${RM} ${OBJECTDIR}/_ext/412716567/pic_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/412716567/pic_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_pic/pic_config.c  -o ${OBJECTDIR}/_ext/412716567/pic_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/412716567/pic_config.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/90777089/misc.o: ../../libraries//lib_misc/misc.c  .generated_files/flags/default/e81a27ae832539f3e2591559c6082a9ac9b2937c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/90777089" 
	@${RM} ${OBJECTDIR}/_ext/90777089/misc.o.d 
	@${RM} ${OBJECTDIR}/_ext/90777089/misc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../libraries//lib_misc/misc.c  -o ${OBJECTDIR}/_ext/90777089/misc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/90777089/misc.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/interrupts_management.o: interrupts_management.c  .generated_files/flags/default/a6381fc2ba1b372877a2d3c9d11f118ac54a9e5a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts_management.o.d 
	@${RM} ${OBJECTDIR}/interrupts_management.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupts_management.c  -o ${OBJECTDIR}/interrupts_management.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupts_management.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/ef628b6b944f2bf04ac7d86437fec1caab008b2c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -O0 -I".." -I"../../libraries/" -I"../../libraries/lib_pic" -I"../../../headers" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../../libraries/lib_chips" -I"../../libraries/lib_pic" -I"../../libraries/lib_misc" -I"../../libraries/lib_lcd" -I"../../libraries" -I"../../libraries/lib_comp" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Pitechoid_QFP100_dsPIC33FJ256MC710.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
