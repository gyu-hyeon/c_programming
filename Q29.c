/********************************************************************
*                                                                   *
* Problem 29 :                                                      *
*           세 숫자의 최대값                                        *
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

void big_return(int a, int b, int c); // 세 숫자의 최대값 출력 함수

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

		big_return(num1, num2, num3); // 최대값 출력
	}

	fclose(fp);
}

void big_return(int a, int b, int c) // 세 숫자중 최대값을 출력하는 함수
{
	if (a >= b)
	{
		if (a >= c) printf("%d\n", a);
		else printf("%d\n", c);
	}

	else
	{
		if (b >= c) printf("%d\n", b);
		else printf("%d\n", c);
	}
}