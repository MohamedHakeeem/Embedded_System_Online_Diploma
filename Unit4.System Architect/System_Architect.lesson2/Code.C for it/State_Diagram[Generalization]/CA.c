/*
 * CA.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Mohamed_Hakeem
 *
 *	CA.c[Collision Avoidance] is THE Algorithm
 */

#include "CA.h"

unsigned int distance,speed,threshold=50;
extern void (*CA_State)();



void US_distance_set(int dis)
{

	distance=dis;
	(distance<=threshold)?(CA_State=State_Add(CA_waiting)):(CA_State=State_Add(CA_driving));
	printf("==========the US distance.............. = %d ===============\n",distance);

}

State_Declare(CA_waiting)
{
	CA_State_ID= CA_Waiting ;
	printf("Waiting State--------------------: Speed=%d, Distance=%d\n",speed,distance);

	speed=0;
	DC_motor_set(speed);
}




State_Declare(CA_driving)
{
	CA_State_ID= CA_Driving ;
	printf("Driving State--------------------: Speed=%d, Distance=%d\n",speed,distance);

	speed=30;
	DC_motor_set(speed);
}

