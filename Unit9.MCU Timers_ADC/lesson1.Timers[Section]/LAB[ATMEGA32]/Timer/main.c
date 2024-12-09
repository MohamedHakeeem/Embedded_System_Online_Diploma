/*
 * main.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 *
 *
 */


#include  <util/delay.h>
#include "ATMEGA32.h"
#include "avr/interrupt.h"
#include "atmega32_gpio_driver.h"
#include "atmega32_timer_driver.h"

#define F_CPU 1000000UL

//#define WDOG_Test
//#define Timer_Test



void TOIE_Callback()
{
	GPIOA->PORT = ~ GPIOA->PORT ;
	_delay_ms(1000000);

}



void WDT_ON()
{
	WDTCR = (1 << WDP0) | (1 << WDP1) | (1 << WDP2) | (1 << WDE);
}

void WDT_OFF()
{
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}


int main()
{

#ifdef WDOG_Test
	/* Replace with your application code */
	GPIOD->DDR |= 0xC0;


	while (1)
	{
		WDT_ON();
		_delay_ms(100);
		GPIOD->PORT |= (1 << 6);
		WDT_OFF();
	}

#endif


#ifdef Timer_Test
	GPIOA->DDR=0xFF;
	GPIOA->PORT = 0X00;

	ENABLE_GLOBAL_INTERRUPT();

	MCAL_TIMER0_CALLBACK_CompareMatch_INTERRUPT(TOIE_Callback);

	STIMER0_CONFIG TIMER_config;
	TIMER_config.clk= PRESCALING_CLK1024;
	TIMER_config.mode=CTC;
	TIMER_config.ocmInterrupt=OCIE_ENABLE;
	TIMER_config.ovfInterrupt=TOIE_DISABLE;
	MCAL_TIMER0_SetCompareValue(0XF2);
	MCAL_TIMER0_Init(&TIMER_config);

	while(1)
	{


	}
#endif



	return 0 ;
}




