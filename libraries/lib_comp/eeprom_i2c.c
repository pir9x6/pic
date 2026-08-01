/*****************************************************************************
*   v1.0    2026-07-28  Original version (read & write validated)
* ****************************************************************************
*  ToDo:    Erase function, sequential write function, page write function
******************************************************************************/

/*****************************************************************************
* Includes
******************************************************************************/
#include "delays.h"
#include "eeprom_i2c.h"
#include "i2c.h"
#include "types.h"

#include "log.h"


/*****************************************************************************
* Docs
******************************************************************************/
// 24LC01: https://ww1.microchip.com/downloads/en/devicedoc/21711j.pdf
// 24LC04: https://ww1.microchip.com/downloads/en/DeviceDoc/21708K.pdf
// 24LC16: https://ww1.microchip.com/downloads/en/DeviceDoc/20002213B.pdf
// 24LC32: https://ww1.microchip.com/downloads/en/DeviceDoc/21072G.pdf
// 24LC256: https://ww1.microchip.com/downloads/aemDocuments/documents/MPD/ProductDocuments/DataSheets/24AA256-24LC256-24FC256-256K-I2C-Serial-EEPROM-DS20001203.pdf
// 24LC1025: https://ww1.microchip.com/downloads/aemDocuments/documents/MPD/ProductDocuments/DataSheets/24AA1025-24LC1025-24FC1025-1024-Kbit-I2C-Serial-EEPROM-20001941M.pdf

/*
    24xx01/02 use 1 byte address, 24xx04/08/16/32/64/128/256/1025 use 2 byte address
    24xx04/08/16/1025 use block addressing, 24xx32/64/128/256/512 do not use block addressing
*/

 /*****************************************************************************
 * Calculate the device address and the register address bytes based on the memory address
 * ****************************************************************************/
static void _get_addresses(
    const EEPROM_CFG *cfg,
    u32 mem_addr,
    u8 *dev_addr,
    u8 *addr_hi,
    u8 *addr_lo
)
{
    u8 block; /* 24xx04/08/16/1025 */
    if (cfg->block_bits)
    {
        block = (u8)(mem_addr >> (cfg->addr_bytes * 8)) & ((1 << cfg->block_bits) - 1);
        *dev_addr |= block << cfg->block_shift;
    }

    if (cfg->addr_bytes == 1)
    {
        /* Small EEPROMs: 24LC01, 24LC02 */
        *addr_hi = 0;
        *addr_lo = (u8)(mem_addr & 0xFF);
    }
    else
    {
        /* Large EEPROMs: 24LC32 ... 24LC512 */
        *addr_hi = (u8)((mem_addr >> 8) & 0xFF);
        *addr_lo = (u8)(mem_addr & 0xFF);
    }
}


 /*****************************************************************************
 * Read a single byte from the EEPROM
 * ****************************************************************************/
