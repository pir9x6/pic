/*****************************************************************************
*   v1.0    2026-07-28  Original version (read validated)
******************************************************************************/

/*****************************************************************************
* Includes
******************************************************************************/
#include "i2c.h"
#include "mma7660.h"
#include "types.h"

/*****************************************************************************
* Docs
******************************************************************************/
// https://www.nxp.com/docs/en/data-sheet/MMA7660FC.pdf

static result_t _read_raw   (I2C_BUS i2c_bus_id, u8 dev_addr, s8 *x, s8 *y, s8 *z);

/*****************************************************************************
* Constants
******************************************************************************/
const s8 MMA_XY[64] = {
      0,   3,   5,   8,  11,  14,  16,  19,
     22,  25,  28,  31,  34,  38,  41,  45,
     49,  53,  58,  63,  70,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0, -80, -70, -63, -58, -53,
    -49, -45, -41, -38, -34, -31, -28, -25,
    -22, -19, -16, -14, -11,  -8,  -5,  -3
};

const s8 MMA_Z[64]  = {
     90,  87,  84,  82,  79,  76,  74,  70,
     68,  65,  62,  59,  56,  52,  49,  45,
     41,  37,  32,  27,  20,  10,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0, -10, -20, -27, -32, -37,
    -41, -45, -49, -52, -56, -59, -52, -65,
    -68, -71, -74, -76, -79, -82, -85, -87
};

/*****************************************************************************
* Initialize the sensor
******************************************************************************/
result_t mma7660_init (I2C_BUS i2c_bus_id, u8 dev_addr)
{
    /* stby mode */
    if (i2c_write_reg (i2c_bus_id, dev_addr, MMA7660_REG_MODE, MMA7660_MODE_STBY) != SUCCESS)
        return ERROR;

    /* no interrupts */
    if (i2c_write_reg (i2c_bus_id, dev_addr, MMA7660_REG_INT,  0x00) != SUCCESS)
        return ERROR;

    /* sampling rate = 120sps */
    if (i2c_write_reg (i2c_bus_id, dev_addr, MMA7660_REG_SR,   MMA7660_SR_120_SPS) != SUCCESS)
        return ERROR;

    /* enable accelorometer */
    if (i2c_write_reg (i2c_bus_id, dev_addr, MMA7660_REG_MODE, MMA7660_MODE_ACTIVE) != SUCCESS)
        return ERROR;

    return SUCCESS;
}

/*****************************************************************************
* Get X, Y, Z acceleration values from sensor
******************************************************************************/
static result_t _read_raw (I2C_BUS i2c_bus_id, u8 dev_addr, s8 *x, s8 *y, s8 *z)
{
    u8 raw_x;
    u8 raw_y;
    u8 raw_z;

    if (i2c_read_reg(i2c_bus_id, dev_addr, MMA7660_REG_X, &raw_x) != SUCCESS)
        return ERROR;

    if (i2c_read_reg(i2c_bus_id, dev_addr, MMA7660_REG_Y, &raw_y) != SUCCESS)
        return ERROR;

    if (i2c_read_reg(i2c_bus_id, dev_addr, MMA7660_REG_Z, &raw_z) != SUCCESS)
        return ERROR;

    /* Sign extension from 6 bits to 8 bits */
    if (raw_x & 0x20)
        raw_x |= 0xC0;
    else
        raw_x &= 0x3F;

    if (raw_y & 0x20)
        raw_y |= 0xC0;
    else
        raw_y &= 0x3F;

    if (raw_z & 0x20)
        raw_z |= 0xC0;
    else
        raw_z &= 0x3F;

    *x = (s8)raw_x;
    *y = (s8)raw_y;
    *z = (s8)raw_z;

    return SUCCESS;
}

result_t mma7660_read_accel(I2C_BUS i2c_bus_id, u8 dev_addr, float *x, float *y, float *z)
{
    s8 raw_x;
    s8 raw_y;
    s8 raw_z;

    if (_read_raw(i2c_bus_id, dev_addr, &raw_x, &raw_y, &raw_z) != SUCCESS)
    {
        return ERROR;
    }

    *x = (float)raw_x * MMA7660_SENSITIVITY;
    *y = (float)raw_y * MMA7660_SENSITIVITY;
    *z = (float)raw_z * MMA7660_SENSITIVITY;

    return SUCCESS;
}

/*****************************************************************************
* Get angles from sensor
******************************************************************************/
result_t mma7660_read_angles (I2C_BUS i2c_bus_id, u8 dev_addr, s8 *x, s8 *y, s8 *z)
{
    u8 tmp = 0;

    if ((x == NULL) || (y == NULL) || (z == NULL))
        return ERROR;

    if (i2c_read_reg(i2c_bus_id, dev_addr, MMA7660_REG_X, &tmp) != SUCCESS)
        return ERROR;
    *x = MMA_XY[tmp];

    if (i2c_read_reg(i2c_bus_id, dev_addr, MMA7660_REG_Y, &tmp) != SUCCESS)
        return ERROR;
    *y = MMA_XY[tmp];

    if (i2c_read_reg(i2c_bus_id, dev_addr, MMA7660_REG_Z, &tmp) != SUCCESS)
        return ERROR;
    *z = MMA_Z [tmp];

    return SUCCESS;
}
