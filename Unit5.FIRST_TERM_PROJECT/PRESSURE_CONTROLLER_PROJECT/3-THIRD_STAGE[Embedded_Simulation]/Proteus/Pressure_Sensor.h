/*
 * Pressure_Sensor.h
 *
 * Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include"state.h"

int generate_random(int l,int r,int count);


/*states that you made in the tool of state diagram*/
enum
{
	PS_Init,
	PS_Read,

}PS_State_ID;


State_Declare(PS_init);
State_Declare(PS_read);


//global pointer to func;
void (*PS_State)();


#endif /* PRESSURE_SENSOR_H_ */
