/*
 * Student_DS.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Mohamed_Hakeem
 *
 * Create New Node of Student in Dynamic Allocation----Heap Section---
 * -------------------------------------------------------------------
 * Why should we use Dynamic Allocation in linked list?
 * Advantage: The newNode remains in memory after the function
 * ends and un_stacking occurs.
 * allowing it to be linked to other nodes in a persistent linked list.
 *
 * A structure declared as a local variable in a function can't
 * be used in a linked list because it will be destroyed when
 * the function returns.
 *
 *
 *
 */


#include"Student_DS.h"

/*Initialization of Dummy*/
Dummy Dummy_Node={NULL};

void Add_Node()
{
	char temp[30];

	Student_Node *New_Node;
	New_Node=(Student_Node*)malloc(sizeof(Student_Node));

	if(New_Node==NULL)
	{
		printf("the Heap is full\n");
		return ;
	}


	/*Last_Index*/
	Student_Node *Last_Index;

	/*Case1:Empty List---------------------------------------------------*/
	/*-------------------------------------------------------------------*/
	if(Dummy_Node.P_Next==NULL)
	{

		Dummy_Node.P_Next=	New_Node;
		New_Node->P_Next=NULL;

	}

	/*Case2:Not Empty List---------------------------------------------------*/
	/*-----------------------------------------------------------------------*/
	else
	{

		Last_Index=Dummy_Node.P_Next;
		while(Last_Index->P_Next !=NULL)
		{
			Last_Index=Last_Index->P_Next;
		}

		Last_Index->P_Next=New_Node;
		New_Node->P_Next=NULL;
	}
	/*-----------------------------------------------------------------------*/

	/*Filling the Node By User-----------------------------------------------*/
	/*-----------------------------------------------------------------------*/
	printf("Please enter the data of student:\n");
	printf("Enter the ID:");fflush(stdout);
	scanf("%u",&(New_Node->ID));fflush(stdin);

	printf("Enter the name:");fflush(stdout);
	gets(New_Node->name);fflush(stdin);

	printf("Enter the height:");fflush(stdout);
	gets(temp);fflush(stdin);
	New_Node->Height=atof(temp);

	/*-----------------------------------------------------------------------*/


}


void Delete_Node()
{

	unsigned int Required_ID;
	printf("Please Enter the Required Id to remove it:\n");fflush(stdout);
	scanf("%u",&Required_ID);fflush(stdin);


	/*----------------Required index as a local pointer----------------- */
	Student_Node* Required_Index=Dummy_Node.P_Next;
	Student_Node* Previous_Index=NULL;
	/*-------------------------------------------------------------------*/


	/*Not Empty List-----------------------------------------------------*/
	/*-------------------------------------------------------------------*/
	if(Dummy_Node.P_Next!=NULL)
	{
		while(Required_Index!=NULL)
		{
			if(Required_Index->ID==Required_ID)
			{
				/*In case of the Required Index is the first Node,then WE don't enter the loop
				 *,so Previous_Index=Null,Required_Index is the First node
				 * */
				if(Previous_Index==NULL)
				{
					Dummy_Node.P_Next=Required_Index->P_Next;
				}
				else
				{
					Previous_Index->P_Next=Required_Index->P_Next;

				}
				free(Required_Index);
				return;

			}

			Previous_Index=Required_Index;
			Required_Index=Required_Index->P_Next;


		}
		printf("The Required Id is not found,Please you make sure Id is Valid \n");
		return;
	}

	printf("^^^^^_____The list is an Empty____^^^^^\n");
	/*-------------------------------------------------------------------*/
}

void Print_Nodes()
{

	Student_Node* Current_Index=Dummy_Node.P_Next;
	int count=0;
	if(Dummy_Node.P_Next==NULL)
	{

		printf("The List is an Empty\n ");
	}
	else
	{
		while(Current_Index!=NULL)
		{

			printf("==================================================\n");
			printf("The Record Number %d \n:",count+1);
			printf("\tThe ID is %u \n:",Current_Index->ID);
			printf("\tThe Name is %s \n:",Current_Index->name);
			printf("\tThe Height is %f \n:",Current_Index->Height);
			printf("==================================================\n");



			Current_Index=Current_Index->P_Next;
			count++;
		}
	}
}




void Delete_AllNodes()
{

	Student_Node* Current_Index=Dummy_Node.P_Next;
	if(Dummy_Node.P_Next==NULL)
	{

		printf("The List is an Empty\n ");
	}
	else
	{
		while(Current_Index!=NULL)
		{
			Student_Node* Temp_Index=Current_Index;
			Current_Index=Current_Index->P_Next;
			free(Temp_Index);
		}


		Dummy_Node.P_Next=NULL;
	}
}



void Get_Node()
{

	int Node_I,Count=0;
	Student_Node* Current_Node=Dummy_Node.P_Next;

	printf("Please Enter the Index of Node [0,1,2,3,....]\n");fflush(stdout);
	scanf("%d",&Node_I);fflush(stdin);

	/*Check if it is empty or not*/
	if(Dummy_Node.P_Next!=NULL)
	{

		while(Current_Node!=NULL)
		{

			if(Node_I==Count)
			{

				printf("==================================================\n");
				printf("The Record Number %d \n:",Count+1);
				printf("\tThe ID is %u \n:",Current_Node->ID);
				printf("\tThe Name is %s \n:",Current_Node->name);
				printf("\tThe Height is %f \n:",Current_Node->Height);
				printf("==================================================\n");
				return;
			}


			Current_Node=Current_Node->P_Next;
			Count++;


		}
		printf("The index is not valid\n");



	}

}



