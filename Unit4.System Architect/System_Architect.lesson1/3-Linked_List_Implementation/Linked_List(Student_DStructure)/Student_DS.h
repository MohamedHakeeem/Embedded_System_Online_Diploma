/*
 * Student_DS.h
 *
 *  Created on: Aug 15, 2024
 *      Author: 	Mohamed Hakeem
 */

#ifndef STUDENT_DS_H_
#define STUDENT_DS_H_



#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"


/*Declaration of Nodes of Students*/
typedef struct SNode
{
	unsigned int ID;
	float Height;
	char name[30];
	struct SNode* P_Next;

}Student_Node;

typedef struct
{
	Student_Node* P_Next;
}Dummy;




void Add_Node();
void Delete_Node();
void Print_Nodes();
void Delete_AllNodes();
void Get_Node();
void GetI_Length();
int  GetR_Length(Student_Node* Dummy);
void Get_ReverseNode();
void Get_RevNode2P();
void Get_Middle();
void Reverse_Nodes();






#endif /* STUDENT_DS_H_ */
