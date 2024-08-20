/*
 * FIFO_Buffer.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 *
 */

#include "Student_DS.h"

#include "stdio.h"
#include "string.h"



#define DPRINTF(...) fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);






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
FIFO_Status_T FIFO_is_Full(FIFO_Buffer_T* S_Buff)
{
	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
		return FIFO_Null;

	if(	S_Buff->count >= S_Buff->length)
		return FIFO_Is_Full;
	else
		return FIFO_Isnt_Full;

}


void add_sstduent_file(FIFO_Buffer_T* S_Buff)
{

	FILE *fptr;
	char line[200];
	element_type  Item;

	// Open the file in read mode
	fptr = fopen("students.txt", "r");
	if (fptr == NULL) {
		DPRINTF("Error: Could not open file\n");
		return ;
	}

	DPRINTF("|=============================Add_Student file to Data ======================================|\n");

	// Read each line and parse the information
	while (fgets(line, sizeof(line), fptr))
	{

		// Parse the main student information
		sscanf(line, "%d %s %s %f %d", &Item.roll, Item.Fname, Item.Lname, &Item.GPA, &Item.No_Courses);
		DPRINTF("|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Roll Number:%d  Added =========================|\n",Item.roll);

		// Parse the first address of line to ptr.
		char *ptr = line;
		for (int i = 0; i < 5; i++)
		{
			/*
			 * strchr():Move the pointer to the next space ,i<5 to move the fifth space
			 * [I mean it will jump to element 6 [Courses Id ]]
			 */
			ptr = strchr(ptr, ' ') + 1;

		}

		for (int i = 0; i < Item.No_Courses; i++) {
			sscanf(ptr, "%d", &Item.Courses_ID[i]);
			ptr = strchr(ptr, ' ') + 1; // Move the pointer to the next space
		}

		*(S_Buff->head)=Item;

		//for making the Queue as Circular FIFO......
		if(S_Buff->head==(S_Buff->base + (S_Buff->length)*sizeof(element_type)))
			S_Buff->head=S_Buff->base;
		else
			S_Buff->head++;

		S_Buff->count++;
	}

	// Close the file
	fclose(fptr);
	DPRINTF("|===============================================================================================|\n");


}






void add_student_manually(FIFO_Buffer_T* S_Buff)
{

	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer of Students is not found ------\n");}

	if(FIFO_is_Full(S_Buff)==FIFO_Is_Full)
	{DPRINTF("the Buffer of Students is full\n");}

	DPRINTF("|====================================Add_Student==================================================|\n");

	element_type  Item;
	DPRINTF("Please enter info of student:\n");
	DPRINTF("First_Name:");
	gets(Item.Fname);

	DPRINTF("Last_Name:");
	gets(Item.Lname);

	DPRINTF("Roll Number:");
	scanf("%d",&Item.roll);

	DPRINTF("GPA:");
	scanf("%f",&Item.GPA);

	DPRINTF("number of Courses:");
	scanf("%d",&Item.No_Courses);

	DPRINTF("Courses_Id respectively:");

	int j=0;
	for(j=0;j<Item.No_Courses;j++)
	{
		scanf("%d",&Item.Courses_ID[j]);
	}


	int i=0;

	for(i=0;i<S_Buff->count;i++)
	{
		if(((S_Buff->tail+i)->roll)==Item.roll)
		{
			DPRINTF("The Roll Number is already used for student:%s \n",(S_Buff->tail+i)->Fname);
			return;
		}
	}

	*(S_Buff->head)=Item;

	//for making the Queue as Circular FIFO......
	if(S_Buff->head==(S_Buff->base + (S_Buff->length)*sizeof(element_type)))
		S_Buff->head=S_Buff->base;
	else
		S_Buff->head++;

	S_Buff->count++;

	DPRINTF("|===============================================================================================|\n");


}



void get_student_fifo(FIFO_Buffer_T* S_Buff,element_type*  Item)
{

	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer of Students is not found ------\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("the Buffer of Students is empty \n");}

	*Item=*(S_Buff->tail);

	//for making the Queue as Circular FIFO......
	if(S_Buff->tail==(S_Buff->base + (S_Buff->length)*sizeof(element_type)))
		S_Buff->tail=S_Buff->base;
	else
		S_Buff->tail++;

	S_Buff->count--;

}



