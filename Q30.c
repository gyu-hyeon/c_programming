/********************************************************************
*                                                                   *
* Problem 30 :                                                      *
*           �� ������ �߰���                                        *
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

int print_middle(int a, int b, int c); // �� ������ �߰��� ��ȯ �Լ�

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

		printf("%d\n", print_middle(num1, num2, num3)); // �߰��� ���
	}

	fclose(fp);
}

int print_middle(int a, int b, int c) // �� ������ �߰����� ��ȯ�ϴ� �Լ�
{
	if (a >= b)
	{
		if (b >= c) return b;
		else if (a >= c) return c;
		else return a;
	}

	else
	{
		if (a >= c) return a;
		else if (b >= c) return c;
		else return b;
	}
}