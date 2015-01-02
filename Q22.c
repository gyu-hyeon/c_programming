/********************************************************************
*                                                                   *
* Problem 22 :                                                      *
*           모레시계 출력하기                                       *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년                    *
*                                               20143053  남규현    *
*                                                                   *
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void print_hourglass(int n); // 모레시계 출력 함수
int abs(int n); // 절댓값 반환 

void main(void)
{
	FILE *fp;
	int no_cases, data;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &data); // 데이타 읽어오기

		print_hourglass(data); // 크기가 data인 모레시계 출력
	}

	fclose(fp);
}

void print_hourglass(int n)
{
	int i, j, k;
	int t;

	t = (n - 1) / 2;

	for (i = -t; i <= t; i++) // 각 줄 출력 순서 : - > * > +* > -
	{
		for (j = abs(i); j < t; j++)
		{
			printf("-");
		}

		printf("*");

		for (k = 0; k < abs(i); k++)
		{
			printf("+*");
		}

		for (j = abs(i); j < t; j++)
		{
			printf("-");
		}

		printf("\n"); // 엔터
	}
}

int abs(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}