/*
 * atmega32_spi_driver.c
 *
 *  Created on: Nov 15, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 */


#include "atmega32_spi_driver.h"

void (* GPtr_Ptr_IRQ_CB)(void);



void MCAL_SPI_Init(SPI_Config_t* SPI_config)
{


	//SPI_MODE
	GPIO_PinConfig_t gpio_confg;
	switch(SPI_config->SPI_MODE)
	{

		case (SPI_MODE_MASTER):

			gpio_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
			gpio_confg.GPIO_PinNumber=SS;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);

			gpio_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
			gpio_confg.GPIO_PinNumber=MOSI;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);

			gpio_confg.GPIO_Mode=GPIO_Mode_Inp_Floating;
			gpio_confg.GPIO_PinNumber=MISO;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);


			gpio_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
			gpio_confg.GPIO_PinNumber=SCK;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);

			MCAL_GPIO_WritePin(GPIOB,SS,1);
			SPI->SPCR |= (1 << 4);


			break;

		case (SPI_MODE_SLAVE):

			gpio_confg.GPIO_Mode=GPIO_Mode_Inp_Floating;
			gpio_confg.GPIO_PinNumber=SS;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);

			gpio_confg.GPIO_Mode=GPIO_Mode_Inp_Floating;
			gpio_confg.GPIO_PinNumber=MOSI;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);

			gpio_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
			gpio_confg.GPIO_PinNumber=MISO;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);

			gpio_confg.GPIO_Mode=GPIO_Mode_Inp_Floating;
			gpio_confg.GPIO_PinNumber=SCK;
			MCAL_GPIO_Init(GPIOB,&gpio_confg);
			SPI->SPCR &= ~(1 << 4);


			break;
	}

	//Data_Order
	switch(SPI_config->Data_Order)
	{

		case (Data_Order_LSB_FIRST):
			SPI->SPCR |= (1 << 5);
			break;
		case (Data_Order_MSB_FIRST):
			SPI->SPCR &= ~(1 << 5);
			break;


	}

	//Data_Modes
	/*
	 * Bit3      Bit2
	   CPOL = 0, CPHA = 0 -------Sample (Rising)  ------- Setup  (Falling)  Mode0
	   CPOL = 0, CPHA = 1 -------Setup  (Rising)  ------- Sample (Falling)  Mode1
	   CPOL = 1, CPHA = 0 -------Sample (Falling) ------- Setup  (Rising)   Mode2
	   CPOL = 1, CPHA = 1 -------Setup  (Falling) ------- Sample (Rising) 	Mode3

	*/
	switch(SPI_config->Data_Modes)
	{

		case (Data_Mode0):
			SPI->SPCR &= ~((1 << 2) | (1 << 3));
			break;

		case (Data_Mode1):
			SPI->SPCR |=  (1 << 2);
			SPI->SPCR &= ~(1 << 3);
		    break;

		case (Data_Mode2):
		    SPI->SPCR |=  (1 << 3);
			SPI->SPCR &= ~(1 << 2);
			break;

		case (Data_Mode3):
			SPI->SPCR |= ((1 << 2) | (1 << 3));
			break;


	}

	//SPI_Clock_Rate
	/*
    BIT0[SPSR]      BIT1[SPCR]  BIT0[SPCR]
	 SPI2X			SPR1		SPR0	SCK Frequency
	   0		 	0       	0         fosc/4
	   0         	0       	1         fosc/16
	   0         	1       	0         fosc/64
	   0        	1       	1         fosc/128
	   1         	0       	0         fosc/2
	   1        	0       	1         fosc/8
	   1         	1       	0         fosc/32
	   1         	1       	1         fosc/64
	 */

	switch(SPI_config->SPI_Clock_Rate)
	{

		case (SPI_Clock_Rate_fosc_divided2):
			SPI->SPCR &=  ~(1<<0);
			SPI->SPCR &=  ~(1<<1);
			SPI->SPSR |=   (1<<0);
			break;

		case (SPI_Clock_Rate_fosc_divided4):
			SPI->SPCR &=  ~(1<<0);
			SPI->SPCR &=  ~(1<<1);
			SPI->SPSR &=  ~(1<<0);
			break;

		case (SPI_Clock_Rate_fosc_divided8):
		   SPI->SPCR |=   (1<<0);
		   SPI->SPCR &=  ~(1<<1);
		   SPI->SPSR |=   (1<<0);
		   break;

		case (SPI_Clock_Rate_fosc_divided16):
		   SPI->SPCR |=   (1<<0);
		   SPI->SPCR &=  ~(1<<1);
		   SPI->SPSR &=  ~(1<<0);
		   break;

		case (SPI_Clock_Rate_fosc_divided32):
		   SPI->SPCR &=  ~(1<<0);
		   SPI->SPCR |=   (1<<1);
		   SPI->SPSR |=   (1<<0);
		   break;

		case (SPI_Clock_Rate_fosc_divided64):
		   SPI->SPCR &=  ~(1<<0);
		   SPI->SPCR |=   (1<<1);
		   SPI->SPSR &=  ~(1<<0);
		   break;

		case (SPI_Clock_Rate_fosc_divided128):
		   SPI->SPCR |=   (1<<0);
		   SPI->SPCR |=   (1<<1);
		   SPI->SPSR &=  ~(1<<0);
		   break;

	}


	//Enable_Interrupt
	switch(SPI_config->SPI_IRQ_EN)
		{
			case (SPI_IRQ_Enable):
				ENABLE_GLOBAL_INTERRUPT();
				SPI->SPCR |= (1 << 7);
				GPtr_Ptr_IRQ_CB = SPI_config->Ptr_IRQ_CallBack;

				break;

			case (SPI_IRQ_Disable):
				DISABLE_GLOBAL_INTERRUPT();
			    SPI->SPCR &= ~(1 << 7);
			    break;

		}



	//Enable SPI
	SPI->SPCR |= (1 << 6);

}




void MCAL_SPI_Master_Send(uint8_t M_send_Buffer_)
{


	//out low at SS pin.
	MCAL_GPIO_WritePin(GPIOB,SS,0);

	SPI->SPDR=M_send_Buffer_;

	while (!(SPI->SPSR & (1 << 7)));
	MCAL_GPIO_WritePin(GPIOB,SS,1);



}


void MCAL_SPI_Master_Receive(uint8_t* M_recive_Buffer_)
{


	//out low at SS pin.
	MCAL_GPIO_WritePin(GPIOB,SS,0);

	while (!(SPI->SPSR & (1 << 7)));
	*M_recive_Buffer_=SPI->SPDR;

	MCAL_GPIO_WritePin(GPIOB,SS,1);




}


void MCAL_SPI_Slave_Send(uint8_t S_send_Buffer_)
{

	SPI->SPDR=S_send_Buffer_;
	while (!(SPI->SPSR & (1 << 7)));

}




void MCAL_SPI_Slave_Receive(uint8_t* S_recive_Buffer_)
{



	while (!(SPI->SPSR & (1 << 7)));
	*S_recive_Buffer_ = SPI->SPDR;




}


