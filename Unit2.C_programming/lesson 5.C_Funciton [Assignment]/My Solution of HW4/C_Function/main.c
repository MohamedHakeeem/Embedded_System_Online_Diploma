/*
 * main.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Mohamed_Hakeem
 */


#include<stdio.h>
#include<string.h>

void Prime_Interval(int start,int stop);
unsigned int Fact(int num);
void Reverse();
int Power(int base , int exp);


int main(void)
{
	/* ******************* Homework_Four ****************************** */
	/******Ex1: Prime Function *******/
	/*int Start,Stop;
	printf("Enter the two numbers [intervals]:");
	fflush(stdout);
	scanf("%d %d",&Start,&Stop);
	fflush(stdin);
	printf("Prime number between %d and %d is:",Start,Stop);
	Prime_Interval(Start,Stop);
	*/

	/******Ex2: Factorial by Recursion *******/
	/*unsigned int n,F;
	printf("Enter A positive number:");
	fflush(stdout);
	scanf("%d",&n);
	fflush(stdin);
	F=Fact(n);
	printf("Factorial Number of %u is %u \n",n,F);*/

	/******Ex3: Reverse Sentences by Recursion ******/
	/*printf("Enter the Sentences: ");
	fflush(stdout);
	Reverse();*/

	/******Ex4: Power of Number by Recursion ******/
	int base,exp,result;
	printf("Enter the Base Number and Power Number[positive] respectively:");
	fflush(stdout);
	scanf("%d %d",&base,&exp);
	fflush(stdin);
	result=Power(base,exp);
	printf(" %d^%d = %d",base,exp,result);




    return 0;

}

void Prime_Interval(int start,int stop)
{
	int i,j;
	int flag=0;

	for(i=start+1;i<stop;i++)
	{
		for(j=2;j<=(i/2);j++)
		{
			if(i%j==0)
			{
				flag=1;
			}

		}

		if(flag==0)
		{
			printf("%d ",i);
		}

		flag=0;
	}

}


unsigned int Fact(int num)
{

	if(num<0)
	{
		printf("the factorial number is not allowed for negative numbers.");
	}
	if(num<=1)
	{
		return 1;
	}

	return num*Fact(num-1);

}

void Reverse()
{
	char c;
	scanf("%c",&c);
	if(c != '\n')
	{
		Reverse();
		printf("%c",c);
	}

}

int Power(int base , int exp)
{


	if(exp==0)
	{
		return 1;
	}

	return (base*Power(base,exp-1));
}


