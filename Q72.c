/********************************************************************
*
* Problem 72 :
*              날짜수 계산하기
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

int total_day(int y, int m, int d);
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
		int innerday = 0;

		fscanf(fp, "%d %d %d", &year, &month, &day); // 첫번째 날짜 읽어오기
		innerday = total_day(year, month, day);

		fscanf(fp, "%d %d %d", &year, &month, &day); // 첫번째 날짜 읽어오기
		innerday -= total_day(year, month, day);
		
		printf("%d\n", -innerday + 1);
	}

	fclose(fp);
}

int total_day(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalday;
	int i;

	totalday = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	// (y - 1) 년 까지의 총일수

	if (leap_year(y) == 1)
		month[1] += 1;

	for (i = 0; i < (m-1); i++)
		totalday += month[i];
	// (m - 1) 월 까지의 총일수

	totalday += d;
	// d일 까지의 총일수

	return totalday;
}


int leap_year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}