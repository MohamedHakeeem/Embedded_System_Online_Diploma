/*
 * atmega32_i2c_driver.h
 *
 *  Created on: Nov 27, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 */


#ifndef INCLUDE_ATMEGA32_I2C_DRIVER_H_
#define INCLUDE_ATMEGA32_I2C_DRIVER_H_

#include "ATMEGA32.h"
#include "atmega32_gpio_driver.h"


#define TWINT 7
#define TWSTA 5
#define TWEN  2
#define TWSTO 4
#define TWEA  6

void MCAL_I2C_Set_Address(unsigned char address);
unsigned char MCAL_I2C_Read(unsigned char ack);
void MCAL_I2C_Write(unsigned char cByte);







#endif /* INCLUDE_ATMEGA32_I2C_DRIVER_H_ */
