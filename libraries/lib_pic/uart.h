#ifndef LIB_PIC_UART_H
#define LIB_PIC_UART_H

/*****************************************************************************
* Includes
******************************************************************************/
#include <xc.h>
#include "types.h"

/*****************************************************************************
* New types
******************************************************************************/
typedef enum
{
    UART_ID_1 = 0,
    UART_ID_2 = 1,
    UART_ID_3 = 2,
    UART_ID_4 = 3,
    UART_ID_5 = 4,
    UART_ID_6 = 5
}UART_ID;

typedef struct
{
    UART_ID uart_id;
    u32 baudrate;
}UART_CFG_t;

/*****************************************************************************
* Prototypes
******************************************************************************/
void     putch            (char txData);
result_t uart_init        (UART_CFG_t *cfg);
result_t uart_write       (UART_ID uart_id, u8 data);

#endif
