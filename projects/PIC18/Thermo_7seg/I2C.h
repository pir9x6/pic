

#include "p18CXXX.h"

void I2C_Init(unsigned char Freq);

void I2C_Start(void);			

void I2C_Rstart(void);	

void I2C_Stop(void);

int  I2C_Read(void);	
					
void I2C_Write(unsigned char i2cWriteData );

void I2C_Nack(unsigned char Ack) ;

void I2C_Ack(void);
