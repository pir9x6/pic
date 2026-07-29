/*****************************************************************************
*   v1.0    2026-07-28  Original version (read validated)
******************************************************************************/

/*****************************************************************************
* Includes
******************************************************************************/
#include "bh1750.h"
#include "i2c.h"
#include "types.h"

/*****************************************************************************
* Docs
******************************************************************************/
// https://www.mouser.com/datasheet/2/348/bh1750fvi-e-186247.pdf


/*****************************************************************************
* Init sensor
******************************************************************************/
result_t bh1750_init (I2C_BUS i2c_bus_id, u8 dev_addr)
{
    // config the chip for a high resolution continuous measure
    if (i2c_start (i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, BH1750_REG_CONT_L_RES) != SUCCESS)
        return ERROR;

    if (i2c_stop (i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}


/*****************************************************************************
* Get Light from sensor
******************************************************************************/
result_t bh1750_get_light (I2C_BUS i2c_bus_id, u8 dev_addr, float *light)
{
    u8 msb, lsb;

    if (i2c_start(i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write(i2c_bus_id, I2C_ADDR_RD(dev_addr)) != SUCCESS)
        return ERROR;

    /* Get MSB */
    if (i2c_read (i2c_bus_id, I2C_ACK,  &msb) != SUCCESS)
        return ERROR;

    /* Get LSB */
    if (i2c_read (i2c_bus_id, I2C_NACK, &lsb) != SUCCESS)
        return ERROR;

    if (i2c_stop (i2c_bus_id) != SUCCESS)
        return ERROR;

    *light = ((msb << 8) | lsb) / 1.2;

    /* workaround: the light goes negative when higher than 32768 */
    if (*light < 0)
        *light = 32768;

    return SUCCESS;
}
