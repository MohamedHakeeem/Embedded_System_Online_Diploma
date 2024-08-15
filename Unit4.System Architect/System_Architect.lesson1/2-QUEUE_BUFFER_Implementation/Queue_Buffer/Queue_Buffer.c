/*
 * FIFO_Buffer.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 *
*/

#include "Queue_Buffer.h"
#include "stdio.h"


FIFO_Status_T FIFO_Buffer_Init(FIFO_Buffer_T* S_Buff,element_type* Buff,unsigned int len)
{
	if(Buff==NULL)
		return FIFO_Null;


	S_Buff->base=Buff;
	S_Buff->head=Buff;
	S_Buff->tail=Buff;
	S_Buff->length=len;
	S_Buff->count=0;

	return FIFO_No_Error;



}


FIFO_Status_T FIFO_enqueue(FIFO_Buffer_T* S_Buff,unsigned int  Item)
{

	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
			return FIFO_Null;

	if(FIFO_is_Full(S_Buff)==FIFO_Is_Full)
		return FIFO_Is_Full;



	*(S_Buff->head)=Item;

	//for making the Queue as Circular FIFO......
	if(S_Buff->head==(S_Buff->base + (S_Buff->length)*sizeof(element_type)))
		S_Buff->head=S_Buff->base;
	else
		S_Buff->head++;

	S_Buff->count++;



	return FIFO_No_Error;



}
FIFO_Status_T FIFO_dequeue(FIFO_Buffer_T* S_Buff,unsigned int* Item)
{
	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
		return FIFO_Null;

	if(	S_Buff->count == 0)
			return FIFO_Is_Empty;

	*Item=*(S_Buff->tail);

	//for making the Queue as Circular FIFO......
	if(S_Buff->tail==(S_Buff->base + (S_Buff->length)*sizeof(element_type)))
		S_Buff->tail=S_Buff->base;
	else
		S_Buff->tail++;

	S_Buff->count--;

	return FIFO_No_Error;

}

FIFO_Status_T FIFO_is_Full(FIFO_Buffer_T* S_Buff)
{
	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
			return FIFO_Null;

	if(	S_Buff->count >= S_Buff->length)
			return FIFO_Is_Full;
	else
		return FIFO_Isnt_Full;
}



void FIFO_Print(FIFO_Buffer_T* S_Buff)
{
	element_type* Temp=S_Buff->tail;
	uint8_t i;
	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
		printf("The Buffer is Null\n");

	if(	S_Buff->count == 0)
		printf("The Buffer is Empty\n");

	printf("------------FIFO_Print-----------------\n");
	for(i=0;i<S_Buff->count;i++)
	{
		printf("The Element is %X \n",*(Temp));
		Temp++;

	}
	printf("---------------------------------------\n");


}

