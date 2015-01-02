/********************************************************************
*
* Problem 129 :
*              8 Queen ����
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

#define CHESS_SIZE 9 // ü������ ũ��
#define SIZE 17 // �迭�� ũ��
#pragma warning(disable : 4996)

int queen_check(int arr[]);

int main(void)
{
	FILE *fp;
	int no_cases;
	int i, j, k;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		char queen[SIZE] = { 0 }; // ���� ��ǥ���� �о�� �迭
		int check[48] = { 0 }; // �˻����ǵ鿡 ���� �迭
		int chess[CHESS_SIZE][CHESS_SIZE] = { 0 }; // �� ���� ������ 2���� �迭

		/* ��ǥ ��ĵ */
		for (j = 0; j < 8; j++)
			fscanf(fp, "%s", queen + 2 * j);

		/* ü���ǿ� ���� ��ǥ�� ���� 1���� (ex : a�� 8�� -> 1�� 8��)*/
		for (j = 0; j < SIZE; j += 2)
			chess[queen[j] - 96][queen[j + 1] - 48]++;

		/* check �� ��� */
		for (j = 1; j < CHESS_SIZE; j++)
		{
			for (k = 1; k < CHESS_SIZE; k++)
			{
				check[j + k] += chess[j][k]; // check[2 ~ 16], ���߿� 8���� 1�̾�� �Ѵ�.
				check[24 + j - k] += chess[j][k]; // check[17 ~ 31], ���߿� 8���� 1��� �Ѵ�.
				check[31 + j] += chess[j][k]; // check[32 ~ 39], ���߿� ��� 1�̿��� �Ѵ�.
				check[39 + j] += chess[k][j]; // check[40 ~ 47], ���߿� ��� 1�̿��� �Ѵ�.
			}
		}

		printf("%d\n", queen_check(check));
	}

	fclose(fp);
}

/* ���� ������ �����ϸ� 1��, �ƴϸ� 0�� ��ȯ */
int queen_check(int arr[])
{
	int i;
	int count_a = 0, count_b = 0;

	for (i = 2; i < 48; i++)
	{
		if (i >= 2 && i <= 16 && arr[i] == 1) count_a++;
		if (i >= 17 && i <= 31 && arr[i] == 1) count_b++;
		if (i >= 32 && i <= 39 && arr[i] == 0) return 0; // �ึ�� ���� 1���� �־�� �Ѵ�
		if (i >= 40 && i <= 47 && arr[i] == 0) return 0; // ������ ���� 1���� �־�� �Ѵ�
	}

	if (count_a != 8 || count_b != 8) return 0; // �밢�� �յ�(15��)�� ���� 8���� �־�� �Ѵ�

	return 1; // ������ ��� ������Ű�� �ʴ´ٸ�(8 Queen ������ �����Ұ��) 1�� ��ȯ
}