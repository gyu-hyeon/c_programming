/********************************************************************
*
* Problem 71 :
*              요일 계산하기
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

int day_of_week(int y, int m, int d); // 요일 반환 함수
int leap_year(int y); // 윤년 검사 함수

void main(void)
{
	FILE *fp;
	int no_cases, year, month, day;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d %d", &year, &month, &day); // 숫자 읽어오기

		printf("%d\n", day_of_week(year, month, day));
	}

	fclose(fp);
}

int day_of_week(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalday;
	int weekday;
	int i;

	totalday = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	// (y - 1) 년 까지의 총일수

	if (leap_year(y) == 1)
		month[1] += 1;

	for (i = 0; i < (m - 1); i++)
		totalday += month[i];
	// (m - 1) 월 까지의 총일수

	totalday += d; // d일 까지의 총일수

	weekday = totalday % 7;
	// 0:일요일, 1:월요일, 2:화요일, 3:수요일, 4:목요일, 5:금요일, 6:토요일

	return weekday;
}

int leap_year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}