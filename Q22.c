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

void print_hourglass(int n); // �𷹽ð� ��� �Լ�
int abs(int n); // ���� ��ȯ 

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

		print_hourglass(data); // ũ�Ⱑ data�� �𷹽ð� ���
	}

	fclose(fp);
}

void print_hourglass(int n)
{
	int i, j, k;
	int t;

	t = (n - 1) / 2;

	for (i = -t; i <= t; i++) // �� �� ��� ���� : - > * > +* > -
	{
		for (j = abs(i); j < t; j++)
		{
			printf("-");
		}

		printf("*");

		for (k = 0; k < abs(i); k++)
		{
			printf("+*");
		}

		for (j = abs(i); j < t; j++)
		{
			printf("-");
		}

		printf("\n"); // ����
	}
}

int abs(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}