/*
 * LIFO_Buffer.h
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 */

#ifndef LIFO_BUFFER_H_
#define LIFO_BUFFER_H_



// Definition of Data type for LIFO_Buffer
typedef struct
{
	unsigned int* base;
	unsigned int* head;
	unsigned int length;
	unsigned int count;


}LIFO_Buffer_T;



//Status of Return type
typedef enum {
	LIFO_No_Error,
	LIFO_Null,
	LIFO_Is_Full,
	LIFO_Is_Empty

}LIFO_Status_T;


//Declaration for Methods[APIS]
/*LIFO_Mechanism
 *Mechanism depends on Stack Idea
 *1-Add_Item() does Push Mechanism  the same as Stack Push
 *2-Get_Item() does Pop Mechanism
 */

LIFO_Status_T LIFO_Add_Item(LIFO_Buffer_T* S_Buff,unsigned int  Item);
LIFO_Status_T LIFO_Get_Item(LIFO_Buffer_T* S_Buff,unsigned int* Item);
LIFO_Status_T LIFO_Buffer_Init(LIFO_Buffer_T* S_Buff,unsigned int* Buff,unsigned int length);




#endif /* LIFO_BUFFER_H_ */
