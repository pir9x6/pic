#ifndef LIB_COMP_EEPROM_I2C_H
#define LIB_COMP_EEPROM_I2C_H

/*****************************************************************************
 * Includes
 * ***************************************************************************/
#include "types.h"
#include "i2c.h"

/*****************************************************************************
 * Types
 * ***************************************************************************/
typedef struct
{
    u32 size;
    u16 page_size;
    u8 addr_bytes;
    u8 write_time_ms;
    u8 block_bits;
    u8 block_shift;
} EEPROM_CFG;

const EEPROM_CFG EEPROM_24LC01 =
{
    .size           = 128,
    .page_size      = 8,
    .addr_bytes     = 1,
    .write_time_ms  = 5,
    .block_bits     = 0,
    .block_shift    = 0
};


const EEPROM_CFG EEPROM_24LC02 =
{
    .size           = 256,
    .page_size      = 8,
    .addr_bytes     = 1,
    .write_time_ms  = 5,
    .block_bits     = 0,
    .block_shift    = 0
};


const EEPROM_CFG EEPROM_24LC04 =
{
    .size           = 512,
    .page_size      = 16,
    .addr_bytes     = 1,
    .write_time_ms  = 5,
    .block_bits     = 1,
    .block_shift    = 1
};


const EEPROM_CFG EEPROM_24LC08 =
{
    .size           = 1024,
    .page_size      = 16,
    .addr_bytes     = 1,
    .write_time_ms  = 5,
    .block_bits     = 2,
    .block_shift    = 1
};


const EEPROM_CFG EEPROM_24LC16 =
{
    .size           = 2048,
    .page_size      = 16,
    .addr_bytes     = 1,
    .write_time_ms  = 5,
    .block_bits     = 3,
    .block_shift    = 1
};


const EEPROM_CFG EEPROM_24LC32 =
{
    .size           = 4096,
    .page_size      = 32,
    .addr_bytes     = 2,
    .write_time_ms  = 5,
    .block_bits     = 0,
    .block_shift    = 0
};


const EEPROM_CFG EEPROM_24LC64 =
{
    .size           = 8192,
    .page_size      = 32,
    .addr_bytes     = 2,
    .write_time_ms  = 5,
    .block_bits     = 0,
    .block_shift    = 0
};


const EEPROM_CFG EEPROM_24LC128 =
{
    .size           = 16384,
    .page_size      = 64,
    .addr_bytes     = 2,
    .write_time_ms  = 5,
    .block_bits     = 0,
    .block_shift    = 0
};


const EEPROM_CFG EEPROM_24LC256 =
{
    .size           = 32768,
    .page_size      = 64,
    .addr_bytes     = 2,
    .write_time_ms  = 5,
    .block_bits     = 0,
    .block_shift    = 0
};


const EEPROM_CFG EEPROM_24LC512 =
{
    .size           = 65536,
    .page_size      = 128,
    .addr_bytes     = 2,
    .write_time_ms  = 5,
    .block_bits     = 0,
    .block_shift    = 0
};


const EEPROM_CFG EEPROM_24LC1025 =
{
    .size           = 131072,
    .page_size      = 128,
    .addr_bytes     = 2,
    .write_time_ms  = 5,
    .block_bits     = 1,
    .block_shift    = 2
};

 /*****************************************************************************
 * Prototypes
 * ****************************************************************************/
result_t eeprom_i2c_read_byte(
    I2C_BUS i2c_bus_id,
    const EEPROM_CFG *cfg,
    u8 dev_addr,
    u32 mem_addr,
    u8 *data
);

result_t eeprom_i2c_read_buffer(
    I2C_BUS i2c_bus_id,
    const EEPROM_CFG *cfg,
    u8 dev_addr,
    u32 mem_addr,
    u8 *data,
    u16 length
);

result_t eeprom_i2c_write_byte(
    I2C_BUS i2c_bus_id,
    const EEPROM_CFG *cfg,
    u8 dev_addr,
    u32 mem_addr,
    u8 data
);

// result_t eeprom_i2c_write_buffer(
//     I2C_BUS i2c_bus_id,
//     const EEPROM_CFG *cfg,
//     u8 dev_addr,
//     u32 mem_addr,
//     u8 *data,
//     u16 length
// );

// result_t eeprom_i2c_erase(
//     I2C_BUS i2c_bus_id,
//     const EEPROM_CFG *cfg,
//     u8 dev_addr
// );

 #endif