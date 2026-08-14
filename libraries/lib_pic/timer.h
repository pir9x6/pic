#ifndef LIB_PIC_TIMER_H
#define LIB_PIC_TIMER_H

/*****************************************************************************
* includes
******************************************************************************/
#include "types.h"
#include "xc.h"


/*****************************************************************************
* New types
******************************************************************************/
typedef enum
{
    TIMER_ID_0 = 0,
    TIMER_ID_1,
    TIMER_ID_2,
    TIMER_ID_3,
    TIMER_ID_4,
    TIMER_ID_5,
    TIMER_ID_6,
    TIMER_ID_7,
    TIMER_ID_8,
    TIMER_ID_9,
    TIMER_ID_2_3,
    TIMER_ID_4_5,
    TIMER_ID_6_7,
    TIMER_ID_8_9
}TIMER_ID_t;

typedef enum
{
#if defined (_18F252) || \
    defined (_18LF252)

    TMR_PRESCALER_1 = 0,
    TMR_PRESCALER_4,
    TMR_PRESCALER_8,
    TMR_PRESCALER_16

#elif defined (_18F26K42) || \
      defined (_18F57K42)

    TMR_PRESCALER_1 = 0,
    TMR_PRESCALER_2,
    TMR_PRESCALER_4,
    TMR_PRESCALER_8,
    TMR_PRESCALER_16,
    TMR_PRESCALER_32,
    TMR_PRESCALER_64,
    TMR_PRESCALER_128,
    TMR_PRESCALER_256,
    TMR_PRESCALER_512,
    TMR_PRESCALER_1024,
    TMR_PRESCALER_2048,
    TMR_PRESCALER_4096,
    TMR_PRESCALER_8192,
    TMR_PRESCALER_16384,
    TMR_PRESCALER_32768,

#elif defined(__PIC24F__) || \
      defined(__dsPIC33F__)

    TMR_PRESCALER_1 = 0,
    TMR_PRESCALER_8,
    TMR_PRESCALER_64,
    TMR_PRESCALER_256

#else

    #error "TMR_PRESCALER: Unknown processor."

#endif
}TIMER_PRESCALER_t;

typedef enum
{
#if defined (_18F252) || \
    defined (_18LF252) || \
    defined (_18F26K42) || \
    defined (_18F57K42)

    TMR_POSTSCALER_1 = 0,
    TMR_POSTSCALER_2,
    TMR_POSTSCALER_3,
    TMR_POSTSCALER_4,
    TMR_POSTSCALER_5,
    TMR_POSTSCALER_6,
    TMR_POSTSCALER_7,
    TMR_POSTSCALER_8,
    TMR_POSTSCALER_9,
    TMR_POSTSCALER_10,
    TMR_POSTSCALER_11,
    TMR_POSTSCALER_12,
    TMR_POSTSCALER_13,
    TMR_POSTSCALER_14,
    TMR_POSTSCALER_15,
    TMR_POSTSCALER_16,

#elif defined(__PIC24F__) || \
      defined(__dsPIC33F__)

    TMR_POSTSCALER_NONE = 0

#else

    #error "TMR_POSTSCALER: Unknown processor."

#endif
}TIMER_POSTSCALER_t;

typedef struct
{
    TIMER_ID_t timer_id;
    TIMER_PRESCALER_t timer_prescaler;
    TIMER_POSTSCALER_t timer_postscaler;
#if defined (__18CXX) || defined (_PIC18)
    u16 period;
#elif(__PIC24F__) || defined(__dsPIC33F__)
    u32 period;
#endif
}TIMER_CFG_t;


/*****************************************************************************
* Prototype
******************************************************************************/
result_t timer_init(const TIMER_CFG_t *cfg);

#endif