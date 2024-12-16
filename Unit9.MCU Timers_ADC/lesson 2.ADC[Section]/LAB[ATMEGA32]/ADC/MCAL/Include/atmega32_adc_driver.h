/*
 * atmega32_adc_driver.h
 *
 *  Created on: Dec 13, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INCLUDE_ATMEGA32_ADC_DRIVER_H_
#define INCLUDE_ATMEGA32_ADC_DRIVER_H_

#include "ATMEGA32.h"


/*
 * =======================================================================================
 * 							Enumerations
 * =======================================================================================
 */

typedef enum
{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
}ADC_Vref_type;


// ADC Running Speed
// Note : ADC Frequency Shouldn't less than 200 KHz
typedef enum
{
	ADC_SCALER_2 = 0,
	ADC_SCALER_4 = 2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
}ADC_Scaler_Type;


typedef enum
{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_Type;


/*
 * =======================================================================================
 * 							         APIs
 * =======================================================================================
 */

void MCAL_ADC_Init(ADC_Vref_type Vref , ADC_Scaler_Type Scaler);

uint16_t MCAL_ADC_Read(ADC_Channel_Type CH);


#endif /* INCLUDE_ATMEGA32_ADC_DRIVER_H_ */
