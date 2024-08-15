/*
 * LIFO_Buffer.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 *
*/

#include "LIFO_Buffer.h"
#include "stdio.h"


LIFO_Status_T LIFO_Buffer_Init(LIFO_Buffer_T* S_Buff,unsigned int* Buff,unsigned int length)
{
	if(Buff==NULL)
		return LIFO_Null;


	S_Buff->base=Buff;
	S_Buff->head=Buff;
	S_Buff->length=length;
	S_Buff->count=0;

	return LIFO_No_Error;



}


LIFO_Status_T LIFO_Add_Item(LIFO_Buffer_T* S_Buff,unsigned int  Item)
{

	if(S_Buff->base==NULL || S_Buff->head==NULL )
			return LIFO_Null;


	if(	S_Buff->count == S_Buff->length)
		return LIFO_Is_Full;

	*(S_Buff->head++)=Item;
	S_Buff->count++;



	return LIFO_No_Error;



}
LIFO_Status_T LIFO_Get_Item(LIFO_Buffer_T* S_Buff,unsigned int* Item)
{
	if(S_Buff->base==NULL || S_Buff->head==NULL )
			return LIFO_Null;

	if(	S_Buff->count == 0)
			return LIFO_Is_Empty;

	*Item=*(--S_Buff->head);
	S_Buff->count--;

	return LIFO_No_Error;

}