/**************Iterative Method******************************/
void GetI_Length()
{

	int Length=0;
	Student_Node* Current_Node=Dummy_Node.P_Next;


	/*Check if it is empty or not*/
	if(Dummy_Node.P_Next!=NULL)
	{

		while(Current_Node!=NULL)
		{


			Current_Node=Current_Node->P_Next;
			Length++;



		}

		printf("Length is %d\n",Length);

	}



}

/*************************Recursive Method*************************************/
int GetR_Length(Student_Node* Dummy)
{
	if(Dummy==NULL)
	{
		return 0;
	}
	else
	{
		return (1+GetR_Length(Dummy->P_Next));
	}

}


/*****************By Length,Ger Reverse Index ****************************/
void Get_ReverseNode()
{
	int Node_RI,Count=0;
	int Len;
	Student_Node* Current_Node=Dummy_Node.P_Next;

	printf("Please Enter the Reverse Index of Node [...,4,3,2,1]\n");fflush(stdout);
	scanf("%d",&Node_RI);fflush(stdin);

	/*Get the length of List First*/
	Len=GetR_Length(Dummy_Node.P_Next);
	Len=Len-Node_RI;

	/*Check if it is empty or not*/
	if(Dummy_Node.P_Next!=NULL)
	{

		while(Current_Node!=NULL)
		{

			if(Len==Count)
			{

				printf("==================================================\n");
				printf("The Record Number %d \n:",Count+1);
				printf("\tThe ID is %u \n:",Current_Node->ID);
				printf("\tThe Name is %s \n:",Current_Node->name);
				printf("\tThe Height is %f \n:",Current_Node->Height);
				printf("==================================================\n");
				return;
			}


			Current_Node=Current_Node->P_Next;
			Count++;

		}
		printf("The index is not valid\n");

	}
}

/******************By Two Pointer , Get Reverse Index************************/
void Get_RevNode2P()
{

	int N,Count=0;
	Student_Node* Main_Index=Dummy_Node.P_Next;
	Student_Node* Ref_Index=Dummy_Node.P_Next;


	printf("Please Enter the Reverse Index of Node [....4,3,2,1]\n");fflush(stdout);
	scanf("%d",&N);fflush(stdin);

	/*Check if it is empty or not*/
	if(Dummy_Node.P_Next!=NULL)
	{
		while(Ref_Index!=NULL)
		{

			if(Count==N)
			{

				while(Ref_Index!=NULL)
				{
					Ref_Index=Ref_Index->P_Next;
					Main_Index=Main_Index->P_Next;

				}
				if(Main_Index)
				{
					printf("==================================================\n");
					printf("The Record Number From The End %d \n:",N);
					printf("\tThe ID is %u \n:",Main_Index->ID);
					printf("\tThe Name is %s \n:",Main_Index->name);
					printf("\tThe Height is %f \n:",Main_Index->Height);
					printf("==================================================\n");
					return;
				}



			}

			Count++;
			Ref_Index=Ref_Index->P_Next;


		}

		/*To hold the First Index if you select the last reverse indx*/
		if(Count==N)
		{
			if(Main_Index)
			{
				printf("==================================================\n");
				printf("The Record Number From The End %d \n:",N);
				printf("\tThe ID is %u \n:",Main_Index->ID);
				printf("\tThe Name is %s \n:",Main_Index->name);
				printf("\tThe Height is %f \n:",Main_Index->Height);
				printf("==================================================\n");
				return;
			}



		}
		// If the loop exits and Count is still less than N,
		//it means N is greater than the list length
		else if (Count < N)
		{
			printf("The reverse index exceeds the length of the list.\n");
			return;
		}

		else
		{
			//Do Nothing..............................
		}




	}
	printf("The List Is Empty\n");
}





/*Floyd’s Cycle-Finding Algorithm:this depending of two pointer */
void Get_Middle()
{

	Student_Node* Slow_Index=Dummy_Node.P_Next;
	Student_Node* Fast_Index=Dummy_Node.P_Next;

	/*Check if it is empty or not*/
	if(Dummy_Node.P_Next!=NULL)
	{

		while (Fast_Index != NULL && Fast_Index->P_Next != NULL)
		{
			Fast_Index = Fast_Index->P_Next->P_Next; /* Fast pointer moves two steps */
			Slow_Index = Slow_Index->P_Next;         /* Slow pointer moves one step */
		}

		printf("==================================================\n");
		printf("The Middle Node \n:");
		printf("\tThe ID is %u \n:",Slow_Index->ID);
		printf("\tThe Name is %s \n:",Slow_Index->name);
		printf("\tThe Height is %f \n:",Slow_Index->Height);
		printf("==================================================\n");



	}
}



/*Reverse The  Nodes in List*/
void Reverse_Nodes()
{

	Student_Node* Previous_Index = NULL;
	Student_Node* Current_Index = Dummy_Node.P_Next;
	Student_Node* Next_Index = NULL;

	while (Current_Index != NULL) {
		// Save the next node
		Next_Index = Current_Index->P_Next;

		// Reverse the current node's pointer
		Current_Index->P_Next = Previous_Index;

		// Move pointers one position ahead
		Previous_Index = Current_Index;

		//After reversing Pointer_Next between Previousindex and  Currentindex
		Current_Index = Next_Index;
	}

	// Update the head of the list
	Dummy_Node.P_Next = Previous_Index;




}


