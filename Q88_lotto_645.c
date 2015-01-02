/********************************************************************
*
* Problem 88 :
*              �ζ� 6/45 (lotto 6/45)
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

#pragma warning(disable : 4996)

int lotto_check(int arr[]); // �ζ� �˻� �Լ�
int bonus_check(int arr[]); // ���ʽ� ���� �˻� �Լ�

int main(void)
{
	FILE *fp;
	int no_cases;
	int num[13] = { 0 }; // ��ȣ�� �о�� �迭
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		for (j = 0; j < 13; j++)
			fscanf(fp, "%d", &num[j]); // ��÷ ��ȣ�� ���� ��ȣ �о����

		printf("%d\n", lotto_check(num)); // �ζ� �˻� �Լ� ȣ��
	}

	fclose(fp);
}

int lotto_check(int arr[])
{
	int i, j;
	int check = 0; // ��÷��ȣ�� ���Թ�ȣ�� ��ġ�ϴ� ������ ���� (���ʽ� ����)

	/* ��ġ �˻� ���� */
	for (i = 0; i < 6; i++)
		for (j = 7; j < 13; j++)
			if (arr[i] == arr[j]) check++;

	/* ��� ��ȯ */
	switch (check)
	{
		case 3:
			return 5;
		case 4:
			return 4;
		case 5:
			if (bonus_check(arr) == 0) return 3;
			else return 2;
		case 6:
			return 1;
		default:
			return 0;
	}
}

/* ���� ��ȣ�� ���ʽ� ��ȣ�� ������ 1��, �ƴϸ� 0�� ��ȯ */
int bonus_check(int arr[])
{
	int i;

	for (i = 7; i < 13; i++)
		if (arr[6] == arr[i]) return 1;

	return 0;
}