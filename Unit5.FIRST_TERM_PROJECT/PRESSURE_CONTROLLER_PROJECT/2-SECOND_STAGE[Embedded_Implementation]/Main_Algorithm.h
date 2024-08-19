/*
 *
 *	Main_Algorithm.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 *      Main_Algorithm task is the algorithm that control between the another tasks
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

#include"state.h"


/*states that you made in the tool of state diagram*/
enum
{
	MA_PressureDetection,
	MA_AlarmOn,
	MA_AlarmOff,

}MA_State_ID;


State_Declare(MA_pressureDetection);
State_Declare(MA_alarmOn);
State_Declare(MA_alarmOff);




//global pointer to func;
void (*MA_State)();



#endif /* MAIN_ALGORITHM_H_ */