void find_by_roll(FIFO_Buffer_T* S_Buff)
{
	int roll;

	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer of Students is not found ------\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("The Buffer of Students is empty \n");}

	DPRINTF("|===============================Find_Student= Roll==============================================|\n");
	DPRINTF("Enter The roll number :");
	scanf("%d",&roll);

	int i=0,j=0;
	for(i=0;i<S_Buff->count;i++)
	{
		if(((S_Buff->tail+i)->roll)==roll)
		{
			DPRINTF(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Info of Roll Number [%d]:\n",(S_Buff->tail+i)->roll);
			DPRINTF("First name : %s \n",(S_Buff->tail+i)->Fname);
			DPRINTF("Last  name : %s \n",(S_Buff->tail+i)->Lname);
			DPRINTF("GPA        : %.2f \n",(S_Buff->tail+i)->GPA);
			DPRINTF("Courses:");
			for(j=0;j<(S_Buff->tail+i)->No_Courses;j++)
			{
				DPRINTF(" %d",(S_Buff->tail+i)->Courses_ID[j]);

			}
			DPRINTF("\n|===============================================================================================|\n");
			return;

		}
	}

	DPRINTF("<<<<<<<<<<<<<<<<<<<<The Roll Number is not valid, Please check your input ^____^>>>>>>>>>>>>>>>>>>>>>\n");

}
void find_by_firstname(FIFO_Buffer_T* S_Buff)
{
	char firstname[50];
	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer of Students is not found ------\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("the Buffer of Students is empty \n");}

	DPRINTF("|==================================Find_Student== FirstName======================================|\n");

	DPRINTF("Enter The first name number:");
	gets(firstname);


	int i=0,j=0,check=0;
	for(i=0;i<S_Buff->count;i++)
	{
		if(!stricmp(((S_Buff->tail+i)->Fname),firstname))
		{
			DPRINTF(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Info of Roll Number [%d]:\n",(S_Buff->tail+i)->roll);
			DPRINTF("First name : %s \n",(S_Buff->tail+i)->Fname);
			DPRINTF("Last  name : %s \n",(S_Buff->tail+i)->Lname);
			DPRINTF("GPA        : %.2f \n",(S_Buff->tail+i)->GPA);
			DPRINTF("Courses:");
			for(j=0;j<(S_Buff->tail+i)->No_Courses;j++)
			{
				DPRINTF(" %d ",(S_Buff->tail+i)->Courses_ID[j]);

			}
			DPRINTF("\n|===============================================================================================|\n");
			check++;

		}
	}

	if(check==0)
	{
		DPRINTF("<<<<<<<<<<<<<<<<<<<<<<<<The First name is not valid, Please check your input ^____^>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	}



}


void find_by_courseid(FIFO_Buffer_T* S_Buff)
{
	int  courseid;

	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer of Students is not found ------\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("the Buffer of Students is empty \n");}


	DPRINTF("|===================================Find_Student== Course_ID===================================|\n");

	DPRINTF("Enter The Course Id :");
	scanf("%d",&courseid);
	int l;
	element_type* temp=(S_Buff->tail);

	for(l=0;l<S_Buff->count;l++)
	{
		if((S_Buff->tail+l)->No_Courses <(S_Buff->tail+l+1)->No_Courses)
		{
			temp=(S_Buff->tail+l+1);
		}

	}

	int Max_No_Course=temp->No_Courses;

	int i=0,j=0,check=0;
	for(i=0;i<S_Buff->count;i++)
	{
		for(j=0;j<Max_No_Course;j++)
		{
			if(((S_Buff->tail+i)->Courses_ID[j])==courseid)
			{
				DPRINTF(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Info of Roll Number [%d]:\n",(S_Buff->tail+i)->roll);
				DPRINTF("First name : %s \n",(S_Buff->tail+i)->Fname);
				DPRINTF("Last  name : %s \n",(S_Buff->tail+i)->Lname);
				DPRINTF("GPA        : %.2f \n",(S_Buff->tail+i)->GPA);
				DPRINTF("|===============================================================================================|\n");
				check++;

			}

		}

	}

	if(check!=0)
	{
		DPRINTF("<<<<<<<<<<<<<<<<<<<<<<<<<<The Total Number of Student are Enrolled in This Course: %d \n>>>>>>>>>>>>>>>>>>>>>>",check);

	}
	else
	{
		DPRINTF("<<<<<<<<<<<<<<<<<<<<<<<<<<<The Course ID is not valid, Please check your input ^____^>>>>>>>>>>>>>>>>>>>>>>>>\n");

	}


}


void how_tot_s(FIFO_Buffer_T* S_Buff)
{
	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer is Null\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("The Buffer is Empty\n");}

	DPRINTF("|======================================Info=====================================================|\n");
	DPRINTF("The Total_Number of Students is : %u \n",S_Buff->count);
	DPRINTF("You can add up to 55 Students \n");
	DPRINTF("you can add %d more Students \n",(S_Buff->length-S_Buff->count));
	DPRINTF("|===============================================================================================|\n");



}


void del_s(FIFO_Buffer_T* S_Buff)
{
	int roll;

	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer of Students is not found ------\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("the Buffer of Students is empty \n");}

	DPRINTF("|=================================Delete Student======Roll========================================|\n");
	DPRINTF("Enter The roll number :");
	scanf("%d",&roll);

	element_type* temp=S_Buff->tail;
	int i,j;
	for(i=0;i<S_Buff->count;i++)
	{
		if(((S_Buff->tail+i)->roll)==roll)
		{
			for(j=i;j>0;j-- )
			{
				*(temp+j)=*(temp+j-1);

			}

			S_Buff->tail++;
			S_Buff->count--;
			DPRINTF("<<<<<<<<<<<<<<<<<<<<<<<<The Roll Number is removed successfully>>>>>>>>>>>>>>>>>>>>>\n");
			return;
		}

	}

	DPRINTF("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<The roll number is not found>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}




void update_s(FIFO_Buffer_T* S_Buff)
{

	int roll=0,Updateidnex=0;
	char name[50];
	int data;

	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer of Students is not found ------\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("the Buffer of Students is empty \n");}

	DPRINTF("|=================================Update Student====Roll=========================================|\n");
	DPRINTF("Enter The roll number to update entry:");
	scanf("%d",&roll);
	DPRINTF("1:First_Name\n2:Last_Name:\n3:Roll_No:\n4:GPA\n5:Courses");
	scanf("%d",&Updateidnex);



	int i=0,j=0;
	for(i=0;i<S_Buff->count;i++)
	{
		if(((S_Buff->tail+i)->roll)==roll)
		{
			switch(Updateidnex)
			{

			case(1):
			DPRINTF("Enter the new first name:");
			gets(name);
			strcpy((S_Buff->tail+i)->Fname,name);
			DPRINTF("<<<<<<<<<<<<<<<<<<UPDATED_SECCESSFULLY.>>>>>>>>>>>>>>>>>>>\n");
			break;
			case(2):
			DPRINTF("Enter the new last name:");
			gets(name);
			strcpy((S_Buff->tail+i)->Lname,name);
			DPRINTF("<<<<<<<<<<<<<<<<<<<UPDATED_SECCESSFULLY.>>>>>>>>>>>>>>>>>>>\n");
			break;
			case(3):
			DPRINTF("Enter the new roll no:");
			scanf("%d",&(S_Buff->tail+i)->roll);
			DPRINTF("<<<<<<<<<<<<<<<<<<UPDATED_SECCESSFULLY.>>>>>>>>>>>>>>>>>>>>\n");
			break;
			case(4):
			DPRINTF("Enter the new GPA:");
			scanf("%f",&(S_Buff->tail+i)->GPA);
			DPRINTF("<<<<<<<<<<<<<<<<<UPDATED_SECCESSFULLY.>>>>>>>>>>>>>>>>>>>>>\n");
			break;

			case(5):
			DPRINTF("First,Take care that student enrolled these Courses:\n");

			for(j=0;j<(S_Buff->tail+i)->No_Courses;j++)
			{
				DPRINTF("%d ",(S_Buff->tail+i)->Courses_ID[j]);

			}
			DPRINTF("\nPlease Enter the index that you want to modify:\n");
			DPRINTF("Hint:Indices showed in ordered from 0 \n");
			scanf("%d",&data);
			DPRINTF("Now,Enter The Course ID that you want to enroll rather than second:\n");
			scanf("%d",&(S_Buff->tail+i)->Courses_ID[data]);
			DPRINTF("<<<<<<<<<<<<<<<<UPDATED_SECCESSFULLY.>>>>>>>>>>>>>>>>>>>>>>>\n");
			break;


			default:
				DPRINTF("<<<<<<<<<<<<<<<<<<<<<<<<<Please Enter right Index>>>>>>>>>>>>>>>>>>>>>>\n");

			}

		}
	}

}




void show_s(FIFO_Buffer_T* S_Buff)
{
	element_type* Temp=S_Buff->tail;
	int i,j;
	if(S_Buff->base==NULL || S_Buff->head==NULL || S_Buff->tail==NULL)
	{DPRINTF("The Buffer is Null\n");}

	if(	S_Buff->count == 0)
	{DPRINTF("The Buffer is Empty\n");}


	DPRINTF("|========================================Student_List========================================|\n");
	for(i=0;i<S_Buff->count;i++)
	{
		DPRINTF(">>>>>>>>>>>>>>>>>>>>>>>>>>>>.Info of Roll Number [%d]:\n",Temp->roll);
		DPRINTF("First name : %s \n",Temp->Fname);
		DPRINTF("Last  name : %s \n",Temp->Lname);
		DPRINTF("GPA        : %.2f \n",Temp->GPA);
		DPRINTF("Courses_ID:");

		for(j=0;j<Temp->No_Courses;j++)
		{
			DPRINTF(" %d ",Temp->Courses_ID[j]);
		}

		DPRINTF("\n|=======================================================================================|\n");
		Temp++;

	}
	DPRINTF("|=============================================================================================|\n");
}

