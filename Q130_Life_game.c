/********************************************************************
*
* Problem 130 :
*                ������ ���� (Life game)
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
int readCell(FILE *fp, char *arr, int column, int row);
void runLifeGame(char *arr, int column, int row, int t);
int aroundArr(char *arr, int pi, int pj, int column);
void printResultGame(char *arr, int column, int row);
int countAliveCell(char *arr, int column, int row);
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ ���̽��� ����
	for (i = 0; i < no_cases; i++)
	{
		char *cell; // ���� ��ġ�� ������ ������ ����
		int row, column, time; // ��, ��, �ð��� �ǹ��ϴ� ����

		fscanf(fp, "%d %d", &row, &column);
		cell = (char*)malloc(sizeof(char)*(row + 2)*(column + 2)); // (row + 2)*(column + 2) ũ��� �����Ҵ�

		time = readCell(fp, cell, column, row); // �ð��� ��ĵ�Ͽ� �����ϰ� cell�� ���� �ʱ���� �Է�
		runLifeGame(cell, column, row, time); // ������ ���� ����
		printResultGame(cell, column, row); // ������ ���� ��� ���

		free(cell); // �޸� �ݳ�
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* cell �� �о���� time �� �ݳ� */
int readCell(FILE *fp, char *arr, int column, int row)
{
	int i;
	int t; // �ð��� ������ ����

	fscanf(fp, "%d", &t);
	memset(arr, 'X', sizeof(char)*(row + 2)*(column + 2)); // cell�� ��� X�� �ʱ�ȭ

	/* ���� �ʱ� ���� ��ĵ */
	for (i = 1; i <= row; i++)
	{
		fscanf(fp, "%s", arr + 1 + i*(column + 2));
		*(arr + (i + 1)*(column + 2) - 1) = 'X';
	}

	return t;
}

/* ������ ���� ���� */
void runLifeGame(char *arr, int column, int row, int t)
{
	int i, j;
	int arrdNoO = 0; // i,j ��ġ���� �ֺ� 8ĭ�� O�� ������ ������ ����

	char *arr2 = (char*)malloc(sizeof(char)*(row + 2)*(column + 2));
	// �ӽ÷� ����� ������ �����ͺ��� �����Ҵ�

	/* t �ð����� ���������� ���� */
	while (t--)
	{
		memset(arr2, 'X', sizeof(char)*(row + 2)*(column + 2));

		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= column; j++)
			{
					arrdNoO = aroundArr(arr, i, j, column);

					if (arrdNoO <= 1) *(arr2 + i *(column + 2) + j) = 'X';
					if (arrdNoO == 2 && *(arr + i *(column + 2) + j) == 'O') *(arr2 + i *(column + 2) + j) = 'O';
					if (arrdNoO == 3) *(arr2 + i *(column + 2) + j) = 'O';
					if (arrdNoO >= 4) *(arr2 + i *(column + 2) + j) = 'X';
			}
		}

		memmove(arr, arr2, sizeof(char)*(row + 2)*(column + 2)); // �ӽ� ������� �ٽ� cell�� ����
	}

	free(arr2); // �޸� �ݳ�
}

/* �ֺ� 8ĭ O�� ������ ��ȯ */
int aroundArr(char *arr, int pi, int pj, int column)
{
	int i, j;
	int countNoO = 0;

	for (i = pi - 1; i <= pi + 1; i++)
	{
		for (j = pj - 1; j <= pj + 1; j++)
		{
			if ((i != pi || j != pj) && *(arr + i *(column + 2) + j) == 'O') countNoO++;
		}
	}

	return countNoO;
}

/* ������ ���� ��� ��� */
void printResultGame(char *arr, int column, int row)
{
	int i, j;
	printf("%d\n", countAliveCell(arr, column, row));

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= column ; j++)
		{
			printf("%c", *(arr + i *(column + 2) + j));
		}
		printf("\n");
	}
}

/* t�ð��� ����ִ� ���� ���� ��ȯ */
int countAliveCell(char *arr, int column, int row)
{
	int i, j;
	int countCell = 0; 

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= column; j++)
		{
			if (*(arr + i *(column + 2) + j) == 'O') countCell++;
		}
	}

	return countCell;
}