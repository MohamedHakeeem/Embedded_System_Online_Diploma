/*
 * main.c
 * TIMER0 [8 bits Counter]
 *  Created on: Nov 13, 2024
 *      Author: Mohamed Abd El Hakeem EL Said Ali.
 *
 *
 */


#include  <util/delay.h>
#include "ATMEGA32.h"
#include "atmega32_gpio_driver.h"
#include "atmega32_PWM_driver.h"
#include "atmega32_spi_driver.h"



#define F_CPU		8000000UL



uint8_t Gate_entry_state;
uint8_t IR_state;

void SERVO_INIT(void);
void SERVO_RUN(void);


void TOIE_Callback()
{	
	MCAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
}




int main()
{

	SERVO_INIT();
	while(1)
	{
		SERVO_RUN();
	}

	return 0 ;
}





void SERVO_INIT(void)
{
	GPIO_PinConfig_t pwmgpio_cnfg;
	pwmgpio_cnfg.GPIO_Mode=GPIO_Mode_Out_push_pull;
	pwmgpio_cnfg.GPIO_PinNumber=GPIO_PIN_3;
	MCAL_GPIO_Init(GPIOB,&pwmgpio_cnfg);

	MCAL_PWM_SETCALLBACK_OVF_INTERRUPT(TOIE_Callback);

	PWM_CONFIG_T PWM_config;
	PWM_config.CLCK=PWM_PRESC_CLCK64; //------> 125000z ------>T(CLK)=8*10^(-6) -------->T(Periodic)=2ms
	PWM_config.MODE=PH_CORRECT_PWM;
	PWM_config.STATE=PWM_NON_INVERTING;
	PWM_config.OCM_INTERRUPT=PWM_OCIE_DISABLE;
	PWM_config.OVF_INTERRUPT=PWM_TOIE_ENABLE;

	MCAL_PWM_SET_CMP_VALUE(0);
	MCAL_PWM_INIT(&PWM_config);
	
	
	GPIO_PinConfig_t Gpio_cnfg;
	Gpio_cnfg.GPIO_Mode=GPIO_Mode_Inp_Floating;
	Gpio_cnfg.GPIO_PinNumber=GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOA,&Gpio_cnfg);
	

	Gpio_cnfg.GPIO_Mode=GPIO_Mode_Inp_Floating;
	Gpio_cnfg.GPIO_PinNumber=GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA,&Gpio_cnfg);
	
	
	
}


void SERVO_RUN(void)
{
	Gate_entry_state=MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
	IR_state=MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1);
	if(Gate_entry_state==GPIO_PIN_SET)
	{
		//Open the gate ..... servo.
		//to get 90 degree , so you should make duty cycle equal........1.5ms on the periodic time
		//But for Proteus, I tuned the angles for the servo .....................
		MCAL_PWM_SET_CMP_VALUE(94);
		
		while(!MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET || !MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1) ==GPIO_PIN_RESET );
		_delay_ms(10);
		MCAL_PWM_SET_CMP_VALUE(0);
	}
	
}
