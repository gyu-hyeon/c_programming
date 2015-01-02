/********************************************************************
*
* Problem 132 :
*                행렬 곱셈 (Matrix Multiplication)
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
#include <string.h>

#pragma warning (disable : 4996)

typedef struct matrix_size
{
	int *matA, *matB, *matC;
	int r, s, t;
} MS; // 행렬연산에 쓰일 멤버 변수들의 구조체

//////////////////////////////  Function List  ////////////////////////////////////
void readMatrix(FILE *fp, MS ms);
void multipleMatrix(MS ms);
void printResult(MS ms);
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	MS ms;
	int no_cases;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d %d %d", &ms.r, &ms.s, &ms.t); // 행과 열 스캔

		ms.matA = (int*)malloc(sizeof(int)*ms.r*ms.s);
		ms.matB = (int*)malloc(sizeof(int)*ms.s*ms.t);
		ms.matC = (int*)malloc(sizeof(int)*ms.r*ms.t); // 세 행렬들의 동적할당
		memset(ms.matC, 0, sizeof(int)*ms.r*ms.t); // 행렬C를 0으로 초기화

		readMatrix(fp, ms);
		multipleMatrix(ms);
		printResult(ms);

		free(ms.matA);
		free(ms.matB);
		free(ms.matC); // 메모리 반납
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* 두 행렬을 읽어옴 */
void readMatrix(FILE *fp, MS ms)
{
	int i;

	for (i = 0; i < ms.r*ms.s; i++)
	{
		fscanf(fp, "%d", ms.matA + i);
	}
	for (i = 0; i < ms.s*ms.t; i++)
	{
		fscanf(fp, "%d", ms.matB + i);
	}
}

/* 두 행렬을 곱함 */
void multipleMatrix(MS ms)
{
	int i, j, k;

	for (i = 0; i < ms.r; i++)
	{
		for (j = 0; j < ms.t; j++)
		{
			for (k = 0; k < ms.s; k++)
			{
				*(ms.matC + i*ms.t + j) += (*(ms.matA + i*ms.s + k))*(*(ms.matB + k*ms.t + j));
			}
		}
	}
}

/* 결과 출력 */
void printResult(MS ms)
{
	int i;

	for (i = 0; i < ms.r*ms.t; i++)
	{
		printf("%d ", *(ms.matC + i));
		if (i % ms.t == (ms.t - 1)) printf("\n");
	}
}