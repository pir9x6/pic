#pragma once

/*****************************************************************************
* includes
******************************************************************************/
#include "types.h"

/*****************************************************************************
* Defines
******************************************************************************/
#define EXT_INT_POS     0
#define EXT_INT_NEG     1

/*****************************************************************************
* New types
******************************************************************************/
typedef enum
{
    EXT_INT_ID_0 = 0,
    EXT_INT_ID_1 = 1,
    EXT_INT_ID_2 = 2,
    EXT_INT_ID_3 = 3,
    EXT_INT_ID_4 = 4
}EXT_INT_ID_t;

typedef enum
{
    POSITIVE = 0,
    NEGATIVE = 1
}EXT_INT_EDGE_t;

typedef struct
{
    EXT_INT_ID_t ext_int_id;
    EXT_INT_EDGE_t edge;
}EXT_INT_CFG_t;

result_t ext_int_init(const EXT_INT_CFG_t *cfg);
