/********************************************************************
*                                                                   *
* Problem 21 :                                                      *
*           사각형 양탄자 출력하기                                  *
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

void print_square(int n); // 다이아몬드 모양 출력 함수

void main(void)
{
	FILE *fp;
	int no_cases, data;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &data); // 데이타 읽어오기

		print_square(data); // 크기가 data인 사각형 양탄자 출력
	}

	fclose(fp);
}

void print_square(int n)
{
	int i, j, k;

	if (n == 3)
	{
		printf("+++\n");
		printf("IXI\n");
		printf("+++\n");
	} // 크기가 3인 경우만 예외처리로 함

	else
	{
		for (j = 0; j < n; j++)
		{
			printf("+");
		} // + 출력
		printf("\n");

		for (i = 1; i <= (n - 2)*(n - 2); i++) 
		{
			if (i % (n - 2) == 1) printf("I");

			if (i % 2 == 1) printf("X");
			if (i % 2 == 0) printf("-");

			if (i % (n - 2) == 0) printf("I");

			if (i % (n - 2) == 0) printf("\n");
		} // 내부 출력

		for (k = 0; k < n; k++)
		{
			printf("+");
		} // + 출력
		printf("\n");
	}
}