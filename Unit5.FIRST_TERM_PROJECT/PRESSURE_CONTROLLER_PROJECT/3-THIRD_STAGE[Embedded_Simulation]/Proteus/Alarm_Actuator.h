/*
 * Alarm_Actuator.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 *
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_



#include"state.h"


/*states that you made in the tool of state diagram*/
enum
{
	AL_Init,
	AL_AlarmSet,

}AL_State_ID;


State_Declare(AL_init);
State_Declare(AL_alarmSet);


//global pointer to func;
void (*AL_State)();





#endif /* ALARM_ACTUATOR_H_ */
