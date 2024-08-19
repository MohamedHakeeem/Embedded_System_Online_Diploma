/*
 * state.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng:Mohamed Abd El Hakeem El Said Ali
 */

#ifndef STATE_H_
#define STATE_H_


#include <stdio.h>
#include <stdlib.h>

/*Factory of function for the tasks*/
#define State_Declare(State_Fun)    void State_Fun()
#define State_Add(State_Fun)  State_Fun





/*Functions to communicate between the task and each other*/
//Map between the tasks "Pressure_Sensor " & "MainALgorithm" :using this func in MainAlgorithm
void Set_PressureVal(int P_Val);
//Map between the tasks "MainALgorithm" & "Alarm_Actuator"  :using this func in Alarm_Actuator
void Set_Alarm_State(int Alarm_Val);


#endif /* STATE_H_ */
