/********************************************************************
*
* Problem 70 :
*              1월 1일의 요일 계산하기
*
*********************************************************************/
/********************************************************************
*
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년
*                                                20143053 남규현
*
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int day_of_week(int y); // 요일 반환 함수

void main(void)
{
	FILE *fp;
	int no_cases, year;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &year); // 숫자 읽어오기

		printf("%d\n", day_of_week(year));
	}

	fclose(fp);
}

int day_of_week(int y)
{
	int totalday;
	int weekday;

	totalday = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + 1;
	// y년 1월 1일 까지의 총일수

	weekday = totalday % 7;
	// 0:일요일, 1:월요일, 2:화요일, 3:수요일, 4:목요일, 5:금요일, 6:토요일

	return weekday;
}