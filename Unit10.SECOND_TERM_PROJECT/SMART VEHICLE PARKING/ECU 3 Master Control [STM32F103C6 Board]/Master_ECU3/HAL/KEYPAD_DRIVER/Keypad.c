/*
 * Keypad.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali
 */


#include "Keypad.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2 }; //,C3};//columns

GPIO_PinConfig_t KEYPAD_pinconfig;


void Wait_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void Keypad_init()
{

	MCAL_GPIO_Enable_ClocK(KEYPAD_PORT);

	KEYPAD_pinconfig.GPIO_PinNumber=R0;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_pull_down;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_Reset_State;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);

	KEYPAD_pinconfig.GPIO_PinNumber=R1;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_pull_down;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_Reset_State;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);

	KEYPAD_pinconfig.GPIO_PinNumber=R2;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_pull_down;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_Reset_State;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);

	KEYPAD_pinconfig.GPIO_PinNumber=R3;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Inp_pull_down;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_Reset_State;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);

	KEYPAD_pinconfig.GPIO_PinNumber=C0;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);

	KEYPAD_pinconfig.GPIO_PinNumber=C1;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);

	KEYPAD_pinconfig.GPIO_PinNumber=C2;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);

	/*KEYPAD_pinconfig.GPIO_PinNumber=C3;
	KEYPAD_pinconfig.GPIO_Mode=GPIO_Mode_Out_push_pull;
	KEYPAD_pinconfig.GPIO_Speed=GPIO_Speed_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT,&KEYPAD_pinconfig);*/


	//MCAL_GPIO_WritePort(KEYPAD_PORT, 0XFF);
	//MCAL_GPIO_WritePin(KEYPAD_PORT, R0, 1);
	//MCAL_GPIO_WritePin(KEYPAD_PORT, R1, 1);
	//MCAL_GPIO_WritePin(KEYPAD_PORT, R2, 1);
	//MCAL_GPIO_WritePin(KEYPAD_PORT, R3, 1);

	MCAL_GPIO_WritePin(KEYPAD_PORT, C0, 0);
	MCAL_GPIO_WritePin(KEYPAD_PORT, C1, 0);
	MCAL_GPIO_WritePin(KEYPAD_PORT, C2, 0);
	//MCAL_GPIO_WritePin(KEYPAD_PORT, C3, 1);

}






char Keypad_getkey()
{
	int i,j;
	for (i = 0; i < 3; i++)
	{
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], 0);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], 0);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], 0);

		//MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], 1);

		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], 1);

		for(j = 0; j < 4; j++)
		{
			if ( (MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j])) == 1 )
			{
				while((MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j])) == 1);
				switch(i)
				{
				case (0):
				if (j == 0) return '1';
				if (j == 1) return '4';
				if (j == 2) return '7';
				if (j == 3) return '*';
				break;
				case (1):
				if (j == 0) return '2';
				if (j == 1) return '5';
				if (j == 2) return '8';
				if (j == 3) return '0';
				break;
				case (2):
				if (j == 0) return '3';
				if (j == 1) return '6';
				if (j == 2) return '9';
				if (j == 3) return '#';
				break;
				/*case (3):
					if (j == 0) return '/';
					else if (j == 1) return '*';
					else if (j == 2) return '-';
					else if (j == 3) return '+';
				break;*/
				}
			}
		}
	}
	return 'N';
}
