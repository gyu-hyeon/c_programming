/********************************************************************
*                                                                   *
* Problem 22 :                                                      *
*           �𷹽ð� ����ϱ�                                       *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 1�г�                    *
*                                               20143053  ������    *
*                                                                   *
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void print_NumSquare(int m, int n); // �𷹽ð� ��� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, data_m, data_n;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i < no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d %d", &data_m, &data_n); // ����Ÿ �о����

		print_NumSquare(data_m, data_n); // ���� �簢�� ���
	}

	fclose(fp);
}

void print_NumSquare(int m, int n)
{
	int i, j;

	for (i = 1; i <= n; i++) // ���� �ݺ�
	{
		for (j = 0; j < m; j++) // ���� �ݺ�
		{
			printf("%d ", i + j * n);
		}

		printf("\n"); // ����
	}
}