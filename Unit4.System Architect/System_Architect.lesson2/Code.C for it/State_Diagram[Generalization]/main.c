/*
 * main.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Mohamed_Hakeem
 *
 *      Main.c is considered as the "APP" it is executed for the all system
 */

#include "CA.h"
#include "US.h"
#include "DC.h"


void setup_app()
{


	//init all drivers
	//init IRQn
	//init HAL US_DRIVER  DC DRIVER
	//init Blocks
	State_Declare(DC_init);
	State_Declare(US_init);


	//set states pointers for each first task'states
	US_State=State_Add(US_busy);
	CA_State=State_Add(CA_waiting);
	DC_State=State_Add(DC_idle);

}




int main()
{

	volatile int i=0;
	setup_app();


	while(1)
	{
		//call the pointer to function respectively according to your state diagram
		US_State();
		CA_State();
		DC_State();

		for(i=0;i<1000;i++);//delay

	}



	return 0;
}


