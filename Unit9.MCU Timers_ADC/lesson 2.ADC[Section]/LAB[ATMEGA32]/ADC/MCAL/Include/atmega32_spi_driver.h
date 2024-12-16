/*
 * atmega32_spi_driver.h
 *
 *  Created on: Nov 15, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 */

#ifndef INCLUDE_ATMEGA32_SPI_DRIVER_H_
#define INCLUDE_ATMEGA32_SPI_DRIVER_H_




//========================================================
//						INCLUDES
//========================================================

#include "ATMEGA32.h"
#include "atmega32_gpio_driver.h"


//According to GPIOB
#define SS   GPIO_PIN_4
#define MOSI GPIO_PIN_5
#define MISO GPIO_PIN_6
#define SCK  GPIO_PIN_7



//========================================================
//				Configuration Structure
//========================================================

typedef struct
{
	uint8_t SPI_MODE ; 			//Specifies the SPI Mode (Master / Slave)
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref SPI_MODE_Define

	uint8_t  Data_Order;       //Specifies the Data_Order (LSB FIRST / MSB FIRST)
							   //This Parameter must be set with value
							  //from Macro Configuration Manual @ref Data_Order_Define

	uint8_t  Data_Modes;        //Specifies the SCK phase and polarity with respect to serial data
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref  Data_Modes_Define


	uint8_t SPI_Clock_Rate;		//Specifies the SCK rate of the device configured as a Master.
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref SPI_Clock_Rate_Define



	uint8_t SPI_IRQ_EN;		//Enables Or Disable SPI_Interrupt[Slave/Master]
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref SPI_IRQ_Define


	void (* Ptr_IRQ_CallBack)(void);  //Set C function to be called once IRQ Happens



}SPI_Config_t;





//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			Macros Configuration References
//========================================================
//@ref SPI_MODE_Define

#define SPI_MODE_MASTER    1
#define SPI_MODE_SLAVE	   0



//@ref Data_Order_Define
#define Data_Order_LSB_FIRST   	   1
#define Data_Order_MSB_FIRST	   0


//@ref  Data_Modes_Define

#define  Data_Mode0	   0
#define  Data_Mode1	   1
#define  Data_Mode2	   2
#define  Data_Mode3	   3


//@ref SPI_Clock_Rate_Define

#define SPI_Clock_Rate_fosc_divided2     0
#define SPI_Clock_Rate_fosc_divided4     1
#define SPI_Clock_Rate_fosc_divided8     2
#define SPI_Clock_Rate_fosc_divided16    3
#define SPI_Clock_Rate_fosc_divided32    4
#define SPI_Clock_Rate_fosc_divided64    5
#define SPI_Clock_Rate_fosc_divided128   6


//@ref SPI_IRQ_Define

#define SPI_IRQ_Enable   1
#define SPI_IRQ_Disable   0



void MCAL_SPI_Init(SPI_Config_t* SPI_config);
void MCAL_SPI_Master_Send(uint8_t M_send_Buffer_);
void MCAL_SPI_Master_Receive(uint8_t* M_recive_Buffer_);
void MCAL_SPI_Slave_Send(uint8_t S_send_Buffer_);
void MCAL_SPI_Slave_Receive(uint8_t* S_recive_Buffer_);


#endif /* INCLUDE_ATMEGA32_SPI_DRIVER_H_ */
