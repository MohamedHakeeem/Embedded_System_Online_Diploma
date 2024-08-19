/*
 * Main_Algorithm.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 *
 *	Main_Algorithm.c is THE Algorithm
 */

#include "Main_Algorithm.h"

unsigned int P_Value,Alarm_Val,Alarm_Period=60,Pressure_Threshold=20;
extern void (*MA_State)();


State_Declare(MA_pressureDetection)
{
	MA_State_ID=MA_PressureDetection;
	MA_State=Set_PressureVal;

}

void Set_PressureVal(int P_Val)
{

	P_Value=P_Val;
	(P_Value<=Pressure_Threshold)?(MA_State=State_Add(MA_alarmOff)):(MA_State=State_Add(MA_alarmOn));

}

State_Declare(MA_alarmOff)
{
	MA_State_ID=MA_AlarmOff;

	/*Value of 1 is Off in Simulation ,so i made it as this*/
	Alarm_Val=1;
	Set_Alarm_State(Alarm_Val);

	MA_State=State_Add(MA_pressureDetection);

}




State_Declare(MA_alarmOn)
{
	MA_State_ID=MA_AlarmOn;

	/*Value of 0 is 1 in Simulation ,so i made it as this*/
	Alarm_Val=0;
	Set_Alarm_State(Alarm_Val);


	MA_State=State_Add(MA_alarmOff);




}


