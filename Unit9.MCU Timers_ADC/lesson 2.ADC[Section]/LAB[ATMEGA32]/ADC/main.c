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
#include "atmega32_timer_driver.h"
#include "atmega32_adc_driver.h"
#include "lcd.h"

#define F_CPU 8000000UL




int main()
{

	uint16_t data = 0;
	uint8_t State=0;
	uint32_t volt_Pot = 0;
	uint32_t volt_lm35 = 0;
	int32_t volt_Offset_lm35 = 0;
	int32_t Temperature_Celsuis=0;
	uint8_t Percent=0;
	uint8_t Block_Black[16]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	uint8_t N_REPEAT=0;

	MCAL_ADC_Init(VREF_AVCC, ADC_SCALER_64);
	LCD_INIT();
	LCD_clear_screen();

	/*Setting Potentiometer Volume*/

	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("Per:");


	LCD_GOTO_XY(1,9);
	LCD_WRITE_STRING("%");


	/*LM35 Temperature [Reading -55 celsius  to 150 celsius ] */
	/*
	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("Temperature (C):");


	LCD_GOTO_XY(2,10);
	LCD_WRITE_STRING("(oC)");*/



	while(1)
	{

		/*Setting Potentiometer Volume*/

		LCD_GOTO_XY(1,5);
		volt_Pot=(((uint32_t)MCAL_ADC_Read(CH_7)*5000)/1024);   //milli_volt , you should do casting (uint32_t )
		Percent=(((uint32_t)MCAL_ADC_Read(CH_7)*100)/1023);

		LCD_WRITE_Number_Ndigit(Percent,3);

		N_REPEAT= Percent / 6 ;

		LCD_GOTO_XY(2,0);
		for (int i=0; i<N_REPEAT;i++)
		{
			LCD_WRITE_CHAR(Block_Black[i]);

		}

		LCD_GOTO_XY(2,N_REPEAT);
		LCD_WRITE_STRING("           ");




		/*LM35 Temperature [Reading -55 celsius  to 150 celsius ] */
		/* I use the logical shifter as hardware with lm35 to shift the volt by 2.5 volt.*/
		/*
		data = MCAL_ADC_Read(CH_6);
		volt_lm35 = (((uint32_t)MCAL_ADC_Read(CH_6)*5000)/1024);   //milli_volt , you should do casting (uint32_t )
		volt_Offset_lm35= volt_lm35-(2.5*1000);
		State= (volt_Offset_lm35 > 0)   ?  1 : 0;
		Temperature_Celsuis= abs((volt_Offset_lm35*100)/1000);


		LCD_GOTO_XY(2,5);
		if(State == 0)LCD_WRITE_CHAR('-');
		else LCD_WRITE_CHAR('+');
		LCD_WRITE_Number_Ndigit(Temperature_Celsuis,3);


		 */



	}



	return 0 ;
}




