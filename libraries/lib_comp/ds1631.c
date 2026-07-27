/*****************************************************************************
* Includes
******************************************************************************/
#include "ds1631.h"
#include "i2c.h"
#include "types.h"

/*****************************************************************************
* Docs
******************************************************************************/
// https://www.analog.com/media/en/technical-documentation/data-sheets/ds1631-ds1731.pdf
// https://www.analog.com/en/resources/technical-articles/temperature-sensor-ic-ds1631.html

/* In continuous mode:
- Config
- Start conversion
- Loop
    - Wait for conversion to complete (ds1631_is_conv_done or 800 ms delay)
    - Read temperature
*/

/*****************************************************************************
* Write Configuration
******************************************************************************/
result_t ds1631_config (I2C_BUS i2c_bus_id, u8 dev_addr, u8 config)
{
    /* start temperature acquisition */
    if (i2c_start (i2c_bus_id) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, DS1631_REG_ACCESS_CONFIG) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, config) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_stop  (i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}


/*****************************************************************************
* Start converstion
******************************************************************************/
result_t ds1631_start_conv (I2C_BUS i2c_bus_id, u8 dev_addr)
{
    /* start temperature conversion */
    if (i2c_start (i2c_bus_id) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, DS1631_REG_START_CONVERT) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_stop  (i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}


/*****************************************************************************
* Check if conversion is done
* Used only when the DS1631 is configured in one-shot mode
******************************************************************************/
result_t ds1631_is_conv_done (I2C_BUS i2c_bus_id, u8 dev_addr, bool_t *done)
{
    u8 config;

    if (i2c_read_reg(i2c_bus_id, dev_addr, DS1631_REG_ACCESS_CONFIG, &config) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (config & 0x80){
        *done = TRUE;
    }
    else{
        *done = FALSE;
    }

    return SUCCESS;
}


/*****************************************************************************
* Stop conversion
******************************************************************************/
result_t ds1631_stop_conv (I2C_BUS i2c_bus_id, u8 dev_addr)
{
    /* stop temperature acquisition */
    if (i2c_start (i2c_bus_id) != SUCCESS)
      {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, DS1631_REG_STOP_CONVERT) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_stop  (i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}


/*****************************************************************************
* Read temperature
******************************************************************************/
result_t ds1631_read_temp (I2C_BUS i2c_bus_id, u8 dev_addr, float *temp)
{
    u8 temp_msb, temp_lsb;
    s16 raw;

    /* get temperature */
    if (i2c_start (i2c_bus_id) != SUCCESS)
       {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write (i2c_bus_id, DS1631_REG_TEMPERATURE) != SUCCESS)
       {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_rstart(i2c_bus_id) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write(i2c_bus_id, I2C_ADDR_RD(dev_addr)) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_read  (i2c_bus_id, I2C_ACK,  &temp_msb) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_read  (i2c_bus_id, I2C_NACK, &temp_lsb) != SUCCESS)
       {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_stop  (i2c_bus_id) != SUCCESS)
        return ERROR;

    raw = ((s16)temp_msb << 8) | temp_lsb;

    *temp = (float)raw / 256.0f;    /* /!\ 256.0f for 12-bit resolution only */

    return SUCCESS;
}

