/********************************************************************
*                                                                   *
* Problem 31 :                                                      *
*           세 숫자의 정렬                                          *
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

void print_upper(int a, int b, int c); // 세 숫자 오름차순 정렬 출력 함수

void main(void)
{
	FILE *fp;
	int no_cases, num1, num2, num3;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d %d", &num1, &num2, &num3); // 데이타 읽어오기

		print_upper(num1, num2, num3); // 오름차순 정렬 출력
	}

	fclose(fp);
}

void print_upper(int a, int b, int c) // 오름차순 정렬 출력
{
	int sml, mid, big; // 순서대로 작은, 중간, 큰 수를 의미하는 변수

	if (a >= b)
	{
		if (b >= c)
		{
			big = a;
			mid = b;
			sml = c;
		}
		else if (a >= c)
		{
			big = a;
			mid = c;
			sml = b;
		}
		else
		{
			big = c;
			mid = a;
			sml = b;
		}
	}

	else
	{
		if (a >= c)
		{
			big = b;
			mid = a;
			sml = c;
		}
		else if (b >= c)
		{
			big = b;
			mid = c;
			sml = a;
		}
		else
		{
			big = c;
			mid = b;
			sml = a;
		}
	}

	printf("%d %d %d\n", sml, mid, big);
}