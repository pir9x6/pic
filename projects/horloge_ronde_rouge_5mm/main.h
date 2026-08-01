#ifndef _MAIN_H_
#define _MAIN_H_

#include "delays.h"
#include "ds1307.h"
#include "ds1621.h"
#include "i2c.h"
#include "i2c_tools.h"
#include "hardware_profile.h"
#include "misc.h"
#include "pic_compiler.h"
#include "uart.h"
#include "types.h"

#define Select_Aff_1            AFF1 = 1;   AFF2 = 0;   AFF3 = 0;   AFF4 = 0;
#define Select_Aff_2            AFF1 = 0;   AFF2 = 1;   AFF3 = 0;   AFF4 = 0;
#define Select_Aff_3            AFF1 = 0;   AFF2 = 0;   AFF3 = 1;   AFF4 = 0;
#define Select_Aff_4            AFF1 = 0;   AFF2 = 0;   AFF3 = 0;   AFF4 = 1;
#define Select_Aff_None         AFF1 = 0;   AFF2 = 0;   AFF3 = 0;   AFF4 = 0;
#define Select_Aff_All          AFF1 = 1;   AFF2 = 1;   AFF3 = 1;   AFF4 = 1;

#define REG4094_PULSE           CLOCK = 1;  Nop();  Nop();  Nop();  CLOCK = 0;

void reset_sec_led (void);

typedef enum eCHANGE
{
    CHANGE_NONE = 0,
    CHANGE_DAY,
    CHANGE_MTH,
    CHANGE_MIN,
    CHANGE_HRS
} CHANGE;

#endif
