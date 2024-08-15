/*
 * main.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 */


#include "Queue_Buffer.h"
#include "stdio.h"


/*
 * #define B_length         5
 * element_type Buffer_Uart[B_length] ;
 */

#define B_length         5
element_type Buffer_Uart[B_length] ;

FIFO_Status_T Status;






int main()
{

	FIFO_Buffer_T  UART;
	unsigned int i,temp;



	Status=FIFO_Buffer_Init(&UART,Buffer_Uart,B_length);


	if(Status==FIFO_No_Error)
	{
		printf("FIFO_Buffer_Init is done\n");

		FIFO_Status_T Status_Oper;
		printf("Moving to Enqueueing process...\n");
		for(i=0;i<5;i++)
		{
			if(Status_Oper==FIFO_Is_Full)
			{
				printf("FIFO_Enqueue is failed -----_____-----\n");
				break;
			}

			Status_Oper=FIFO_enqueue(&UART,i);
			printf("The Enqueued item:%X \n FIFO_Enqueue is done ^^^______^^^ \r\n ",i);

		}

		FIFO_Print(&UART);
		printf("Moving to Dequeueing process...\n");

		for(i=0;i<2;i++)
		{
			if(Status_Oper==FIFO_Is_Empty)
			{
				printf("FIFO_Enqueue is failed -----_____-----\n");
				break;
			}

			Status_Oper=FIFO_dequeue(&UART,&temp);
			printf("The Dequeued item:%X \n FIFO_Dequeue is done ^^^______^^^ \n ",temp);

		}

	}

	FIFO_Print(&UART);

	return 0;
}
