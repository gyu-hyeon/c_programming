/********************************************************************
*
* Problem 90 :
*              1���� ������ ���� (1-dimension life game)
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
#include <string.h>

#define SIZE 53 // �迭�� ũ��
#pragma warning(disable : 4996)

void run_game(int arr[], int arr2[], int n, int k); // 1���� ������ ���� ���� �Լ�
void print_result(int arr[], int n); // ���� ���� �� ��� ��� �Լ�

int main(void)
{
	FILE *fp;
	int no_cases;
	int n, k; // �������� ũ�� : n, �����ð� : k
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		int cell[SIZE] = { 0 }; // ���׸��Ƽ��� ������ �迭
		int after_cell[SIZE] = { 0 }; // ���� ������ ����� ������ �迭

		fscanf(fp, "%d %d", &n, &k);

		for (j = 1; j <= n; j++)
			fscanf(fp, "%d", &cell[j]);

		run_game(cell, after_cell, n, k); // ���� ���� �Լ� ȣ��
		print_result(after_cell, n); // ��� ��� �Լ� ȣ��
	}

	fclose(fp);
}

/* 1���� ������ ���� ���� */
void run_game(int arr[], int arr2[], int n, int k)
{
	int i;

	while (k--)
	{
		for (i = 1; i <= n; i++)
		{
			int neighbor = arr[i - 1] + arr[i + 1];

			if (neighbor < 3 || neighbor > 7)
			{
				if (arr[i] == 0) arr2[i] = arr[i];
				else arr2[i] = arr[i] - 1;
			}
			else if (neighbor >= 4 && neighbor <= 7)
			{
				if (arr[i] == 9) arr2[i] = arr[i];
				else arr2[i] = arr[i] + 1;
			}
			else if (neighbor == 3) arr2[i] = arr[i];
		}

		memmove(arr, arr2, sizeof(int)*SIZE); 
	}
}

/* ���� ���� �� ��� ��� */
void print_result(int arr[], int n)
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}