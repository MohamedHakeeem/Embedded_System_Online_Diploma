

/*
 * main.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 */

/*
 * Clock Configuration............
 * The device is shipped with CKSEL = “0100” and SUT = “10”.
 *   setting is therefore the "8 MHz" Internal RC Oscillator
 *
 */

#include <util/delay.h>




#define F_CPU 8000000UL
#define SET_BIT(Register,Bit)     (Register |= (1 << Bit))
#define CLEAR_BIT(Register,Bit)   (Register &= ~(1 << Bit))
#define TOGGLE_BIT(Register,Bit)     (Register ^= (1 << Bit))
#define READ_BIT(Register,Bit)     ((Register >> Bit) & 0x1)


#define DDRC      *(volatile unsigned char *)(0X34)
#define PORTC     *(volatile unsigned char *)(0X35)
#define PINC      *(volatile unsigned char *)(0X33)

#define DDRD      *(volatile unsigned char *)(0X31)
#define PORTD     *(volatile unsigned char *)(0X32)
#define PIND      *(volatile unsigned char *)(0X30)


unsigned int i,j;

void Two_7Segment()
{
	for(i=0 ; i<10 ; i++)
	{
		for(j=0 ; j<10; j++)
		{
			PORTC = 0b1011 | (i << 4);
			_delay_ms(2000);
			PORTC = 0b0111 | (j << 4);
			_delay_ms(2000);
		}
	}
}





void Leds_Series()
{
	for(i=5;i<=8;i++)
	{
		if(i==8)
		{
			for(j=7;j>4;j--)
			{
				CLEAR_BIT(PORTD,j);
				_delay_ms(2000);
			}
			break;
		}
		SET_BIT(PORTD,i);
		_delay_ms(2000);
	}
}

void Buzzer()
{

	if(READ_BIT(PIND,0) == 1)
	{
		SET_BIT(PORTD,4);
	}

	else
	{
		CLEAR_BIT(PORTD,4);

	}

}




int main()
{

	/* PORTC is Configured as Output for Two_7Segment */
	DDRC=0xFF;


	/*Configure PORTD PIN5 ,6 7 as Output For Led_Series */
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);

	/* Configure PORTD PIN0 as Input For Pull_Down Button
	 * PIN4 as Output   Buzzer  */
	SET_BIT(DDRD,4);
	CLEAR_BIT(DDRD,0);

	while(1)
	{



		//Two_7Segment();
		Leds_Series();
		//Buzzer();

	}



	return 0;
}



