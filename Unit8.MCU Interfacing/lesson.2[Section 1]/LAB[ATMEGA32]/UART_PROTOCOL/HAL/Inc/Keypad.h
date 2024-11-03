/*
 * Keypad.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "ATMEGA32.h"
#include "atmega32_gpio_driver.h"




#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_2
#define R3 GPIO_PIN_3
#define C0 GPIO_PIN_4
#define C1 GPIO_PIN_5
#define C2 GPIO_PIN_6
#define C3 GPIO_PIN_7

#define KEYPAD_PORT GPIOD

void Keypad_init();
char Keypad_getkey();







#endif /* KEYPAD_H_ */
