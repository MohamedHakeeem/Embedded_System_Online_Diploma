/*
 * Alarm_Actuator.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 *
 *
 *      [Alarm_Actuator] is the task that receives actor(Alarm value) from the algorithm Main_Algorithm.c
 */

#include "Alarm_Actuator.h"
unsigned int Alarm_Value=0;

extern void (*AL_State)();



void Set_Alarm_State(int Alarm_Val)
{


	Alarm_Value=Alarm_Val;
	AL_State=State_Add(AL_alarmSet);



}


State_Declare(AL_init)
{

	AL_State_ID=AL_Init;

}


State_Declare(AL_alarmSet)
{
	AL_State_ID=AL_AlarmSet;
	//send Alarm_Value to Alarm_Actuator
	Set_Alarm_actuator(Alarm_Value);
	AL_State=State_Add(AL_alarmSet);

}
