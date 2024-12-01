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
	MCAL_I2C_Init(0x48);
    while (1)
    {
		_delay_ms(500);
		MCAL_I2C_Start();                   		  //Transmit Start Condition
		MCAL_I2C_Write(0b11010000+0);       		  //Transmit  SLA[slave address] + W(0)
		while ((I2C->TWSR) != 0x18);       			  //SLA + W(0) has been transmitted and ACK has been Received
		MCAL_I2C_Write(ch++);             				  // Transmit Data
		while ((I2C->TWSR) != 0x28);     			  //Data has been transmitted and ACK has been Received
		MCAL_I2C_Stop();                					  //Transmit Stop condition
    }

	return 0 ;
}




