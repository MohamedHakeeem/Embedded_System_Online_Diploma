/*
 * lcd.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali
 */

#include "lcd.h"
GPIO_PinConfig_t LCD_pinconfig;


void _delay_ms(uint32_t time_ms)
{
	volatile uint32_t  i,j;
	for(i=0;i<time_ms;i++)
		for(j=0 ; j<255 ; j++);

}



void LCD_INIT()
{
	_delay_ms(20);
	LCD_pinconfig.GPIO_PinNumber=EN_SWITCH;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_CTRL,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=RS_SWITCH;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_CTRL,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=RW_SWITCH;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_CTRL,&LCD_pinconfig);

	//WRITE IN CONTROL PINS '0';
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0);
    //========================================================================

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_0;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_1;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_2;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_3;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_4;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_5;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_6;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_7;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	_delay_ms(15);

	//WRITE IN DATA PINS '';
	//MCAL_GPIO_WritePort(LCD_PORT, )
#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
#endif
	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
}


void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}



/*
 * When the busy flag is 1, the HD44780U is in the internal operation mode,
 *  and the next instruction will not be accepted. When RS = 0 and R/W = 1 (Table 1),
 *  the busy flag is output to DB7. The next instruction must be written after
 *  ensuring that the busy flag is 0.
 *  If an instruction is sent without checking the busy flag, the time between
 *  the first instruction and next instruction will take much longer than the instruction time itself
 *
 *
 */
void LCD_check_lcd_isbusy(){

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_0;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_1;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_2;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_3;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_4;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_5;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_6;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_7;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_Floating;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);


	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 1); //read mode
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, 0);   // instruction mode
	LCD_lcd_kick();

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_0;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_1;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_2;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_3;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_4;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_5;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_6;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);

	LCD_pinconfig.GPIO_PinNumber=GPIO_PIN_7;
	LCD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	MCAL_GPIO_Init(LCD_PORT,&LCD_pinconfig);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0); //write mode

}
void LCD_lcd_kick()
{
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, 1);
	_delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, 0);

}




void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}





void LCD_WRITE_COMMAND(unsigned char command)
{
#ifdef EIGHT_BIT_MODE
	//LCD_check_lcd_isbusy();
	MCAL_GPIO_WritePort(LCD_PORT, (uint16_t)(command));
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0);
	_delay_ms(1);
	LCD_lcd_kick();
#endif
#ifdef FOUR_BIT_MODE
	LCD_PORT = (command & 0xF0);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	_delay_ms(1);
	LCD_lcd_kick ();
	LCD_PORT = (command << 4);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	_delay_ms(1);
	LCD_lcd_kick();

#endif

}

void LCD_WRITE_CHAR(unsigned char character)
{
#ifdef EIGHT_BIT_MODE
	//LCD_check_lcd_isbusy();
	MCAL_GPIO_WritePort(LCD_PORT, (uint16_t)(character));
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, 1);
	_delay_ms(1);
	LCD_lcd_kick();
#endif
#ifdef FOUR_BIT_MODE
	LCD_PORT = (character & 0xF0);
	LCD_CTRL |= (1<<RS_SWITCH); //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	_delay_ms(1);
	LCD_lcd_kick();
	LCD_PORT = (character << 4);
	LCD_CTRL |= (1<<RS_SWITCH); //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	_delay_ms(1);
	LCD_lcd_kick ();
#endif
}


void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string != '\0')
	{
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}


void LCD_Generate_Ch(void)
{

	// Set CGRAM address to 0
	LCD_WRITE_COMMAND(64);

	// Define the heart shape
	LCD_WRITE_CHAR(0b00000); // Row 1
	LCD_WRITE_CHAR(0b01010); // Row 2
	LCD_WRITE_CHAR(0b11111); // Row 3
	LCD_WRITE_CHAR(0b11111); // Row 4
	LCD_WRITE_CHAR(0b11111); // Row 5
	LCD_WRITE_CHAR(0b01110); // Row 6
	LCD_WRITE_CHAR(0b00100); // Row 7
	LCD_WRITE_CHAR(0b00000); // Row 8

	// Move cursor to the beginning of the first row
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);

	// Display the custom character
	LCD_WRITE_CHAR(0);

	// Small delay
	_delay_ms(10000);

}



