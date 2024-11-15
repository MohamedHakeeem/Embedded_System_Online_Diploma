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
#include "atmega32_spi_driver.h"

#define F_CPU 1000000UL

void GPIOA_Init(void)
{
	GPIO_PinConfig_t GPIO_config;
	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_3;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_4;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


	GPIO_config.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GPIO_config.GPIO_PinNumber=GPIO_PIN_7;
	MCAL_GPIO_Init(GPIOA,&GPIO_config);


}

int main()
{

	unsigned char ch = 0;

	SPI_Config_t SPI_config;
	SPI_config.SPI_MODE=SPI_MODE_MASTER;
	SPI_config.Data_Modes=Data_Mode0;
	SPI_config.Data_Order=Data_Order_MSB_FIRST;
	SPI_config.SPI_Clock_Rate=SPI_Clock_Rate_fosc_divided16;
	SPI_config.Ptr_IRQ_CallBack=NULL;
	SPI_config.SPI_IRQ_EN=SPI_IRQ_Disable;
	MCAL_SPI_Init(&SPI_config);


	GPIOA_Init();

	for (ch = 0; ch <= 255; ch++)
	{
		_delay_ms(1000);
		MCAL_SPI_Master_Send(ch);
		MCAL_GPIO_WritePort(GPIOA,ch);
	}



	return 0 ;
}




