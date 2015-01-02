/********************************************************************
*                                                                   *
* Problem 31 :                                                      *
*           �� ������ ����                                          *
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

void print_upper(int a, int b, int c); // �� ���� �������� ���� ��� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, num1, num2, num3;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i < no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d %d %d", &num1, &num2, &num3); // ����Ÿ �о����

		print_upper(num1, num2, num3); // �������� ���� ���
	}

	fclose(fp);
}

void print_upper(int a, int b, int c) // �������� ���� ���
{
	int sml, mid, big; // ������� ����, �߰�, ū ���� �ǹ��ϴ� ����

	if (a >= b)
	{
		if (b >= c)
		{
			big = a;
			mid = b;
			sml = c;
		}
		else if (a >= c)
		{
			big = a;
			mid = c;
			sml = b;
		}
		else
		{
			big = c;
			mid = a;
			sml = b;
		}
	}

	else
	{
		if (a >= c)
		{
			big = b;
			mid = a;
			sml = c;
		}
		else if (b >= c)
		{
			big = b;
			mid = c;
			sml = a;
		}
		else
		{
			big = c;
			mid = b;
			sml = a;
		}
	}

	printf("%d %d %d\n", sml, mid, big);
}