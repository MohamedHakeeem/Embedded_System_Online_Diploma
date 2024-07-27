/*
 * main.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Mohamed_Hakeem
 */


#include<stdio.h>
#include<string.h>

typedef struct Semployee
{
	char* emp_name;
	char emp_id;

}Emp;



int main(void)
{
	/* ******************* Homework_Six ****************************** */
	/******************Q1**********************/
	/*int x;
	x=29;
	int *p= &x;
	printf("address of x= %X , value of x=%d \n",&x,x);
	printf("address of p= %X , content of p=%d \n",p,*p);
	x=34;
	printf("address of p= %X , content of p=%d \n",p,*p);
	*p=7;
	printf("address of x= %X , value of x=%d \n",&x,x);*/

	/******************Q2**********************/
	/*char alphabet[26];
	char *Pabc=alphabet;
	int i=0;
	for(i=0;i<26;i++)
	{
		*(Pabc++)='A'+i;

	}

	for(i=0;i<26;i++)
	{
		printf("%c, ",*(alphabet+i));

	}*/

	/******************Q3**********************/
	/*char str[30];
	char temp;
	int i,j;
	char *ptr;
	printf("please enter your name: ");fflush(stdout);
	gets(str);fflush(stdin);
	ptr=str;
	j=strlen(str)-1;

	for(i=0;i<strlen(str);i++,j--)
	{
		if(i<j)
		{
			temp=*(ptr+j);
			*(ptr+j)=*(ptr+i);
			*(ptr+i)=temp;
		}
	}


	printf("%s",str);
*/

	/******************Q4**********************/
	/*int arr[15];
	int *p_element=arr;
	int i;
	printf("Enter the elements of the array\n");fflush(stdout);
	for(i=0;i<5;i++)
	{
		printf("the element %d: ",i+1);fflush(stdout);
		scanf("%d",p_element++);fflush(stdin);
	}

	p_element--;

	printf("\nthe elements of the array are\n");fflush(stdout);
	for(i=5;i>0;i--)
	{
			printf("the element %d is %d\n",i,*p_element--);fflush(stdout);

	}*/

	/****************** Q5 [Very Important] *********************/
	/*Emp emp1={"Mohamed",123} ,emp2={"Hakeem",345}, emp3={"Ahmed",100};
	Emp (*arr[])={&emp1,&emp2, &emp3};
	Emp(*(*ptr)[])=&arr;

	printf("|========================================|\n");
	printf("|Employee name: %s\n",(**(*ptr)).emp_name);
	printf("|Employee id: %d\n",(*(*ptr))->emp_id);
	printf("|========================================|\n");
	printf("|Employee name: %s\n",(**(*ptr+1)).emp_name);
	printf("|Employee id: %d\n",(*(*ptr+1))->emp_id);
	printf("|========================================|\n");
	printf("|Employee name: %s\n",(**(*ptr+2)).emp_name);
	printf("|Employee id: %d\n",(*(*ptr+2))->emp_id);
	printf("|========================================|\n");
    */

	return 0;

}

