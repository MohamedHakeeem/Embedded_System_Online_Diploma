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
#include "lcd.h"
#include "atmega32_usart_driver.h"


#define F_CPU 8000000UL


int main()
{
	LCD_INIT();
	LCD_clear_screen();
	LCD_WRITE_STRING("UART_STRING^__^");

	uint8_t *ptrsend_string = "Mohamed_HK";
	uint8_t ptrreceive_string[100];
	USART_Config_t USART_CONFIG_LCD;
	USART_CONFIG_LCD.USART_MODE=USART_MODE_Asynchronous;
	USART_CONFIG_LCD.BaudRate=USART_BaudRate_9600;
	USART_CONFIG_LCD.Data_Length=USART_DATA_LEGNTH_8BIT;
	USART_CONFIG_LCD.Parity=USART_PARITY_NONE;
	USART_CONFIG_LCD.Stop_Bits=USART_StopBits_1;
	USART_CONFIG_LCD.IRQ_Enable=USART_IRQ_DISABLED;
	USART_CONFIG_LCD.Ptr_IRQ_CallBack=NULL;
	MCAL_USART_Init(&USART_CONFIG_LCD);

	MCAL_USART_SendString(ptrsend_string);
	MCAL_USART_ReceiveString(ptrreceive_string);
	LCD_clear_screen();

	uint8_t i=0;

	while(1)
	{
		while(ptrreceive_string[i]!='#')
		{
			LCD_WRITE_CHAR(ptrreceive_string[i]);
			i++;
		}

	}

	return 0 ;

}

