/*
 * DC.h
 *
 *  Created on: Aug 17, 2024
 *      Author: Mohamed_Hakeem
 */

#ifndef DC_H_
#define DC_H_



#include"state.h"


/*states that you made in the tool of state diagram*/
enum
{
	DC_Init,
	DC_Idle,
	DC_Busy

}DC_State_ID;


State_Declare(DC_init);
State_Declare(DC_idle);
State_Declare(DC_busy);


//global pointer to func;
void (*DC_State)();





#endif /* DC_H_ */
