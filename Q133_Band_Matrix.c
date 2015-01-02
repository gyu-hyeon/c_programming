/********************************************************************
*
* Problem 133 :
*                ��� ��� (Band Matrix)
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
	int *matA;
	int size;
	int s, t;
} MS; // ��Ŀ��꿡 ���� ��� �������� ����ü

//////////////////////////////  Function List  ////////////////////////////////////
void readMatrix(FILE *fp, MS ms);
int calcBand(MS ms);
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
		int sum = 0;
		fscanf(fp, "%d", &ms.size); // ����� ũ�� ��ĵ

		ms.matA = (int*)malloc(sizeof(int)*ms.size*ms.size); // ��� �����Ҵ�
		readMatrix(fp, ms);

		fscanf(fp, "%d %d", &ms.s, &ms.t);
		sum = calcBand(ms);
		printf("%d\n", sum);
		
		free(ms.matA); // �޸� �ݳ�
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* ����� �о�� */
void readMatrix(FILE *fp, MS ms)
{
	int i;

	for (i = 0; i < ms.size*ms.size; i++)
	{
		fscanf(fp, "%d", ms.matA + i);
	}
}

/* ��� ��� */
int calcBand(MS ms)
{
	int i, j, k;
	int sum = 0;

	for (k = ms.s; k <= ms.t; k++)
	{
		for (i = 0; i < ms.size; i++)
		{
			for (j = 0; j < ms.size; j++)
			{
				if ((j - i) == k) sum += *(ms.matA + i*ms.size + j);
			}
		}
	}

	return sum;
}
