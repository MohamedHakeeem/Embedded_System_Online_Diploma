/*
 * main.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Mohamed_Hakeem
 */
#include"Student_DS.h"
extern Dummy Dummy_Node;


int main()
{
	int option=0;

	printf("======================================================================\n");
	printf("Please choose one of the following options,write the index of it only \n");
	printf("1:Add_Node\n");
	printf("2:Delete_Node\n");
	printf("3:Print_Nodes\n");
	printf("4:Delete_AllNodes\n");
	printf("5:Get_Node\n");
	printf("6:GetI_Length\n");
	printf("7:GetR_Length\n");
	printf("8:Get_ReverseNode\n");
	printf("9:Get_RevNode2P\n");
	printf("10:Get_Middle\n");
	printf("11:Reverse_Nodes\n");
	printf("========================^______________^===============================\n");fflush(stdout);
	while(1)
	{
		printf("=======================Choose Option=======================\n");fflush(stdout);
		scanf("%d",&option);fflush(stdin);
		switch(option)
		{

		case 1:
			Add_Node();
			break;

		case 2:
			Delete_Node();
			break;

		case 3:
			Print_Nodes();
			break;

		case 4:
			Delete_AllNodes();
			break;

		case 5:
			Get_Node();
			break;

		case 6:
			GetI_Length();
			break;

		case 7:
			printf("Length is %d\n",GetR_Length(Dummy_Node.P_Next));
			break;

		case 8:
			Get_ReverseNode();
			break;

		case 9:
			Get_RevNode2P();
			break;

		case 10:
			Get_Middle();
			break;

		case 11:
			Reverse_Nodes();
			break;

		default:
			printf("the option is not right,remember you should enter the index only\n");

		}
		printf("\n");
	}



	return 0;
}
