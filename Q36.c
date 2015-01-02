/********************************************************************
*                                                                   *
* Problem 36 :                                                      *
*           두 구간의 겹침                                          *
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

int samePartCheck(int a, int b, int c, int d); // [a,b], [c,d] 두 구간의 겹침 검사 함수

void main(void)
{
	FILE *fp;
	int no_cases, a, b, c, d;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d %d %d", &a, &b, &c, &d); // 데이타 읽어오기

		printf("%d\n", samePartCheck(a, b, c, d)); // 두 구간의 겹침을 함수를 이용하여 출력
	}

	fclose(fp);
}

int samePartCheck(int a, int b, int c, int d) // [a,b], [c,d] 두 구간의 겹치는 부분이 있다면 1, 없다면 0을 반환
{
	if (((a <= c) && (c <= b)) || ((a <= d) && (d <= b)) || ((c <= a) && (a <= d)) || ((c <= b) && (b <= d)))
		return 1;
	else
		return 0;
}