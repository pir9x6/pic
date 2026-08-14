#ifndef LIB_PIC_PWM_H
#define LIB_PIC_PWM_H

/*****************************************************************************
* includes
******************************************************************************/
#include "xc.h"
#include "types.h"


/*****************************************************************************
* New types
******************************************************************************/
typedef enum
{
    PWM_ID_1 = 0,
    PWM_ID_2 = 1,
    PWM_ID_3 = 2,
    PWM_ID_4 = 3,
    PWM_ID_5 = 4,
    PWM_ID_6 = 5
}PWM_ID_t;

typedef enum
{
    PWM_FROM_TMR2 = 0,
    PWM_FROM_TMR3 = 1
}PWM_SOURCE_t;

typedef struct
{
    PWM_ID_t pwm_id;
    u16 freq;
    u8 duty;    /* 0 to 100 */
    PWM_SOURCE_t timer_source;
}PWM_CFG_t;


/*****************************************************************************
* Prototypes
******************************************************************************/
result_t pwm_init (const PWM_CFG_t *cfg);
result_t pwm_set_duty (const PWM_CFG_t *cfg);

#endif