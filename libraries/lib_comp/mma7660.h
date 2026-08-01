#ifndef LIB_COMP_MAX7660_H
#define LIB_COMP_MAX7660_H

/*****************************************************************************
* Includes
******************************************************************************/
#include "i2c.h"
#include "types.h"

/*****************************************************************************
* Registers
******************************************************************************/
#define MMA7660_REG_X               0x00
#define MMA7660_REG_Y               0x01
#define MMA7660_REG_Z               0x02
#define MMA7660_REG_TILT            0x03
#define MMA7660_REG_RATE            0x04
#define MMA7660_REG_SLEEP           0x05
#define MMA7660_REG_INT             0x06
#define MMA7660_REG_MODE            0x07
#define MMA7660_REG_SR              0x08
#define MMA7660_REG_TAP             0x09
#define MMA7660_REG_TAP_CNT         0x0A

/*****************************************************************************
* Definitions
******************************************************************************/
#define MMA7660_MODE_STBY           0x00
#define MMA7660_MODE_ACTIVE         0x01
#define MMA7660_MODE_AUTO_WAKE      0x02
#define MMA7660_MODE_AUTO_SLEEP     0x04
#define MMA7660_MODE_PRESCALER      0x10
#define MMA7660_MODE_INT_TYPE       0x20
#define MMA7660_MODE_IPP            0x40
#define MMA7660_MODE_IAH            0x80

#define MMA7660_SR_120_SPS          0x00
#define MMA7660_SR_64_SPS           0x01
#define MMA7660_SR_32_SPS           0x02
#define MMA7660_SR_16_SPS           0x03

#define MMA7660_RANGE_G             3.0f
#define MMA7660_COUNTS              64.0f
#define MMA7660_SENSITIVITY         (MMA7660_RANGE_G / MMA7660_COUNTS)

/*****************************************************************************
* Prototypes
******************************************************************************/
result_t mma7660_init       (I2C_BUS i2c_bus_id, u8 dev_addr);
result_t mma7660_read_angles(I2C_BUS i2c_bus_id, u8 dev_addr, s8 *x, s8 *y, s8 *z);
result_t mma7660_read_accel (I2C_BUS i2c_bus_id, u8 dev_addr, float *x, float *y, float *z);

#endif
