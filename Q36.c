/********************************************************************
*                                                                   *
* Problem 36 :                                                      *
*           �� ������ ��ħ                                          *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 1�г�                      *
*                                               20143053  ������    *
*                                                                   *
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int samePartCheck(int a, int b, int c, int d); // [a,b], [c,d] �� ������ ��ħ �˻� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, a, b, c, d;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ �ݺ� Ƚ�� �о����

	for (i = 0; i < no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d %d %d %d", &a, &b, &c, &d); // ����Ÿ �о����

		printf("%d\n", samePartCheck(a, b, c, d)); // �� ������ ��ħ�� �Լ��� �̿��Ͽ� ���
	}

	fclose(fp);
}

int samePartCheck(int a, int b, int c, int d) // [a,b], [c,d] �� ������ ��ġ�� �κ��� �ִٸ� 1, ���ٸ� 0�� ��ȯ
{
	if (((a <= c) && (c <= b)) || ((a <= d) && (d <= b)) || ((c <= a) && (a <= d)) || ((c <= b) && (b <= d)))
		return 1;
	else
		return 0;
}