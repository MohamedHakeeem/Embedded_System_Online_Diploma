/*
 * main.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 */


#include "stdio.h"
#include "Student_DS.h"

#define DPRINTF(...) fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);


#define B_length  55
element_type StudentDataBase[B_length] ;




int main()
{
	FIFO_Buffer_T Student_Buff;
	FIFO_Buffer_Init(&Student_Buff,StudentDataBase,B_length);





	DPRINTF("||||||||||||||||||||||||||||||||||||Welcome to the Student Management System||||||||||||||||||||||||||||\n");
	int task;
	while(1)
	{
		DPRINTF("|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Choose The Task that you want to perform:\n");
		DPRINTF("1. Add The Student Details Manually\n");
		DPRINTF("2. Add The Student Details From Text File \n");
		DPRINTF("3.Find The Student Details by Roll Number \n");
		DPRINTF("4.Find The Student Details by First Name\n");
		DPRINTF("5.Find The Student Details by Course ID\n");
		DPRINTF("6.Find The Total Number of Students\n");
		DPRINTF("7.Delete The Student Details by Roll Number\n");
		DPRINTF("8.Update The Student Details by Roll Number\n");
		DPRINTF("9.Show All Information\n");
		DPRINTF("10.To Exit\n");
		DPRINTF("..............................Enter Your Choice to perform the task:");
		scanf("%d",&task);
		switch(task)
		{

		case 1:
			add_student_manually(&Student_Buff);
			break;

		case 2:
			add_sstduent_file(&Student_Buff);
			break;
		case 3:
			find_by_roll(&Student_Buff);
			break;

		case 4:
			find_by_firstname(&Student_Buff);
			break;


		case 5:
			find_by_courseid(&Student_Buff);
			break;

		case 6:
			how_tot_s(&Student_Buff);
			break;
		case 7:
			del_s(&Student_Buff);
			break;

		case 8:
			update_s(&Student_Buff);
			break;

		case 9:
			show_s(&Student_Buff);
			break;
		case 10:
			return 0;
			break;


		default:
			DPRINTF("<<<<<<<<<<<<<<<<<<<<<<<<Enter Right Index>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

		}

	}



	return 0;
}
