/********************************************************************
*                                                                   *
* Problem 21 :                                                      *
*           �簢�� ��ź�� ����ϱ�                                  *
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

void print_square(int n); // ���̾Ƹ�� ��� ��� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, data;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d", &data); // ����Ÿ �о����

		print_square(data); // ũ�Ⱑ data�� �簢�� ��ź�� ���
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
	} // ũ�Ⱑ 3�� ��츸 ����ó���� ��

	else
	{
		for (j = 0; j < n; j++)
		{
			printf("+");
		} // + ���
		printf("\n");

		for (i = 1; i <= (n - 2)*(n - 2); i++) 
		{
			if (i % (n - 2) == 1) printf("I");

			if (i % 2 == 1) printf("X");
			if (i % 2 == 0) printf("-");

			if (i % (n - 2) == 0) printf("I");

			if (i % (n - 2) == 0) printf("\n");
		} // ���� ���

		for (k = 0; k < n; k++)
		{
			printf("+");
		} // + ���
		printf("\n");
	}
}