/*
 * main.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 *
 *
 */


#include  <util/delay.h>
#include "ATMEGA32.h"
#include "atmega32_gpio_driver.h"
#include "atmega32_exti_driver.h"
#include "lcd.h"
#include "atmega32_usart_driver.h"



#define F_CPU 8000000UL



int main()
{

	uint8_t ptrreceive_string[32];
	uint8_t *ptrsend_string= "Mohamed";
	uint8_t no_block=0;
	uint8_t Count=0;

	LCD_INIT();
	LCD_clear_screen();


	USART_Config_t USART_CONFIG_LCD;
	USART_CONFIG_LCD.USART_MODE=USART_MODE_Asynchronous;
	USART_CONFIG_LCD.BaudRate=USART_BaudRate_9600;
	USART_CONFIG_LCD.Data_Length=USART_DATA_LEGNTH_8BIT;
	USART_CONFIG_LCD.Parity=USART_PARITY_NONE;
	USART_CONFIG_LCD.Stop_Bits=USART_StopBits_1;
	//USART_CONFIG_LCD.IRQ_Enable=USART_IRQ_DISABLED;
	//USART_CONFIG_LCD.Ptr_IRQ_CallBack=NULL;

	USART_CONFIG_LCD.Ptr_IRQ_CallBack=MCAL_USART_SStr_ISR;
	USART_CONFIG_LCD.IRQ_Enable=USART_IRQ_EN_TXCIE;

	MCAL_USART_Init(&USART_CONFIG_LCD);



	//***************Task1:Send & Receiving By Polling********************//
	//********************************************************************//
	/*LCD_WRITE_STRING("UART_STRING^___^");
	MCAL_USART_SendString(ptrsend_string);

	uint8_t i=0;

	while(1)
	{

		MCAL_USART_ReceiveString(ptrreceive_string);

		LCD_GOTO_XY(2,0);
		LCD_WRITE_STRING(ptrreceive_string);

		LCD_GOTO_XY(1,0);
		LCD_WRITE_Number(Count);
		Count++;
		if(Count == 10)
		{
			Count=0;
		}


		_delay_ms(100000);


	}*/

	//********************************************************************//
	//********************************************************************//





	//***********Task2:Send & Receiving By No Blocking********************//
	//********************************************************************//
	/*
	LCD_WRITE_STRING("UART_STRING^___^");
	MCAL_USART_SEND('M',Polling_DISABLED,No_Blocking);
	uint8_t i=0;

	while(1)
	{

		if(MCAL_USART_RECEIVE(&no_block,Polling_DISABLED,No_Blocking))
		{
			LCD_GOTO_XY(2,0);
			LCD_WRITE_CHAR(no_block);
		}


		LCD_GOTO_XY(1,0);
		LCD_WRITE_Number(Count);
		Count++;
		if(Count == 10)
		{
			Count=0;
		}


		_delay_ms(1000);


	}*/


	//********************************************************************//
	//********************************************************************//






	//***********Task2:Send & Receiving By Interrupt********************//
	//********************************************************************//

	/*MCAL_USART_SendStr_Aysnch("Mohamed_HK");


	while(1)
	{

		LCD_GOTO_XY(1,0);
		LCD_WRITE_Number(Count);
		Count++;
		if(Count == 10)
		{
			Count=0;
		}


		_delay_ms(1000);


	}*/


	//********************************************************************//
	//********************************************************************//







	return 0 ;

}

