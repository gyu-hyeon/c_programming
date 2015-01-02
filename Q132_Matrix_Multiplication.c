/********************************************************************
*
* Problem 132 :
*                ��� ���� (Matrix Multiplication)
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

typedef struct matrix_size
{
	int *matA, *matB, *matC;
	int r, s, t;
} MS; // ��Ŀ��꿡 ���� ��� �������� ����ü

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

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ ���̽��� ����
	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d %d %d", &ms.r, &ms.s, &ms.t); // ��� �� ��ĵ

		ms.matA = (int*)malloc(sizeof(int)*ms.r*ms.s);
		ms.matB = (int*)malloc(sizeof(int)*ms.s*ms.t);
		ms.matC = (int*)malloc(sizeof(int)*ms.r*ms.t); // �� ��ĵ��� �����Ҵ�
		memset(ms.matC, 0, sizeof(int)*ms.r*ms.t); // ���C�� 0���� �ʱ�ȭ

		readMatrix(fp, ms);
		multipleMatrix(ms);
		printResult(ms);

		free(ms.matA);
		free(ms.matB);
		free(ms.matC); // �޸� �ݳ�
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* �� ����� �о�� */
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

/* �� ����� ���� */
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

/* ��� ��� */
void printResult(MS ms)
{
	int i;

	for (i = 0; i < ms.r*ms.t; i++)
	{
		printf("%d ", *(ms.matC + i));
		if (i % ms.t == (ms.t - 1)) printf("\n");
	}
}