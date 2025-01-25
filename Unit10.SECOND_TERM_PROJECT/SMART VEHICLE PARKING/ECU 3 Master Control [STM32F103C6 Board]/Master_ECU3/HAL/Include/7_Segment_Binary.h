/*
 * 7_Segment_Binary.h
 *
 *  Created on: Jan 12, 2025
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

#ifndef INCLUDE_7_SEGMENT_BINARY_H_
#define INCLUDE_7_SEGMENT_BINARY_H_

#include "stm32f103x6_gpio_driver.h"

#define Dig0       0
#define Dig1       1
#define Dig2       2
#define Dig3       3
#define Dig4       4
#define Dig5       5
#define Dig6       6
#define Dig7       7
#define Dig8       8
#define Dig9       9



void Seven_SegmentBCD_Init(GPIO_TypedDef* GPIOx);
void Seven_SegmentBCD_Display(GPIO_TypedDef* GPIOx,uint8_t Digit);






#endif /* INCLUDE_7_SEGMENT_BINARY_H_ */
