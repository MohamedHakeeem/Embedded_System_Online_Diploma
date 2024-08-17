/*
 * US.h
 *
 *  Created on: Aug 17, 2024
 *      Author:  Mohamed Hakeem
 */

#ifndef US_H_
#define US_H_

#include"state.h"

int generate_random(int l,int r,int count);


/*states that you made in the tool of state diagram*/
enum
{
	US_Init,
	US_Busy

}US_State_ID;


State_Declare(US_init);
State_Declare(US_busy);


//global pointer to func;
void (*US_State)();


#endif /* US_H_ */
