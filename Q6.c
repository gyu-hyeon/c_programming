/*********************************************************************************************
*                                                                                            *
* Problem 6:                                                                                 *
*          두 정수 사이의 모든 정수의 합 구하기                                              *
*                                                                                            *
*********************************************************************************************/

/*********************************************************************************************
*                                                                                            *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년                                             *
*                                                                20143053 남규현             *
*                                                                                            *
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

int sum_numbers(int s, int t);

void main(void)
{
	FILE *fp;
	int i;
	int no_cases, start, end;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 반복횟수 읽어오기
	
	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d %d", &start, &end); // 두 정수값 읽어오기
		printf("%d\n", sum_numbers(start, end)); // sum_numbers 함수로 두 정수 사이의 모든 정수의 합 구하기
	}

	fclose(fp);
}

int sum_numbers(int s, int t)
{
	int i;
	int sum = 0;

	for (i = s; i <= t; i++)
	{
		sum += i; // s부터 t까지 더함
	}

	return sum; // sum값 반환
}