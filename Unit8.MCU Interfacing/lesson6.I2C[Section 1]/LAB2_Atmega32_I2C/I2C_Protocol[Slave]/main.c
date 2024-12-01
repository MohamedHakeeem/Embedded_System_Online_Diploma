/*
 * main.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 *
 *
 */


#include  <util/delay.h>
#include "ATMEGA32.h"
#include "atmega32_gpio_driver.h"
#include "atmega32_i2c_driver.h"


#define F_CPU 1000000UL



int main()
{
	unsigned char ch=0;
	MCAL_I2C_Set_Address(0b11010000);     //Set Slave Address

	while (1)
	{
		MCAL_I2C_Write(ch++);
	}
	return 0;


}




