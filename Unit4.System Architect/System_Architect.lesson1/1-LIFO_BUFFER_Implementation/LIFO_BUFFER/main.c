/*
 * main.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 */


#include "LIFO_Buffer.h"
#include "stdio.h"
#include "stdlib.h"

unsigned int Buffer_I2C[10];
LIFO_Status_T Status;
LIFO_Status_T Status_D;






int main()
{

	LIFO_Buffer_T I2C;
	LIFO_Buffer_T UART;
	unsigned int i,temp,temp_D;

	//Dynamic Allocation  size is 5 *4 --->5 element from unsigned int type
	unsigned int* Buffer_UART=(unsigned int*) malloc(5*sizeof(unsigned int)) ;



	Status=LIFO_Buffer_Init(&I2C,Buffer_I2C,sizeof(Buffer_I2C)/sizeof(Buffer_I2C[0]));
	Status_D=LIFO_Buffer_Init(&UART,Buffer_UART,5);

	printf("----------------Static Allocation---------------\n");
	/*Operation on Buffer_I2C [Static Allocation]*/
	if(Status==LIFO_No_Error)
	{
		LIFO_Status_T Status_Oper;
		for(i=0;i<10;i++)
		{
			if(Status_Oper==LIFO_Is_Full)
			{
				printf("The Buffer is Full\n");
				break;
			}

			Status_Oper=LIFO_Add_Item(&I2C,i);
			printf("The Added Item is: %d\n",i);

		}

		printf("-------------------------------\n");

		for(i=0;i<10;i++)
		{
			if(Status_Oper==LIFO_Is_Empty)
			{
				printf("The Buffer is Empty \n");
				break;
			}

			Status_Oper=LIFO_Get_Item(&I2C,&temp);
			printf("The Got Item is: %d\n",temp);

		}

	}

	printf("----------------Dynamic Allocation---------------\n");
	/*Operation on Buffer_UART [Dynamic Allocation]*/
	if(Status_D==LIFO_No_Error)
	{
		LIFO_Status_T Status_Oper_D;
		for(i=0;i<5;i++)
		{
			if(Status_Oper_D==LIFO_Is_Full)
			{
				printf("The Buffer is Full\n");
				break;
			}

			Status_Oper_D=LIFO_Add_Item(&UART,i);
			printf("The Added Item is: %d\n",i);

		}

		printf("-------------------------------\n");

		for(i=0;i<5;i++)
		{
			if(Status_Oper_D==LIFO_Is_Empty)
			{
				printf("The Buffer is Empty \n");
				break;
			}

			Status_Oper_D=LIFO_Get_Item(&UART,&temp_D);
			printf("The Got Item is: %d\n",temp_D);

		}

	}











	return 0;
}
