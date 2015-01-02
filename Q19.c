/********************************************************************
*                                                                   *
* Problem 19 :                                                      *
*           �ﰢ�� ����ϱ�                                          *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� ������                     *
*                                                     20143053      *
*                                                                   *
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void print_triangle(int n);

void main(void)
{
	FILE *fp;
	int no_cases, data;
	int i;

	fp = fopen("input.txt","r");
	if(fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for(i=0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d", &data); // ����Ÿ �о����

		print_triangle(data); // ũ�Ⱑ data�� �ﰢ�� ���
	}

	fclose(fp);
}

void print_triangle(int n)
{
	int i, j, k;

	if (n == 3) // ũ�Ⱑ 3�� �ﰢ�� ���
	{
		printf("*\n");
		printf("**\n");
		printf("***\n");
	}

	else // ũ�Ⱑ 4�̻��� �ﰢ�� ���, ��½� �� ���� ���� a(n)���� ����Ͽ� �ּ�÷��
	{
		printf("*\n");
		printf("**\n"); // a1, a2

		for (i=0; i<n-3; i++)
		{
			printf("*");
			for (j=0; j<=i; j++)
			{
				printf("+");
			}
			printf("*");
			printf("\n");
		} // a3 ~ a(n-1)

		for (k=0; k<n; k++)
		{
			printf("*");
		}
		printf("\n"); // a(n)
	}
}