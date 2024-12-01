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
	unsigned char ch;

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

	MCAL_I2C_Init(0x48);
	//Initialize TWI for Master Code
	while (1)
	{
		_delay_ms(1000);
		MCAL_I2C_Start();                       //Transmit Start condition
		MCAL_I2C_Write(0b11010000+1);          //Transmit SLA+R(1)
		ch=MCAL_I2C_Read(0);                  //read last Byte , send NACK
		MCAL_I2C_Stop();

		MCAL_GPIO_WritePort(GPIOA,ch);   // Receive Byte and send ACK

	}
	return 0 ;
}




