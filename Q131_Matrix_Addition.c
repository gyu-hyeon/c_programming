/********************************************************************
*
* Problem 131 :
*                ��� ���� (Matrix Addtion)
*
*********************************************************************/
/********************************************************************
*
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 1�г�
*                                                20143053 ������
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
	int row, column, size; // �� �� ��, �׸��� ����� ũ��
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ ���̽��� ����
	for (i = 0; i < no_cases; i++)
	{
		int *matrixA = NULL, *matrixB = NULL; // �� ����� ������ ����
		fscanf(fp, "%d %d", &row, &column); // ��� �� ��ĵ

		size = row *column; 
		matrixA = (int*)malloc(sizeof(int)*size);
		matrixB = (int*)malloc(sizeof(int)*size);
		// �� ��� �����Ҵ�

		readMatrix(fp, matrixA, matrixB, size);
		addMatrix(matrixA, matrixB, size);
		printResultAddMatrix(matrixA, size, column);

		free(matrixA);
		free(matrixB);
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* �� ����� �о�� */
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

/* �� ����� ���ؼ� A�� ���� */
void addMatrix(int *matA, int *matB, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		*(matA + i) += *(matB + i);
	}
}

/* ��� ��������� ��� */
void printResultAddMatrix(int *mat, int size, int column)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", *(mat + i));
		if (i % column == (column - 1)) printf("\n");
	}
}