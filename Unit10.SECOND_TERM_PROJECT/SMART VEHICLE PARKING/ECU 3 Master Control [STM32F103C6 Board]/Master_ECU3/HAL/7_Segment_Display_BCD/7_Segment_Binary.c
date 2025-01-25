/*
 * 7_Segment_Binary.c
 *
 *  Created on: Jan 12, 2025
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#include "7_Segment_Binary.h"



GPIO_PinConfig_t GB_Segment_confg;
void Seven_SegmentBCD_Init(GPIO_TypedDef* GPIOx)
{
	MCAL_GPIO_Enable_ClocK(GPIOx);

	GB_Segment_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GB_Segment_confg.GPIO_PinNumber=GPIO_PIN_12;
	GB_Segment_confg.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOx, &GB_Segment_confg);

	GB_Segment_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GB_Segment_confg.GPIO_PinNumber=GPIO_PIN_13;
	GB_Segment_confg.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOx, &GB_Segment_confg);

	GB_Segment_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GB_Segment_confg.GPIO_PinNumber=GPIO_PIN_14;
	GB_Segment_confg.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOx, &GB_Segment_confg);

	GB_Segment_confg.GPIO_Mode=GPIO_Mode_Out_push_pull;
	GB_Segment_confg.GPIO_PinNumber=GPIO_PIN_15;
	GB_Segment_confg.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(GPIOx, &GB_Segment_confg);


}

void Seven_SegmentBCD_Display(GPIO_TypedDef* GPIOx , uint8_t Digit)
{
	MCAL_GPIO_WritePin(GPIOx, GPIO_PIN_12, (Digit & (0x01)) >> 0);
	MCAL_GPIO_WritePin(GPIOx, GPIO_PIN_13, (Digit & (0x02)) >> 1 );
	MCAL_GPIO_WritePin(GPIOx, GPIO_PIN_14, (Digit & (0x04)) >> 2);
	MCAL_GPIO_WritePin(GPIOx, GPIO_PIN_15, (Digit & (0x08)) >> 3);

}
