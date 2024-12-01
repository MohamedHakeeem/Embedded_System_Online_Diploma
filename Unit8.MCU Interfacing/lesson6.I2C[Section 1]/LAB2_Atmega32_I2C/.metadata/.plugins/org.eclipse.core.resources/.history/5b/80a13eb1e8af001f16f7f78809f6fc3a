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
	GPIO_PinConfig_t gpioconfig;
	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);

	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);

	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);

	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_3;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);

	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_4;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);


	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);


	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);

	gpioconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	gpioconfig.GPIO_PinNumber=GPIO_PIN_7;
	MCAL_GPIO_Init(GPIOA,&gpioconfig);

	MCAL_I2C_Set_Address(0b11010000);         //Enable slave at address 01101000 and Don't accept general call

	while (1)
	{
		MCAL_GPIO_WritePort(GPIOA,MCAL_I2C_Read(1));   // Receive Byte and send ACK
	}

	return 0 ;
}




