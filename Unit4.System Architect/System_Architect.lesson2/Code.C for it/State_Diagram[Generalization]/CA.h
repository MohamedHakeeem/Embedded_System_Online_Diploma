/*
 * CA.h
 *
 *  Created on: Aug 17, 2024
 *      Author: Mohamed_Hakeem
 *      Collision Avoidance task is the algorithm that control between the another tasks
 */

#ifndef CA_H_
#define CA_H_

#include"state.h"


/*states that you made in the tool of state diagram*/
enum
{
	CA_Waiting,
	CA_Driving

}CA_State_ID;


State_Declare(CA_waiting);
State_Declare(CA_driving);



//global pointer to func;
void (*CA_State)();



#endif /* CA_H_ */
