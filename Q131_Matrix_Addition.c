/********************************************************************
*
* Problem 131 :
*                행렬 덧셈 (Matrix Addtion)
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

//////////////////////////////  Function List  ////////////////////////////////////
void readMatrix(FILE *fp, int *matA, int *matB, int size);
void addMatrix(int *matA, int *matB, int size);
void printResultAddMatrix(int *mat, int size, int column);
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases;
	int row, column, size; // 행 과 열, 그리고 행렬의 크기
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		int *matrixA = NULL, *matrixB = NULL; // 두 행렬의 포인터 변수
		fscanf(fp, "%d %d", &row, &column); // 행과 열 스캔

		size = row *column; 
		matrixA = (int*)malloc(sizeof(int)*size);
		matrixB = (int*)malloc(sizeof(int)*size);
		// 두 행렬 동적할당

		readMatrix(fp, matrixA, matrixB, size);
		addMatrix(matrixA, matrixB, size);
		printResultAddMatrix(matrixA, size, column);

		free(matrixA);
		free(matrixB);
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* 두 행렬을 읽어옴 */
void readMatrix(FILE *fp, int *matA, int *matB, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		fscanf(fp, "%d", matA + i);
	}
	for (i = 0; i < size; i++)
	{
		fscanf(fp, "%d", matB + i);
	}
}

/* 두 행렬을 더해서 A에 저장 */
void addMatrix(int *matA, int *matB, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		*(matA + i) += *(matB + i);
	}
}

/* 행렬 덧셈결과를 출력 */
void printResultAddMatrix(int *mat, int size, int column)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", *(mat + i));
		if (i % column == (column - 1)) printf("\n");
	}
}