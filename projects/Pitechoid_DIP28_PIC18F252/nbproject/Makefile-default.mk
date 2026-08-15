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
FINAL_IMAGE=${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../../libraries/lib_pic/timer.c ../../libraries/lib_comp/tmp75.c ../../libraries/lib_pic/uart.c ../../libraries/lib_misc/log.c ../../libraries/lib_misc/misc.c ../../libraries/lib_comp/mma7660.c ../../libraries/lib_comp/pcf8574.c ../../libraries/lib_pic/i2c.c ../../libraries/lib_misc/i2c_tools.c ../../libraries/lib_pic/interrupts.c ../../libraries/lib_misc/bcd.c ../../libraries/lib_misc/date_time.c ../../libraries/lib_misc/delays.c ../../libraries/lib_comp/ds1337.c ../../libraries/lib_comp/ds1631.c ../../libraries/lib_comp/eeprom_i2c.c ../../libraries/lib_lcd/lcd_hd44780.c ../../libraries/lib_comp/ds1307.c ../../libraries/lib_comp/bh1750.c pin_manager.c main.c interrupts_management.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/113394246/timer.p1 ${OBJECTDIR}/_ext/779364575/tmp75.p1 ${OBJECTDIR}/_ext/113394246/uart.p1 ${OBJECTDIR}/_ext/779656892/log.p1 ${OBJECTDIR}/_ext/779656892/misc.p1 ${OBJECTDIR}/_ext/779364575/mma7660.p1 ${OBJECTDIR}/_ext/779364575/pcf8574.p1 ${OBJECTDIR}/_ext/113394246/i2c.p1 ${OBJECTDIR}/_ext/779656892/i2c_tools.p1 ${OBJECTDIR}/_ext/113394246/interrupts.p1 ${OBJECTDIR}/_ext/779656892/bcd.p1 ${OBJECTDIR}/_ext/779656892/date_time.p1 ${OBJECTDIR}/_ext/779656892/delays.p1 ${OBJECTDIR}/_ext/779364575/ds1337.p1 ${OBJECTDIR}/_ext/779364575/ds1631.p1 ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1 ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1 ${OBJECTDIR}/_ext/779364575/ds1307.p1 ${OBJECTDIR}/_ext/779364575/bh1750.p1 ${OBJECTDIR}/pin_manager.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/interrupts_management.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/113394246/timer.p1.d ${OBJECTDIR}/_ext/779364575/tmp75.p1.d ${OBJECTDIR}/_ext/113394246/uart.p1.d ${OBJECTDIR}/_ext/779656892/log.p1.d ${OBJECTDIR}/_ext/779656892/misc.p1.d ${OBJECTDIR}/_ext/779364575/mma7660.p1.d ${OBJECTDIR}/_ext/779364575/pcf8574.p1.d ${OBJECTDIR}/_ext/113394246/i2c.p1.d ${OBJECTDIR}/_ext/779656892/i2c_tools.p1.d ${OBJECTDIR}/_ext/113394246/interrupts.p1.d ${OBJECTDIR}/_ext/779656892/bcd.p1.d ${OBJECTDIR}/_ext/779656892/date_time.p1.d ${OBJECTDIR}/_ext/779656892/delays.p1.d ${OBJECTDIR}/_ext/779364575/ds1337.p1.d ${OBJECTDIR}/_ext/779364575/ds1631.p1.d ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1.d ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1.d ${OBJECTDIR}/_ext/779364575/ds1307.p1.d ${OBJECTDIR}/_ext/779364575/bh1750.p1.d ${OBJECTDIR}/pin_manager.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/interrupts_management.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/113394246/timer.p1 ${OBJECTDIR}/_ext/779364575/tmp75.p1 ${OBJECTDIR}/_ext/113394246/uart.p1 ${OBJECTDIR}/_ext/779656892/log.p1 ${OBJECTDIR}/_ext/779656892/misc.p1 ${OBJECTDIR}/_ext/779364575/mma7660.p1 ${OBJECTDIR}/_ext/779364575/pcf8574.p1 ${OBJECTDIR}/_ext/113394246/i2c.p1 ${OBJECTDIR}/_ext/779656892/i2c_tools.p1 ${OBJECTDIR}/_ext/113394246/interrupts.p1 ${OBJECTDIR}/_ext/779656892/bcd.p1 ${OBJECTDIR}/_ext/779656892/date_time.p1 ${OBJECTDIR}/_ext/779656892/delays.p1 ${OBJECTDIR}/_ext/779364575/ds1337.p1 ${OBJECTDIR}/_ext/779364575/ds1631.p1 ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1 ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1 ${OBJECTDIR}/_ext/779364575/ds1307.p1 ${OBJECTDIR}/_ext/779364575/bh1750.p1 ${OBJECTDIR}/pin_manager.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/interrupts_management.p1

# Source Files
SOURCEFILES=../../libraries/lib_pic/timer.c ../../libraries/lib_comp/tmp75.c ../../libraries/lib_pic/uart.c ../../libraries/lib_misc/log.c ../../libraries/lib_misc/misc.c ../../libraries/lib_comp/mma7660.c ../../libraries/lib_comp/pcf8574.c ../../libraries/lib_pic/i2c.c ../../libraries/lib_misc/i2c_tools.c ../../libraries/lib_pic/interrupts.c ../../libraries/lib_misc/bcd.c ../../libraries/lib_misc/date_time.c ../../libraries/lib_misc/delays.c ../../libraries/lib_comp/ds1337.c ../../libraries/lib_comp/ds1631.c ../../libraries/lib_comp/eeprom_i2c.c ../../libraries/lib_lcd/lcd_hd44780.c ../../libraries/lib_comp/ds1307.c ../../libraries/lib_comp/bh1750.c pin_manager.c main.c interrupts_management.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18LF252
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/113394246/timer.p1: ../../libraries/lib_pic/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/timer.p1 ../../libraries/lib_pic/timer.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/timer.d ${OBJECTDIR}/_ext/113394246/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/tmp75.p1: ../../libraries/lib_comp/tmp75.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/tmp75.p1 ../../libraries/lib_comp/tmp75.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/tmp75.d ${OBJECTDIR}/_ext/779364575/tmp75.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/tmp75.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113394246/uart.p1: ../../libraries/lib_pic/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/uart.p1 ../../libraries/lib_pic/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/uart.d ${OBJECTDIR}/_ext/113394246/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/log.p1: ../../libraries/lib_misc/log.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/log.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/log.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/log.p1 ../../libraries/lib_misc/log.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/log.d ${OBJECTDIR}/_ext/779656892/log.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/log.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/misc.p1: ../../libraries/lib_misc/misc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/misc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/misc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/misc.p1 ../../libraries/lib_misc/misc.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/misc.d ${OBJECTDIR}/_ext/779656892/misc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/misc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/mma7660.p1: ../../libraries/lib_comp/mma7660.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/mma7660.p1 ../../libraries/lib_comp/mma7660.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/mma7660.d ${OBJECTDIR}/_ext/779364575/mma7660.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/mma7660.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/pcf8574.p1: ../../libraries/lib_comp/pcf8574.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/pcf8574.p1 ../../libraries/lib_comp/pcf8574.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/pcf8574.d ${OBJECTDIR}/_ext/779364575/pcf8574.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/pcf8574.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113394246/i2c.p1: ../../libraries/lib_pic/i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/i2c.p1 ../../libraries/lib_pic/i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/i2c.d ${OBJECTDIR}/_ext/113394246/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/i2c_tools.p1: ../../libraries/lib_misc/i2c_tools.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/i2c_tools.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/i2c_tools.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/i2c_tools.p1 ../../libraries/lib_misc/i2c_tools.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/i2c_tools.d ${OBJECTDIR}/_ext/779656892/i2c_tools.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/i2c_tools.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113394246/interrupts.p1: ../../libraries/lib_pic/interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/interrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/interrupts.p1 ../../libraries/lib_pic/interrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/interrupts.d ${OBJECTDIR}/_ext/113394246/interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/bcd.p1: ../../libraries/lib_misc/bcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/bcd.p1 ../../libraries/lib_misc/bcd.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/bcd.d ${OBJECTDIR}/_ext/779656892/bcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/bcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/date_time.p1: ../../libraries/lib_misc/date_time.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/date_time.p1 ../../libraries/lib_misc/date_time.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/date_time.d ${OBJECTDIR}/_ext/779656892/date_time.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/date_time.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/delays.p1: ../../libraries/lib_misc/delays.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/delays.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/delays.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/delays.p1 ../../libraries/lib_misc/delays.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/delays.d ${OBJECTDIR}/_ext/779656892/delays.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/delays.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/ds1337.p1: ../../libraries/lib_comp/ds1337.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/ds1337.p1 ../../libraries/lib_comp/ds1337.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/ds1337.d ${OBJECTDIR}/_ext/779364575/ds1337.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/ds1337.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/ds1631.p1: ../../libraries/lib_comp/ds1631.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/ds1631.p1 ../../libraries/lib_comp/ds1631.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/ds1631.d ${OBJECTDIR}/_ext/779364575/ds1631.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/ds1631.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1: ../../libraries/lib_comp/eeprom_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1 ../../libraries/lib_comp/eeprom_i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.d ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1: ../../libraries/lib_lcd/lcd_hd44780.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113398275" 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1 ../../libraries/lib_lcd/lcd_hd44780.c 
	@-${MV} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.d ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/ds1307.p1: ../../libraries/lib_comp/ds1307.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1307.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1307.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/ds1307.p1 ../../libraries/lib_comp/ds1307.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/ds1307.d ${OBJECTDIR}/_ext/779364575/ds1307.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/ds1307.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/bh1750.p1: ../../libraries/lib_comp/bh1750.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/bh1750.p1 ../../libraries/lib_comp/bh1750.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/bh1750.d ${OBJECTDIR}/_ext/779364575/bh1750.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/bh1750.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/pin_manager.p1: pin_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/pin_manager.p1 pin_manager.c 
	@-${MV} ${OBJECTDIR}/pin_manager.d ${OBJECTDIR}/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/interrupts_management.p1: interrupts_management.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts_management.p1.d 
	@${RM} ${OBJECTDIR}/interrupts_management.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/interrupts_management.p1 interrupts_management.c 
	@-${MV} ${OBJECTDIR}/interrupts_management.d ${OBJECTDIR}/interrupts_management.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/interrupts_management.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/113394246/timer.p1: ../../libraries/lib_pic/timer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/timer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/timer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/timer.p1 ../../libraries/lib_pic/timer.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/timer.d ${OBJECTDIR}/_ext/113394246/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/tmp75.p1: ../../libraries/lib_comp/tmp75.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/tmp75.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/tmp75.p1 ../../libraries/lib_comp/tmp75.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/tmp75.d ${OBJECTDIR}/_ext/779364575/tmp75.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/tmp75.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113394246/uart.p1: ../../libraries/lib_pic/uart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/uart.p1 ../../libraries/lib_pic/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/uart.d ${OBJECTDIR}/_ext/113394246/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/log.p1: ../../libraries/lib_misc/log.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/log.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/log.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/log.p1 ../../libraries/lib_misc/log.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/log.d ${OBJECTDIR}/_ext/779656892/log.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/log.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/misc.p1: ../../libraries/lib_misc/misc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/misc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/misc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/misc.p1 ../../libraries/lib_misc/misc.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/misc.d ${OBJECTDIR}/_ext/779656892/misc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/misc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/mma7660.p1: ../../libraries/lib_comp/mma7660.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/mma7660.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/mma7660.p1 ../../libraries/lib_comp/mma7660.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/mma7660.d ${OBJECTDIR}/_ext/779364575/mma7660.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/mma7660.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/pcf8574.p1: ../../libraries/lib_comp/pcf8574.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/pcf8574.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/pcf8574.p1 ../../libraries/lib_comp/pcf8574.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/pcf8574.d ${OBJECTDIR}/_ext/779364575/pcf8574.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/pcf8574.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113394246/i2c.p1: ../../libraries/lib_pic/i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/i2c.p1 ../../libraries/lib_pic/i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/i2c.d ${OBJECTDIR}/_ext/113394246/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/i2c_tools.p1: ../../libraries/lib_misc/i2c_tools.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/i2c_tools.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/i2c_tools.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/i2c_tools.p1 ../../libraries/lib_misc/i2c_tools.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/i2c_tools.d ${OBJECTDIR}/_ext/779656892/i2c_tools.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/i2c_tools.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113394246/interrupts.p1: ../../libraries/lib_pic/interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113394246" 
	@${RM} ${OBJECTDIR}/_ext/113394246/interrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113394246/interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113394246/interrupts.p1 ../../libraries/lib_pic/interrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/113394246/interrupts.d ${OBJECTDIR}/_ext/113394246/interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113394246/interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/bcd.p1: ../../libraries/lib_misc/bcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/bcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/bcd.p1 ../../libraries/lib_misc/bcd.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/bcd.d ${OBJECTDIR}/_ext/779656892/bcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/bcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/date_time.p1: ../../libraries/lib_misc/date_time.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/date_time.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/date_time.p1 ../../libraries/lib_misc/date_time.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/date_time.d ${OBJECTDIR}/_ext/779656892/date_time.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/date_time.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779656892/delays.p1: ../../libraries/lib_misc/delays.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779656892" 
	@${RM} ${OBJECTDIR}/_ext/779656892/delays.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779656892/delays.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779656892/delays.p1 ../../libraries/lib_misc/delays.c 
	@-${MV} ${OBJECTDIR}/_ext/779656892/delays.d ${OBJECTDIR}/_ext/779656892/delays.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779656892/delays.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/ds1337.p1: ../../libraries/lib_comp/ds1337.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1337.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/ds1337.p1 ../../libraries/lib_comp/ds1337.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/ds1337.d ${OBJECTDIR}/_ext/779364575/ds1337.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/ds1337.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/ds1631.p1: ../../libraries/lib_comp/ds1631.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1631.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/ds1631.p1 ../../libraries/lib_comp/ds1631.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/ds1631.d ${OBJECTDIR}/_ext/779364575/ds1631.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/ds1631.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1: ../../libraries/lib_comp/eeprom_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1 ../../libraries/lib_comp/eeprom_i2c.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.d ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/eeprom_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1: ../../libraries/lib_lcd/lcd_hd44780.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/113398275" 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1.d 
	@${RM} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1 ../../libraries/lib_lcd/lcd_hd44780.c 
	@-${MV} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.d ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/113398275/lcd_hd44780.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/ds1307.p1: ../../libraries/lib_comp/ds1307.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1307.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/ds1307.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/ds1307.p1 ../../libraries/lib_comp/ds1307.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/ds1307.d ${OBJECTDIR}/_ext/779364575/ds1307.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/ds1307.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/779364575/bh1750.p1: ../../libraries/lib_comp/bh1750.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/779364575" 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.p1.d 
	@${RM} ${OBJECTDIR}/_ext/779364575/bh1750.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/779364575/bh1750.p1 ../../libraries/lib_comp/bh1750.c 
	@-${MV} ${OBJECTDIR}/_ext/779364575/bh1750.d ${OBJECTDIR}/_ext/779364575/bh1750.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/779364575/bh1750.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/pin_manager.p1: pin_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/pin_manager.p1 pin_manager.c 
	@-${MV} ${OBJECTDIR}/pin_manager.d ${OBJECTDIR}/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/interrupts_management.p1: interrupts_management.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts_management.p1.d 
	@${RM} ${OBJECTDIR}/interrupts_management.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/interrupts_management.p1 interrupts_management.c 
	@-${MV} ${OBJECTDIR}/interrupts_management.d ${OBJECTDIR}/interrupts_management.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/interrupts_management.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=pickit3  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-7dc0-7fff -mram=default,-5f4-5ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../libraries/lib_comp" -I"../../libraries/lib_lcd" -I"../../libraries/lib_misc" -I"../../libraries/lib_pic" -I"." -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Pitechoid_DIP28_PIC18F252.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
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
