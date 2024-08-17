/*
 * DC.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Mohamed_Hakeem
 *
 *
 *      DC.c[DC_Motor] is the task that receives actor(speed value) from the algorithm CA.c
 */

#include "DC.h"
unsigned int speed=0;

extern void (*DC_State)();



void DC_motor_set(int spd)
{


	speed=spd;
	DC_State=State_Add(DC_busy);
	printf("DC..........Speed= %d\n",speed);



}


State_Declare(DC_init)
{


	//DC_Motor Initialization
	//PWM module init........
	DC_State_ID=DC_Init;
	printf("===============The DC Init is .......Done================\n");

}

State_Declare(DC_idle)
{
	//it don't  anything ,it leaves the motor on the previous speed
	DC_State_ID=DC_Idle;
	printf("Idle State -----------:Speed=%d\n",speed);



}

State_Declare(DC_busy)
{
	DC_State_ID=DC_Busy;
	//send PWM to DC motor
	printf("Busy_State------------: Speed= %d\n",speed);
	DC_State=State_Add(DC_idle);

}
