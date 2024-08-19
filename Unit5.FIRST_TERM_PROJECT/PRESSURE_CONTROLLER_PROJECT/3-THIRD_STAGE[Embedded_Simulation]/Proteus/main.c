/*
 * main.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 *
 *      Main.c is considered as the "APP" it is executed for the all system
 */

#include <stdint.h>
#include <stdio.h>
#include "driver.h"


#include "Alarm_Actuator.h"
#include "Main_Algorithm.h"
#include "Pressure_Sensor.h"


void setup_app()
{

	GPIO_INITIALIZATION();
	State_Declare(AL_init);
	State_Declare(PS_init);



	//set states pointers for each first task'states
	PS_State=State_Add(PS_read);
	MA_State=State_Add(MA_pressureDetection);
	AL_State=State_Add(AL_alarmSet);

}




int main()
{

	setup_app();


	while(1)
	{
		//call the pointer to function respectively according to your state diagram
		PS_State();
		MA_State();
		AL_State();
		if(MA_State_ID==MA_AlarmOn)
		{
			/*Set Timer to 60 s for waiting the turning on of alarm*/
			Delay(2000000);
			MA_State();
			AL_State();



		}
		else
		{
			//Do Nothing
		}

		
	}



	return 0;
}



