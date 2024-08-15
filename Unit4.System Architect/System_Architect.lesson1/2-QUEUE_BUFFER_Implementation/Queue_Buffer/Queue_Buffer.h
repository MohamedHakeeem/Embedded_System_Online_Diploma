/*
 * Queue_Buffer.h
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 */

#ifndef QUEUE_BUFFER_H_
#define QUEUE_BUFFER_H_

#include <stdio.h>
#include <stdint.h>


/*Generic Queue ,so You have to set the data type of configuration
 * you can select from these types ----> uint8_t, uint16_t, uint32_t ,......
 * */

#define element_type  uint8_t

/*HINT:
 * you must make  your buffer of data according to this element_type
 * Ci:in main.c , you can write
 *
 * #define B_length         5
 * element_type Buffer_Uart[B_length] ;
 *
 * */



//Structure of Queue Buffer
typedef struct
{

	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;


}FIFO_Buffer_T;



//Status of Return type
typedef enum {
	FIFO_No_Error,
	FIFO_Null,
	FIFO_Is_Full,
	FIFO_Is_Empty,
	FIFO_Isnt_Full

}FIFO_Status_T;


//Declaration for Methods[APIS]
/*FIFO_Mechanism
 *Mechanism depends on Queue Idea
 *FIFO_enqueue adds data by passing it in the argument Item , with Refrence of  your buffer structure
 *FIFO_dequeue take data by passign the refrence of the buffer you want to receive data  in it , but you
 * takes data with First In First Out Mechanism.
 */

FIFO_Status_T FIFO_enqueue(FIFO_Buffer_T* S_Buff,unsigned int  Item);
FIFO_Status_T FIFO_dequeue(FIFO_Buffer_T* S_Buff,unsigned int* Item);
FIFO_Status_T FIFO_Buffer_Init(FIFO_Buffer_T* S_Buff,element_type* Buff,unsigned int len);
FIFO_Status_T FIFO_is_Full(FIFO_Buffer_T* S_Buff);
void FIFO_Print(FIFO_Buffer_T* S_Buff);





#endif
