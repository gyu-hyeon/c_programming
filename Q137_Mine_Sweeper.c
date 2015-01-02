/********************************************************************
*
* Problem 137 :
*                ���� ã�� (Mine Sweeper)
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

typedef struct
{
	int row; // ��
	int column; // ��
	char *input_map; // �Է� ��
	char *result_map; // ��� ��
	char *output_map; // (����ڿ� ����) ��� ��
} MS; // ����ã�⿡ �ʿ��� �������� ���Խ�Ų ����ü ����

///////////////////////////// Function List ///////////////////////////////////
MS *readCell(FILE *fp, MS *ms); 
MS *operateResult(MS *ms); 
MS *isNearMine(MS *ms, int pi, int pj);
MS *runMindSweeper(MS *ms);
MS *floodFill(MS *ms, int pi, int pj);
void printResult(MS *ms); 
void freeMap(MS *ms); 
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////// Main () ///////////////////////////////////////
int main(void)
{
	FILE *fp;
	MS user_ms = { 0, 0, NULL, NULL, NULL }, *ms = &user_ms; // ����ü ����, ����ü ������ ���� ����
	int no_cases;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		ms = readCell(fp, ms);
		ms = runMindSweeper(ms);
		printResult(ms);
		freeMap(ms);
	}

	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////

// �Է� �ʿ� ������ �о����, �� �� �ʱ�ȭ �� �����Ҵ�
MS *readCell(FILE *fp, MS *ms)
{
	int i;

	fscanf(fp, "%d %d", &ms->column, &ms->row);

	// input_map ���� �Ҵ� �� �ʱ�ȭ
	ms->input_map = (char*)malloc(sizeof(char)*(ms->row + 2)*(ms->column + 2));
	memset(ms->input_map, '+', sizeof(char)*(ms->row + 2)*(ms->column + 2));

	// result_map ���� �Ҵ� �� �ʱ�ȭ
	ms->result_map = (char*)malloc(sizeof(char)*(ms->row + 2)*(ms->column + 2));
	memset(ms->result_map, '0', sizeof(char)*(ms->row + 2)*(ms->column + 2));

	// output_map �����Ҵ� �� �ʱ�ȭ
	ms->output_map = (char*)malloc(sizeof(char)*(ms->row + 2)*(ms->column + 2));
	memset(ms->output_map, '+', sizeof(char)*(ms->row + 2)*(ms->column + 2));

	// input_map �о����
	for (i = 1; i <= ms->row; i++)
	{
		fscanf(fp, "%s", ms->input_map + 1 + i*(ms->column + 2));
		*(ms->input_map + (i + 1)*(ms->column + 2) - 1) = '+';
	}

	return ms;
}

// ��� �ʿ� �Է� �ʿ� ���� ��� ����
MS *operateResult(MS *ms)
{
	int i, j;

	for (i = 1; i <= ms->row; i++)
	{
		for (j = 1; j <= ms->column; j++)
		{
			if (*(ms->input_map + i * (ms->column + 2) + j) == '*')
			{
				ms = isNearMine(ms, i, j);
			}
		}
	}

	return ms;
}

// �Է¸� ������ġ���� �� ��ġ�� ����� �ֺ��� ���� 1����
MS *isNearMine(MS *ms, int pi, int pj)
{
	int i, j;

	for (i = pi - 1; i <= pi + 1; i++)
	{
		for (j = pj - 1; j <= pj + 1; j++)
		{
			if ((i == pi && j == pj) || (*(ms->input_map + i * (ms->column + 2) + j) == '*'))
				continue;
			else
				*(ms->result_map + i * (ms->column + 2) + j) += 1;
		}
	}

	return ms;
}

// ����ã�� ����
MS *runMindSweeper(MS *ms)
{
	int i, j;

	ms = operateResult(ms);

	for (i = 1; i <= ms->row; i++)
	{
		for (j = 1; j <= ms->column; j++)
		{
			if (*(ms->input_map + i * (ms->column + 2) + j) == '?')
			{
				ms = floodFill(ms, i, j);
			}
		}
	}

	return ms;
}

// �Է¸��� ����� Ŭ�� ��ġ�� ��������, ��� �ʿ� ��� ���� ���ڵ��� ����
MS *floodFill(MS *ms, int pi, int pj)
{
	// ������ ����� ����
	if (pi < 1 || pi > ms->row || pj < 1 || pj > ms->column)
		return ms;
	
	// ��� �ʿ� ���� �ִٸ� �װ��� ��� �ʿ� ���� �� ����
	if (*(ms->result_map + pi * (ms->column + 2) + pj) >= '1')
	{
		*(ms->output_map + pi * (ms->column + 2) + pj) = *(ms->result_map + pi * (ms->column + 2) + pj);
		return ms;
	}

	// ��� �ʿ� ���� ���� �ִٸ� ����
	if (*(ms->output_map + pi * (ms->column + 2) + pj) >= '0')
	{
		return ms;
	}

	// �ƴϸ� 0�� �Է��ϰ� 8���� ����Լ� ȣ��
	else
	{
		*(ms->output_map + pi * (ms->column + 2) + pj) = '0';

		ms = floodFill(ms, pi, pj - 1);
		ms = floodFill(ms, pi, pj + 1);
		ms = floodFill(ms, pi - 1, pj);
		ms = floodFill(ms, pi + 1, pj);

		ms = floodFill(ms, pi - 1, pj - 1);
		ms = floodFill(ms, pi - 1, pj + 1);
		ms = floodFill(ms, pi + 1, pj - 1);
		ms = floodFill(ms, pi + 1, pj + 1);
	}
}

// ��� �� ���
void printResult(MS *ms)
{
	int i, j;

	for (i = 1; i <= ms->row; i++)
	{
		for (j = 1; j <= ms->column; j++)
		{
			printf("%c", *(ms->output_map + i * (ms->column + 2) +j));
		}
		printf("\n");
	}
}

// �޸� �ݳ�
void freeMap(MS *ms)
{
	free(ms->input_map);
	free(ms->result_map);
	free(ms->output_map);
}