#ifndef LIB_COMP_DS1631_H
#define LIB_COMP_DS1631_H

/*****************************************************************************
* Includes
******************************************************************************/
#include "i2c.h"
#include "types.h"

/*****************************************************************************
* Configuration
******************************************************************************/
#define DS1631_CFG_DONE         0x80
#define DS1631_CFG_THF          0x40
#define DS1631_CFG_TLF          0x20
#define DS1631_CFG_NVB          0x10

#define DS1631_CFG_RES_9B       0x00
#define DS1631_CFG_RES_10B      0x04
#define DS1631_CFG_RES_11B      0x08
#define DS1631_CFG_RES_12B      0x0C

#define DS1631_CFG_CONTINUOUS   0x00
#define DS1631_CFG_ONE_SHOT     0x01

/*****************************************************************************
* Registers
******************************************************************************/
#define DS1631_REG_STOP_CONVERT     0x22
#define DS1631_REG_START_CONVERT    0x51
#define DS1631_REG_ACCESS_TH        0xA1
#define DS1631_REG_ACCESS_TL        0xA2
#define DS1631_REG_TEMPERATURE      0xAA
#define DS1631_REG_ACCESS_CONFIG    0xAC
#define DS1631_REG_SOFTWARE_POR     0x54

/*****************************************************************************
* Prototypes
******************************************************************************/
result_t ds1631_config      (I2C_BUS i2c_bus_id, u8 dev_addr, u8 config);
result_t ds1631_start_conv  (I2C_BUS i2c_bus_id, u8 dev_addr);
result_t ds1631_stop_conv   (I2C_BUS i2c_bus_id, u8 dev_addr);
result_t ds1631_is_conv_done(I2C_BUS i2c_bus_id, u8 dev_addr, bool_t *done);
result_t ds1631_read_temp   (I2C_BUS i2c_bus_id, u8 dev_addr, float *temp);

#endif
