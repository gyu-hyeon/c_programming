/********************************************************************
*                                                                   *
* Problem 19 :                                                      *
*           삼각형 출력하기                                          *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* 국민대학교 전자정보통신대학 컴퓨터공학부 남규현                     *
*                                                     20143053      *
*                                                                   *
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void print_triangle(int n);

void main(void)
{
	FILE *fp;
	int no_cases, data;
	int i;

	fp = fopen("input.txt","r");
	if(fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for(i=0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &data); // 데이타 읽어오기

		print_triangle(data); // 크기가 data인 삼각형 출력
	}

	fclose(fp);
}

void print_triangle(int n)
{
	int i, j, k;

	if (n == 3) // 크기가 3인 삼각형 출력
	{
		printf("*\n");
		printf("**\n");
		printf("***\n");
	}

	else // 크기가 4이상인 삼각형 출력, 출력시 각 줄을 수열 a(n)으로 취급하여 주석첨부
	{
		printf("*\n");
		printf("**\n"); // a1, a2

		for (i=0; i<n-3; i++)
		{
			printf("*");
			for (j=0; j<=i; j++)
			{
				printf("+");
			}
			printf("*");
			printf("\n");
		} // a3 ~ a(n-1)

		for (k=0; k<n; k++)
		{
			printf("*");
		}
		printf("\n"); // a(n)
	}
}