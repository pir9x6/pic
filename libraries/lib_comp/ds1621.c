/*****************************************************************************
* Includes
******************************************************************************/
#include "ds1621.h"
#include "i2c.h"
#include "types.h"



/******************************** NOT YET TESTED *****************************/



/*****************************************************************************
* Write Configuration
******************************************************************************/
result_t ds1621_config (I2C_BUS i2c_bus_id, u8 dev_addr)
{
    /* configure sensor */
    if (i2c_start (i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, DS1621_CMD_ACCESS_CONFIG) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, 0x00) != SUCCESS)
        return ERROR;

    if (i2c_stop  (i2c_bus_id) != SUCCESS)
        return ERROR;
}


/*****************************************************************************
* Start converstion
******************************************************************************/
result_t ds1621_start_conv (I2C_BUS i2c_bus_id, u8 dev_addr)
{
    /* start temperature conversion */
    if (i2c_start (i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, DS1621_CMD_START_CONVERT) != SUCCESS)
        return ERROR;

    if (i2c_stop  (i2c_bus_id) != SUCCESS)
        return ERROR;
}


/*****************************************************************************
* Read temperature
******************************************************************************/
result_t ds1621_read_temp (I2C_BUS i2c_bus_id, u8 dev_addr, float *temp)
{
    u8 temp_msb, temp_lsb;

    /* get temperature */
    if (i2c_start (i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, DS1621_CMD_READ_TEMP) != SUCCESS)
        return ERROR;

    if (i2c_rstart(i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write (i2c_bus_id, I2C_ADDR_RD(dev_addr)) != SUCCESS)
        return ERROR;

    if (i2c_read  (i2c_bus_id, I2C_ACK,  &temp_msb) != SUCCESS)
        return ERROR;

    if (i2c_read  (i2c_bus_id, I2C_NACK, temp_lsb) != SUCCESS)
        return ERROR;

    if (i2c_stop  (i2c_bus_id) != SUCCESS)
        return ERROR;

    *temp = (float)((int8_t)temp_msb);

    if (temp_lsb & 0x80)
    {
        if (*temp >= 0)
            *temp += 0.5f;
        else
            *temp -= 0.5f;
    }

    return SUCCESS;
}

