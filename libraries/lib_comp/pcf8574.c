/*****************************************************************************
*   v1.0    2026-07-28  Original version (read & write validated)
******************************************************************************/

/*****************************************************************************
* Includes
******************************************************************************/
#include "i2c.h"
#include "pcf8574.h"
#include "types.h"

/*****************************************************************************
* Write on the port of PCF8574
******************************************************************************/
result_t pcf8574_write_port (I2C_BUS i2c_bus_id, u8 dev_addr, u8 data)
{
    if (i2c_start(i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write(i2c_bus_id, I2C_ADDR_WR(dev_addr)) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_write(i2c_bus_id, data) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_stop(i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}

/*****************************************************************************
* Read from the port of PCF8574
******************************************************************************/
result_t pcf8574_read_port (I2C_BUS i2c_bus_id, u8 dev_addr, u8 *data)
{
    if (i2c_start(i2c_bus_id) != SUCCESS)
        return ERROR;

    if (i2c_write(i2c_bus_id, I2C_ADDR_RD(dev_addr)) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_read(i2c_bus_id, I2C_NACK, data) != SUCCESS)
    {
        i2c_stop(i2c_bus_id);
        return ERROR;
    }

    if (i2c_stop(i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}


