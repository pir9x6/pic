#ifndef LIB_COMP_DS1621_H
#define LIB_COMP_DS1621_H

/*****************************************************************************
* Includes
******************************************************************************/
#include "i2c.h"
#include "types.h"

/*****************************************************************************
* Registers
******************************************************************************/
#define DS1621_CMD_READ_TEMP        0xAA
#define DS1621_CMD_READ_COUNTER     0xA8
#define DS1621_CMD_READ_SLOPE       0xA9
#define DS1621_CMD_ACCESS_TH        0xA1
#define DS1621_CMD_ACCESS_TL        0xA2
#define DS1621_CMD_ACCESS_CONFIG    0xAC
#define DS1621_CMD_START_CONVERT    0xEE
#define DS1621_CMD_STOP_CONVERT     0x22

/*****************************************************************************
* Prototypes
******************************************************************************/
result_t ds1621_config     (I2C_BUS i2c_bus_id, u8 dev_addr);
result_t ds1621_start_conv (I2C_BUS i2c_bus_id, u8 dev_addr);
result_t ds1621_read_temp  (I2C_BUS i2c_bus_id, u8 dev_addr, float *temp);

#endif
