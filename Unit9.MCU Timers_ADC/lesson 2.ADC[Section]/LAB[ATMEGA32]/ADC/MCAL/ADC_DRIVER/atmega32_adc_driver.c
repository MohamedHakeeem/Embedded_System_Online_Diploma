/*
 * atmega32_adc_driver.c
 *
 *  Created on: Dec 13, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */


#include "atmega32_adc_driver.h"
#include "atmega32_gpio_driver.h"

#define SET_BIT(Register, bit)        Register |=  (1 << bit)
#define CLEAR_BIT(Register, bit)      Register &= ~(1 << bit)
#define TOGGLE_BIT(Register, bit)     Register ^=  (1 << bit)
#define READ_BIT(Register, bit)       ((Register >> bit) & 0x1)


void MCAL_ADC_Init(ADC_Vref_type Vref , ADC_Scaler_Type Scaler)
{
	GPIOA->DDR = 0x00;  // Make ADC port as input

	// Bits 7:6 – REFSn:?Reference Selection [n = 1:0]
	switch(Vref)
	{
		case VREF_AREF:
		CLEAR_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;

		case VREF_AVCC:
		SET_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;

		case VREF_256:
		SET_BIT(ADMUX , REFS0);
		SET_BIT(ADMUX , REFS1);
		break;
	}

	// Prescaler
	ADCSRA &= 0xF8;
	ADCSRA |= Scaler;

	// Enable ADC
	SET_BIT(ADCSRA , ADEN);
}



uint16_t MCAL_ADC_Read(ADC_Channel_Type CH)
{
	//Select Channel
	ADMUX = ADMUX & 0XE0;
	ADMUX |= CH;


	ADCSRA |= (1<<ADSC);				// Start conversion

	while(READ_BIT(ADCSRA,ADSC));		// Monitor end of conversion interrupt

	return ADC;					        // Return digital value
}
