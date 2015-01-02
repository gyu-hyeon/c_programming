/********************************************************************
*                                                                   *
* Problem 22 :                                                      *
*           모레시계 출력하기                                       *
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

void print_NumSquare(int m, int n); // 모레시계 출력 함수

void main(void)
{
	FILE *fp;
	int no_cases, data_m, data_n;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d", &data_m, &data_n); // 데이타 읽어오기

		print_NumSquare(data_m, data_n); // 숫자 사각형 출력
	}

	fclose(fp);
}

void print_NumSquare(int m, int n)
{
	int i, j;

	for (i = 1; i <= n; i++) // 세로 반복
	{
		for (j = 0; j < m; j++) // 가로 반복
		{
			printf("%d ", i + j * n);
		}

		printf("\n"); // 엔터
	}
}