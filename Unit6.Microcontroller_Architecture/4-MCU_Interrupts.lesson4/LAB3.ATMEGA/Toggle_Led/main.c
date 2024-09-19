/*
 * main.c
 *
 *	Toggle Led By External Interrupt .....................
 *  Created on: Sep 17, 2024
 *      Author: Mohamed Abd El Hakeem El Said Ali
 *
 */


/*
 * Clock Configuration............
 * The device is shipped with CKSEL = “0001” and SUT = “10”. The default clock source
 *   setting is therefore the "1 MHz" Internal RC Oscillator
 *
 */

#include <avr/interrupt.h>
#include <util/delay.h>




#define DDRD     *(volatile unsigned char *)(0X31)
#define PORTD     *(volatile unsigned char *)(0X32)
#define PIND     *(volatile unsigned char *)(0X30)


#define MCUCR     *(volatile unsigned char *)(0X55)
#define MCUCSR     *(volatile unsigned char *)(0X54)

#define SREG     *(volatile unsigned char *)(0X5F)
#define GICR     *(volatile unsigned char *)(0X5B)
#define GIFR     *(volatile unsigned char *)(0X5A)

/*
 * EXTI
 * PD2/INT0
 * PD3/INT1
 * PB2/INT2
 *
 * Input Pin
 */


void GPIO_INIT(void)
{
	/*
	 * PORTD PIN7,6,5
	 * As Output
	 */
	DDRD |= ((1 << 5)|(1 << 6) | (1 << 7));
	// Write Initial Value 0.
	PORTD &= ~((1 << 5)|(1 << 6)|(1 << 7));


}


void ExtI_Init(void)
{

	DDRD &= ~((1 << 2)|(1 << 3));   // Set PD2,PD3 (INT0, INT1 pin) as input


	/*Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
	 * 0 1 Any logical change on INT0 generates an interrupt request.
	 */
	MCUCR |= (0b01 << 0);



	/* Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
	 * 1 1 The rising edge of INT1 generates an interrupt request.
	 */
	MCUCR |= (0b11 << 2);


	/* MCUCSR:  Bit 6 – ISC2: Interrupt Sense Control 2
	 * If ISC2 is written to zero, a
	 *falling edge on INT2 activates the interrupt
	 */
	MCUCSR &= ~(1 << 6);



	/*GICR: Bit 7 – INT1: External Interrupt Request 1 Enable
	 *Bit 6 – INT0: External Interrupt Request 0 Enable
	 *Bit 5 – INT2: External Interrupt Request 2 Enable
	 *When the INT0 bit is set (one) and the I-bit [BIT 7] in the Status Register (SREG) is set (one),
	 *the external pin interrupt is enable
	 */
	GICR |= (1 << 5);
	GICR |= ((1 << 6)|(1 << 7));

	//SREG |= (1 << 7 );
	sei();

}



int main()
{



	GPIO_INIT();
	ExtI_Init();


	while(1)
	{

		PORTD &= ~((1 << 5)|(1 << 6));
		PORTD &= ~(1 << 7);

	}



	return 0;
}


ISR(INT0_vect)
{

	PORTD |= (1 << 5);
	_delay_ms(1000);

	/*Bit 6 – INTF0: External Interrupt Flag 0
	 *the flag can be cleared by writing a logical one to it.
	 */
	//GIFR |= (1 << 6);
}

ISR(INT1_vect)
{
	PORTD |= (1 << 6);
	_delay_ms(1000);

	/*Bit 7 – INTF1: External Interrupt Flag 1*/
	//GIFR |= (1 << 7);

}


ISR(INT2_vect)
{
	PORTD |= (1 << 7);
	_delay_ms(1000);

	/* Bit 5 – INTF2: External Interrupt Flag 2*/
	//GIFR |= (1 << 5);



}
