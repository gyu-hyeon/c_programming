/********************************************************************
*                                                                   *
* Problem 30 :                                                      *
*           세 숫자의 중간값                                        *
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

int print_middle(int a, int b, int c); // 세 숫자의 중간값 반환 함수

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

		printf("%d\n", print_middle(num1, num2, num3)); // 중간값 출력
	}

	fclose(fp);
}

int print_middle(int a, int b, int c) // 세 숫자중 중간값을 반환하는 함수
{
	if (a >= b)
	{
		if (b >= c) return b;
		else if (a >= c) return c;
		else return a;
	}

	else
	{
		if (a >= c) return a;
		else if (b >= c) return c;
		else return b;
	}
}