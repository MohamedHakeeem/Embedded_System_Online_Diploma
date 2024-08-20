/*
 * Student_DS.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Mohamed_Hakeem
 */

#ifndef STUDENT_DS_H_
#define STUDENT_DS_H_

#include <stdio.h>
#include <stdint.h>


/*Generic Queue ,so You have to set the data type of configuration
 * you can select from these types ----> uint8_t, uint16_t, uint32_t ,...... or Struct type...>>>>> normal
 * */

typedef struct
{
	char Fname[50];
	char Lname[50];
	int roll;
	float GPA;
	int No_Courses;
	int Courses_ID[10];

}SStudent;


#define element_type  SStudent

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


FIFO_Status_T FIFO_Buffer_Init(FIFO_Buffer_T* S_Buff,element_type* Buff,unsigned int len);
FIFO_Status_T FIFO_is_Full(FIFO_Buffer_T* S_Buff);

void add_sstduent_file(FIFO_Buffer_T* S_Buff);
void add_student_manually(FIFO_Buffer_T* S_Buff);
void get_student_fifo(FIFO_Buffer_T* S_Buff,element_type*  Item);
void find_by_roll(FIFO_Buffer_T* S_Buff);
void find_by_firstname(FIFO_Buffer_T* S_Buff);
void find_by_courseid(FIFO_Buffer_T* S_Buff);
void how_tot_s(FIFO_Buffer_T* S_Buff);
void del_s(FIFO_Buffer_T* S_Buff);
void update_s(FIFO_Buffer_T* S_Buff);
void show_s(FIFO_Buffer_T* S_Buff);





#endif
