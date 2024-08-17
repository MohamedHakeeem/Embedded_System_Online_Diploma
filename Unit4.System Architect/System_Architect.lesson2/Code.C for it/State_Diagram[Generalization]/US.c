/*
 * US.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Mohamed_Hakeem
 *	US.c[Ultrasonic_Sensor] is task or file that responsible for  reading the distance and then sending the distance
 *	to the task is called CA.c [Collision Avoidance] that is task that has "algorithm" for achieving the required target
 */


#include "US.h"
unsigned int distance=0;
extern void (*US_State)();






State_Declare(US_init)
{


	//Initialization of US Device
	//Timre initlization
	//....
	US_State_ID=US_Init;
	printf("========The US Init ....... is done=========\n");



}

State_Declare(US_busy)
{

	US_State_ID=US_Busy;
	distance=generate_random(45,55,1);
	printf("US_busy:-------distance=%d\n",distance);

	US_distance_set(distance);
	US_State=State_Add(US_busy);


}





int generate_random(int l,int r,int count)
{
	/* Func generate the random number in range of ( r , l ) */
	int i;
	for(i=0;i<count;i++)
	{
		int rand_num=(rand() % (r-l+1) ) +l;
		return rand_num;
	}

}
