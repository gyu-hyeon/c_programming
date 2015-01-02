/********************************************************************
*                                                                   *
* Problem 34 :                                                      *
*           윤년 계산하기                                           *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년                      *
*                                               20143053  남규현    *
*                                                                   *
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int isLeapYear(int year); // 윤년 검사 함수

void main(void)
{
	FILE *fp;
	int no_cases, data;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &data); // 데이터 읽어오기

		printf("%d\n", isLeapYear(data)); // 윤년 검사 함수를 이용해 1 또는 0 출력
	}

	fclose(fp);
}

int isLeapYear(int year) // 1이면 윤년, 0이면 평년
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;
}