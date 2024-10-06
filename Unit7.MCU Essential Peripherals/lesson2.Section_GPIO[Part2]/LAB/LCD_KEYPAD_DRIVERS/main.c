/*
 * main.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 *      LCD & Keypad Drivers
 *
 */

#include "LCD_Driver/lcd.h"
#include  "KEYPAD_Driver/Keypad.h"





int main()
{

	LCD_INIT();
	LCD_Generate_Ch();

	Keypad_init();
	_delay_ms(50);
	unsigned char key_pressed;
	while(1)
	{
		key_pressed = Keypad_getkey();
		switch(key_pressed)
		{
		case 'N':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);

		}
	}

	return 0 ;

}