result_t eeprom_i2c_read_byte   (
    I2C_BUS i2c_bus_id,
    const EEPROM_CFG *cfg,
    u8 dev_addr,
    u32 mem_addr,
    u8 *data
)
{
    if (cfg->addr_bytes > 2){
        return ERROR;
    }

    /* get addresses */
    u8 dev_addr_new = dev_addr;
    u8 addr_hi, addr_lo;
    // LOG_INFO("EEPROM: Addr=0x%08lX DevAddr=0x%02X     ", mem_addr, dev_addr_new);
    _get_addresses(cfg, mem_addr, &dev_addr_new, &addr_hi, &addr_lo);
    // LOG_INFO("EEPROM: Addr=0x%08lX DevAddr=0x%02X AddrHi=0x%02X AddrLo=0x%02X    ", mem_addr, dev_addr_new, addr_hi, addr_lo);

    /* send start condition */
    if (i2c_start(i2c_bus_id) != SUCCESS){
        return ERROR;
    }

    /* Control byte: address of the device + Write */
    if (i2c_write(i2c_bus_id, I2C_ADDR_WR(dev_addr_new)) != SUCCESS){
        return ERROR;
    }

    /* MSB address of the register (large EEPROMS only) */
    if (cfg->addr_bytes == 2){
        u8 addr_hi = (u8)((mem_addr >> 8) & 0xFF);
        if (i2c_write(i2c_bus_id, addr_hi) != SUCCESS){
            return ERROR;
        }
    }

    /* LSB address of the register */
    if (i2c_write(i2c_bus_id, addr_lo) != SUCCESS){
        return ERROR;
    }

    /* send start condition */
    if (i2c_rstart(i2c_bus_id) != SUCCESS){
        return ERROR;
    }

    /* Control byte: address of the device + Read */
    if (i2c_write(i2c_bus_id, I2C_ADDR_RD(dev_addr_new)) != SUCCESS){
        return ERROR;
    }

    /* get data */
    if (i2c_read(i2c_bus_id, I2C_NACK, data) != SUCCESS){
        return ERROR;
    }

    /* send stop condition */
    if (i2c_stop(i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}


 /*****************************************************************************
 * Sequential read a buffer from the EEPROM
 * ****************************************************************************/
result_t eeprom_i2c_read_buffer(
    I2C_BUS i2c_bus_id,
    const EEPROM_CFG *cfg,
    u8 dev_addr,
    u32 mem_addr,
    u8 *data,
    u16 length
)
{
    if (cfg->addr_bytes > 2)
        return ERROR;

    if (data == NULL)
        return ERROR;

    if (length == 0)
        return ERROR;

    /* get addresses */
    u8 dev_addr_new = dev_addr;
    u8 addr_hi, addr_lo;
    // LOG_INFO("EEPROM: Addr=0x%08lX DevAddr=0x%02X     ", mem_addr, dev_addr_new);
    _get_addresses(cfg, mem_addr, &dev_addr_new, &addr_hi, &addr_lo);
    // LOG_INFO("EEPROM: Addr=0x%08lX DevAddr=0x%02X AddrHi=0x%02X AddrLo=0x%02X    ", mem_addr, dev_addr_new, addr_hi, addr_lo);

    /* send start condition */
    if (i2c_start(i2c_bus_id) != SUCCESS){
        return ERROR;
    }

    /* Control byte: address of the device + Write */
    if (i2c_write(i2c_bus_id, I2C_ADDR_WR(dev_addr_new)) != SUCCESS){
        return ERROR;
    }

    /* MSB address of the register (large EEPROMS only) */
    if (cfg->addr_bytes == 2){
        u8 addr_hi = (u8)((mem_addr >> 8) & 0xFF);
        if (i2c_write(i2c_bus_id, addr_hi) != SUCCESS){
            return ERROR;
        }
    }

    /* LSB address of the register */
    if (i2c_write(i2c_bus_id, addr_lo) != SUCCESS){
        return ERROR;
    }

    /* send start condition */
    if (i2c_rstart(i2c_bus_id) != SUCCESS){
        return ERROR;
    }

    /* Control byte: address of the device + Read */
    if (i2c_write(i2c_bus_id, I2C_ADDR_RD(dev_addr_new)) != SUCCESS){
        return ERROR;
    }

    /* get data */
    for (u16 i = 0; i < length; i++){
        u8 ack = (i == (length-1)) ? I2C_NACK : I2C_ACK;
        if (i2c_read(i2c_bus_id, ack, &data[i]) != SUCCESS){
            return ERROR;
        }
    }

    /* send stop condition */
    if (i2c_stop(i2c_bus_id) != SUCCESS)
        return ERROR;

    return SUCCESS;
}


 /*****************************************************************************
 * Write a single byte to the EEPROM
 * ****************************************************************************/
result_t eeprom_i2c_write_byte  (
    I2C_BUS i2c_bus_id,
    const EEPROM_CFG *cfg,
    u8 dev_addr,
    u32 mem_addr,
    u8 data
)
{
    if (cfg->addr_bytes > 2){
        return ERROR;
    }

    /* get addresses */
    u8 dev_addr_new = dev_addr;
    u8 addr_hi, addr_lo;
    LOG_INFO("EEPROM: Addr=0x%08lX DevAddr=0x%02X     ", mem_addr, dev_addr_new);
    _get_addresses(cfg, mem_addr, &dev_addr_new, &addr_hi, &addr_lo);
    LOG_INFO("EEPROM: Addr=0x%08lX DevAddr=0x%02X AddrHi=0x%02X AddrLo=0x%02X    ", mem_addr, dev_addr_new, addr_hi, addr_lo);

    /* send start condition */
    if (i2c_start(i2c_bus_id) != SUCCESS){
        return ERROR;
    }

    /* Control byte: address of the device + Write */
    if (i2c_write(i2c_bus_id, I2C_ADDR_WR(dev_addr_new)) != SUCCESS){
        return ERROR;
    }

    /* MSB address of the register (large EEPROMS only) */
    if (cfg->addr_bytes == 2){
        u8 addr_hi = (u8)((mem_addr >> 8) & 0xFF);
        if (i2c_write(i2c_bus_id, addr_hi) != SUCCESS){
            return ERROR;
        }
    }

    /* LSB address of the register */
    if (i2c_write(i2c_bus_id, addr_lo) != SUCCESS){
        return ERROR;
    }

    /* Write data */
    if (i2c_write(i2c_bus_id, data) != SUCCESS){
        return ERROR;
    }

    /* send stop condition */
    if (i2c_stop(i2c_bus_id) != SUCCESS)
        return ERROR;

    delay_ms(cfg->write_time_ms); // wait for the write cycle to complete

    return SUCCESS;
}
