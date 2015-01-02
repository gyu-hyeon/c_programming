/********************************************************************
*                                                                   *
* Problem 35 :                                                      *
*           ������ ������ ���԰���                                  *
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

int in_intervalCheck(int a, int b, int m); // �󱸰� a,b ���̿� m�� �ִ��� �˻��ϴ� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, a, b, m;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ �ݺ� Ƚ�� �о����

	for (i = 0; i < no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d %d %d", &a, &b, &m); // ����Ÿ �о����

		printf("%d\n", in_intervalCheck(a, b, m)); // �˻��ؼ� ���
	}

	fclose(fp);
}

int in_intervalCheck(int a, int b, int m) // [a,b] �ȿ� m�� ������ 1, ������ 0 ��ȯ
{
	if ((a <= m) && (m <= b))
		return 1;
	else
		return 0;
}