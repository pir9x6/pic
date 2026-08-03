/*****************************************************************************
* Includes
******************************************************************************/
#include "i2c.h"
#include "i2c_tools.h"
#include "types.h"
#include <stdio.h>

/*****************************************************************************
* Scan I2C Bus
******************************************************************************/
#define I2C_ADDR_MIN 0x03
#define I2C_ADDR_MAX 0x77

result_t i2c_detect (I2C_BUS i2c_id)
{
    u8 i, row, col;
    u8 nb_devices = 0;

    printf("\n\r--------- Detected I2C Devices (bus #%u) ----------\n   ", i2c_id);

    /* print '0' to 'F' */
    for (i = 0; i < 16; i++)
    {
        printf(" %X", i);
        printf(" ");
    }

    printf("\n");
    for (row = 0; row < 8; row++)
    {
        printf("%02X:", row << 4);

        for (col = 0; col < 16; col++)
        {
            u8 addr = (u8)((row << 4) | col);

            if ((addr < I2C_ADDR_MIN) || (addr > I2C_ADDR_MAX))
            {
                printf("   ");
                continue;
            }
            else
            {
                // send start condition
                i2c_start(i2c_id);

                // send address
                i2c_write (i2c_id, (addr << 1) & 0xFE);

                // wait for ack
                if (i2c_wait_ack(i2c_id) == SUCCESS){
                    // si reception du Ack du slave
                    nb_devices++;
                    printf("%02X ", addr);
                }else{
                    printf("-- ");
                }

                // send stop condition
                i2c_stop(i2c_id);
            }
        }
        printf("\n");
    }

    printf("\nFound %u device(s)\n\n", nb_devices);

    return SUCCESS;
}


/*****************************************************************************
* Dump I2C Device
******************************************************************************/
result_t i2c_dump (I2C_BUS i2c_id, u8 dev_addr, u16 start, u16 length)
{
    u8 i, row, col;
    u8 read_data = 0;
    u16 end = start + length;

    printf("\n\n-------------- Dump of I2C Chip --------------\n");
    printf("Bus    : %u\n", i2c_id);
    printf("Address: 0x%02X\n", dev_addr);
    printf("Range  : 0x%04X - 0x%04X\n\n", start, end - 1);

    printf("\n    ");

    /* print '0' to 'F' */
    for (i = 0; i < 16; i++)
    {
        printf(" %X", i);
        printf(" ");
    }

    for (row = 0; row < 16; row++)
    {
        printf("%02X: ", row);
        for (col = 0; col < 16; col++)
        {
            i2c_read_reg(i2c_id, dev_addr, (u8)((row << 4) | col), &read_data);
            printf("%02X ", read_data);
        }
        printf("\n");
    }

    return SUCCESS;
}
