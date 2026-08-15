/*****************************************************************************
* Title:    external interrupt
******************************************************************************
* Versions: v1.0    23/11/2014  MPLAB: vx.x   XC16: vx.x
*                   Initial version
*           v1.1    08/08/2026  MPLAB: 6.05   XC-DSC: 4.00
*                   Added support for all channels
******************************************************************************/


/******************************************************************************
* Includes
******************************************************************************/
#include "ext_int.h"
#include "types.h"
#include <xc.h>


/******************************************************************************
* Initialisation
******************************************************************************/
result_t ext_int_init(const EXT_INT_CFG_t *cfg)
{
    if (cfg->ext_int_id == EXT_INT_ID_0)
    {
        _INT0EP = cfg->edge;    /* edge */
        _INT0IF = 0;            /* clear IT flag */
        _INT0IE = 1;            /* Enable IT */
    }
    else if (cfg->ext_int_id == EXT_INT_ID_1)
    {
        _INT1EP = cfg->edge;    /* edge */
        _INT1IF = 0;            /* clear IT flag */
        _INT1IE = 1;            /* Enable IT */
    }
    else if (cfg->ext_int_id == EXT_INT_ID_2)
    {
        _INT2EP = cfg->edge;    /* edge */
        _INT2IF = 0;            /* clear IT flag */
        _INT2IE = 1;            /* Enable IT */
    }
    else if (cfg->ext_int_id == EXT_INT_ID_3)
    {
        _INT3EP = cfg->edge;    /* edge */
        _INT3IF = 0;            /* clear IT flag */
        _INT3IE = 1;            /* Enable IT */
    }
    else if (cfg->ext_int_id == EXT_INT_ID_4)
    {
        _INT4EP = cfg->edge;    /* edge */
        _INT4IF = 0;            /* clear IT flag */
        _INT4IE = 1;            /* Enable IT */
    }
    else
    {
        return ERROR;
    }

    return SUCCESS;
}

