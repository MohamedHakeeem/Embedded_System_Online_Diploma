/*
 * main.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Mohamed_Hakeem
 */


#include<stdio.h>
#include<string.h>

#define PI  3.14
#define Circle_Area(R) (PI*R*R)

typedef struct SStudenst
{
	char name[50];
	int roll;
	float marks;

}Student;


typedef struct SDistances
{
	float feets;
	float inches;

}Distance;


typedef struct SComplex
{
	float Real_N;
	float Imag_N;

}Complex_Num;

Complex_Num Add_CN(Complex_Num A, Complex_Num B);


union Ujob
{
	char name [32];
	float salary;
	int worker_no;
}u;
struct Sjob1
{
	char name [32];
	float salary;
	int worker_no;
}s;

int main(void)
{
	/* ******************* Homework_Five ****************************** */
	/******************Ex1**********************/
	/*Student S1;
	printf("Please Enter information of students\n");	fflush(stdout);
	printf("Please Enter Name:");fflush(stdout);
	gets(S1.name);fflush(stdin);
	printf("Please Enter Roll:");fflush(stdout);
	scanf("%d",&S1.roll);fflush(stdin);
	printf("Please Enter Marks:");fflush(stdout);
	scanf("%f",&S1.marks);fflush(stdin);
	printf("\nDisplaying Information\n");
	printf("Name:%s \nRoll:%d \nMarks:%.2f",S1.name,S1.roll,S1.marks);*/

	/******************Ex2**********************/
	/*Distance D1 ,D2,Sum;
	float Sfeets;
	float Sinches;
	printf("Please Enter 1st distance: \n");	fflush(stdout);
	printf("Please Enter feet:");fflush(stdout);
	scanf("%f",&D1.feets);fflush(stdin);
	printf("Please Enter inch:");fflush(stdout);
	scanf("%f",&D1.inches);fflush(stdin);

	printf("\nPlease Enter 2nd distance: \n");	fflush(stdout);
	printf("Please Enter feet:");fflush(stdout);
	scanf("%f",&D2.feets);fflush(stdin);
	printf("Please Enter inch:");fflush(stdout);
	scanf("%f",&D2.inches);fflush(stdin);

	Sum.inches=D1.inches+D2.inches;
	Sum.feets=D1.feets+D2.feets;
	Sfeets=Sum.feets+(Sum.inches/12);
	Sinches=(Sfeets- (int)Sfeets)*12;

	printf("Sum of distances : %d\' %.2f\" ",(int)Sfeets,Sinches);*/


	/******************Ex3**********************/
	/*Complex_Num C1,C2,Total;
	printf("please enter the 1st complex number:\n");
	printf("enter the real and imaginary respectively:");fflush(stdout);
	scanf("%f %f",&C1.Real_N,&C1.Imag_N);fflush(stdin);

	printf("\nplease enter the 2nd complex number:\n");
	printf("enter the real and imaginary respectively:");fflush(stdout);
	scanf("%f %f",&C2.Real_N,&C2.Imag_N);fflush(stdin);

	Total=Add_CN(C1,C2);
	printf("the Sum = %.2f + %.2fi",Total.Real_N,Total.Imag_N);*/


	/******************Ex4**********************/
	/*Student S[10];
	int i;
	printf("Please Enter information of students\n\n");	fflush(stdout);
	for(i=0;i<10;i++)
	{
		printf("For Roll %d:\n",i+1);
		S[i].roll=(i+1);
		printf("Please Enter Name:");fflush(stdout);
		gets(S[i].name);fflush(stdin);
		printf("Please Enter Marks:");fflush(stdout);
		scanf("%f",&S[i].marks);fflush(stdin);
		printf("\n");
	}

	printf("\nDisplaying Information of students\n");
	for(i=0;i<10;i++)
	{
		printf("Information of Roll %d: \n",S[i].roll);
		printf("Name:%s \nMarks:%.2f \n\n",S[i].name,S[i].marks);
	}*/


	/******************Ex5**********************/
	/*float area,radius;
	printf("Please enter the radius:");fflush(stdout);
	scanf("%f",&radius);fflush(stdin);
	area=Circle_Area(radius);
	printf("the area of the circle = %.2f",area);*/


	/******************Ex6**********************/
	/*printf("size of union = %d", sizeof(u));
	printf("\nsize of structure = %d", sizeof(s));*/


	return 0;

}

Complex_Num Add_CN(Complex_Num A, Complex_Num B)
{
	Complex_Num R;
	R.Real_N=A.Real_N+B.Real_N;
	R.Imag_N=A.Imag_N+B.Imag_N;

	return R;

}

