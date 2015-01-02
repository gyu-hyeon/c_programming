/********************************************************************
*
* Problem 74 :
*              달력 출력하기
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

int week_day(int y, int m); // 총일수 구하는 함수
int leap_year(int y); // 윤년 검사 함수
void print_calendar(int week, int y, int m); // 달력 출력 함수

void main(void)
{
	FILE *fp;
	int no_cases, year, month;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		int week = 0;
		fscanf(fp, "%d %d", &year, &month); // 날짜 읽어오기
		
		week = week_day(year, month);
		print_calendar(week, year, month); // 달력 출력
	}

	fclose(fp);
}

/* y년 m월 1일 의 총일수 반환 */
int week_day(int y, int m)
{
	int totalday = 0;
	int year1, year2;

	if (m <= 2)
	{
		y -= 1;
		m += 12;
	}

	year1 = y / 100;
	year2 = y % 100;

	totalday = ((21 * year1 / 4) + (5 * year2 / 4) + (26 * (m + 1) / 10)) % 7;

	return totalday;
}

/* 윤년이면 1, 아니면 0 반환 */
int leap_year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}

// 0:일요일, 1:월요일, 2:화요일, 3:수요일, 4:목요일, 5:금요일, 6:토요일
/* 달력 출력 */
void print_calendar(int week, int y, int m)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int last;
	int i, j = 0;

	if (leap_year(y) == 1)
		month[1] += 1;

	printf("%d %d\n", y, m);

	/*---------------------------  날짜 출력 --------------------------*/
	for (i = 1; i <= month[m - 1]; i++)
	{
		// 처음 0 파트 출력
		while (week)
		{
			printf("0 ");
			j++;
			week--;
		}

		// 날짜 출력
		printf("%d ", i); 

		// 행바꿈
		if ((i + j) % 7 == 0)
			printf("\n");
	}

	last = (i + j - 1) % 7;

	// ---------------------------------------------- 마지막 0 파트 출력
	if (last != 0)
	{
		while (7 - last)
		{
			printf("0 ");
			last++;
		}

		printf("\n");
	}
}