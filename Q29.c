/********************************************************************
*                                                                   *
* Problem 29 :                                                      *
*           �� ������ �ִ밪                                        *
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

void big_return(int a, int b, int c); // �� ������ �ִ밪 ��� �Լ�

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

		big_return(num1, num2, num3); // �ִ밪 ���
	}

	fclose(fp);
}

void big_return(int a, int b, int c) // �� ������ �ִ밪�� ����ϴ� �Լ�
{
	if (a >= b)
	{
		if (a >= c) printf("%d\n", a);
		else printf("%d\n", c);
	}

	else
	{
		if (b >= c) printf("%d\n", b);
		else printf("%d\n", c);
	}
}