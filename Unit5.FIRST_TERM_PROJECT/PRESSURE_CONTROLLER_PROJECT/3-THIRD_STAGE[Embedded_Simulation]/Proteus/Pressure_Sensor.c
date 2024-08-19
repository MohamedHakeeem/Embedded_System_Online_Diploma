/*
 * Pressure_Sensor.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 *
 *	[Pressure_Sensor] is task or file that responsible for  reading the Pressure and then sending it 
 *	to the task is called  [Main_Algorithm] that is task that has "algorithm" for achieving the required target
 */


#include "Pressure_Sensor.h"
unsigned int P_Val=0;
extern void (*PS_State)();






State_Declare(PS_init)
{

	PS_State_ID=PS_Init;



}

State_Declare(PS_read)
{

	PS_State_ID=PS_Read;
	P_Val=getPressureVal();

	Set_PressureVal(P_Val);



	/*Go back to the same state 'PS_read'*/
	PS_State=State_Add(PS_read);


}


