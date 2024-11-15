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



int main()
{

	//Replace with your application code
	uint8_t counter = 0;
	uint8_t index_display=0;

	SPI_Config_t SPI_config;
	SPI_config.SPI_MODE=SPI_MODE_MASTER;
	SPI_config.Data_Modes=Data_Mode0;
	SPI_config.Data_Order=Data_Order_MSB_FIRST;
	SPI_config.SPI_Clock_Rate=SPI_Clock_Rate_fosc_divided32;
	SPI_config.Ptr_IRQ_CallBack=NULL;
	SPI_config.SPI_IRQ_EN=SPI_IRQ_Disable;
	MCAL_SPI_Init(&SPI_config);


	// cmd and data.
	MCAL_SPI_Master_Send(0x09);
	MCAL_SPI_Master_Send(0xFF);

	// cmd and data.
	MCAL_SPI_Master_Send(0x0A);
	MCAL_SPI_Master_Send(0xFF);


	// cmd and data.
	MCAL_SPI_Master_Send(0x0B);
	MCAL_SPI_Master_Send(0xF7);

	// cmd and data.
	MCAL_SPI_Master_Send(0x0C);
	MCAL_SPI_Master_Send(0x01);





	while(1)
	{
		for (index_display = 1; index_display < 9; index_display++)
		{

			MCAL_SPI_Master_Send(index_display-2);
			MCAL_SPI_Master_Send(0);
			MCAL_SPI_Master_Send(index_display-1);
			MCAL_SPI_Master_Send(0);


			MCAL_SPI_Master_Send(index_display);
			MCAL_SPI_Master_Send(counter++);

			_delay_ms(1000);

		}
		counter = 0;

	}

	return 0 ;
}




