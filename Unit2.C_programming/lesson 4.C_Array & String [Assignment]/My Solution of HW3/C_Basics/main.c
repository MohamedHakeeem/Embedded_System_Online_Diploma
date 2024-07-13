/*
 * main.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Mohamed_Hakeem
 */


#include<stdio.h>
#include<string.h>

int main(void)
{
	/* ******************* Homework_three ****************************** */
	/******Ex1: Sum of Two Matrix *******/
	/*float A[2][2];
	float B[2][2];
	float S[2][2];
	int i , j , k;
	i=j=k=0;

	printf("please enter the data of 1st Matrix \n");
	fflush(stdout);

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf(" a%d%d: \n",i+1,j+1);
			fflush(stdout);
			scanf("%f",&A[i][j]);
			fflush(stdin);
		}
	}

	printf("please enter the data of 2nd Matrix \n");
	fflush(stdout);

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf(" b%d%d: \n",i+1,j+1);
			fflush(stdout);
			scanf("%f",&B[i][j]);
			fflush(stdin);
		}
	}

	for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				S[i][j]=(A[i][j]+B[i][j]);
			}
		}

	printf("\r\nSum Of Matrices\r\n");
	for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%.1f \t",	S[i][j]);
			}
			printf("\r\n");
		}*/

	/******Ex2: Average using Array*******/
	/*float arr[100];
	float sum=0.0;
	int i,n;
	i=n=0;


	printf("Please enter the number of data: \r\n");
	fflush(stdout);
	scanf("%d",&n);	fflush(stdin);

	for(i=0;i<n;i++)
	{
		printf("enter the number %d: \r\n",i+1);
		fflush(stdout);
		scanf("%f",&arr[i]);	fflush(stdin);
		sum+=arr[i];
	}

	printf("Average = %.2f",(sum/n));*/


	/******Ex3:Transpose Matrix *******/
/*
	float M[5][5];
	float M_T[5][5];

	int h,g,r,c;
	h=g=r=c=0;

	printf("Please enter the number of rows & columns respectively : \r\n");
	fflush(stdout);
	scanf("%d %d",&r ,&c);	fflush(stdin);
	printf("Enter the element of  Matrix :\r\n");
	fflush(stdout);

	for(h=0;h<r;h++)
		{
			for(g=0;g<c;g++)
			{
				printf(" M%d%d: \n",h+1,g+1);
				fflush(stdout);
				scanf("%f",&M[h][g]);
				fflush(stdin);
			}
		}

	printf("Original Matrix: \r\n");
	for(h=0;h<r;h++)
		{
			for(g=0;g<c;g++)
			{
				printf("%.1f \t",M[h][g]);
			}
			printf("\r\n");
		}


	for(h=0;h<r;h++)
	{
		for(g=0;g<c;g++)
		{
			M_T[g][h]=M[h][g];
		}
	}

	printf("Transposed Matrix: \r\n");
	for(h=0;h<c;h++)
	{
		for(g=0;g<r;g++)
		{
			printf("%.1f \t",M_T[h][g]);
		}
		printf("\r\n");
	}
*/

	/******Ex4:Insert Element in Array *******/
	/*int ar[100];
	int i,n1=0,el_In=0,Loc=0;


	printf("Please enter the number of element : \r\n");
	fflush(stdout);
	scanf("%d",&n1);	fflush(stdin);
	printf("Please enter elements : \r\n");
	fflush(stdout);

	for(i=0;i<n1;i++)
	{
		scanf("%d",&ar[i]);	fflush(stdin);

	}

	for(i=0;i<n1;i++)
	{
		printf("%d ",ar[i]);
	}

	printf("\r\n");
	printf("Please enter the element to be inserted: \r\n");
	fflush(stdout);
	scanf("%d",&el_In);	fflush(stdin);
	printf("Please enter the required location: \r\n");
	fflush(stdout);
	scanf("%d",&Loc);	fflush(stdin);

	for(i=n1-1;i>=0;i--)
	{
		ar[i+1]=ar[i];
		if((Loc-1)==i)
		{
			ar[i]=el_In;
			break;
		}

	}

	for(i=0;i<n1+1;i++)
	{
		printf("%d ",ar[i]);
	}

	printf("\r\n");

*/
	/******Ex5:Search an element in Array *******/
/*
	int ar1[100];
	int i,n2=0,el_S=0 ,loc=0;


	printf("Please enter the number of element : \r\n");
	fflush(stdout);
	scanf("%d",&n2);	fflush(stdin);
	printf("Please enter elements : \r\n");
	fflush(stdout);

	for(i=0;i<n2;i++)
	{
		scanf("%d",&ar1[i]);	fflush(stdin);

	}

	for(i=0;i<n2;i++)
	{
		printf("%d ",ar1[i]);
	}

	printf("\r\n");
	printf("Please enter the element to be searched: \r\n");
	fflush(stdout);
	scanf("%d",&el_S);	fflush(stdin);

	for(i=0;i<n2;i++)
	{
		if(el_S==ar1[i])
		{
			loc=i+1;
		}

	}

	printf("Number found at  the Location = %d \r\n",loc);


*/

	/******Ex6:Frequency of character in string *******/
	/*char string[100];
	char a;
	int i=0,count=0;
	printf("Enter String: \r\n");
	fflush(stdout);
	gets(string);	fflush(stdin);


	printf("Enter a character  to find frequency: \r\n");
	fflush(stdout);
	scanf("%c",&a); fflush(stdin);

	while(string[i]!=0)
	{
		if(string[i]==a)
		{
			count++;
		}

		i++;
	}

	printf("Frequency of %c: %d \r\n",a,count);

*/

	/******Ex7:length of string *******/
	/*char str[50];
	int i=0,cou=0;
	printf("Enter String: \r\n");
	fflush(stdout);
	gets(str);	fflush(stdin);

	while(str[i]!=0)
	{
		cou++;
		i++;

	}

	printf("length of \"%s\": %d \r\n",str,cou);

*/

	/******Ex8:Reverse String *******/
	/*char str[50];
	char temp;
	int i=0,len=0;
	printf("Enter String: \r\n");
	fflush(stdout);
	gets(str);	fflush(stdin);
	len=strlen(str);

	for(i=0;i<len ;i++)
	{
		--len;
		temp=str[i];
		str[i]=str[len];
		str[len]=temp;

	}

	printf("Reverse String is %s \r\n",str);
*/



    return 0;

}
