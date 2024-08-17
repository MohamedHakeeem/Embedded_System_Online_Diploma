/*
 * state.h
 *
 *  Created on: Aug 17, 2024
 *      Author: Mohamed_Hakeem
 */

#ifndef STATE_H_
#define STATE_H_


#include <stdio.h>
#include <stdlib.h>

/*Factory of function for the tasks*/
#define State_Declare(State_Fun)    void State_Fun()
#define State_Add(State_Fun)  State_Fun





/*Functions to communicate between the task and each other*/
void US_distance_set(int dis);//map between the tasks "Ultra_sonic " & "Collision Avoidance" :using this func in CA
void DC_motor_set(int spd);//map between the tasks "Collision Avoidance" & "Dc_Motor  :using this func in DC



#endif /* STATE_H_ */
