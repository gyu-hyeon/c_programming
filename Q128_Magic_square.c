/********************************************************************
*
* Problem 128 :
*              ���� ������ (Magic square)
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

#define SIZE 100 // �迭�� ũ��
#pragma warning(disable : 4996)

int check_MSquare(int arr[][SIZE], int n); // ���� ������ �Ǻ� �Լ�

int main(void)
{
	FILE *fp;
	int no_cases, no_data;
	int i, j, k;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		int M_matrix[SIZE][SIZE] = { 0 }; // ����� ���ҵ��� ������ 2���� �迭
		fscanf(fp, "%d", &no_data);

		/* �迭�� ���ҵ� ���� */
		for (j = 0; j < no_data; j++)
			for (k = 0; k < no_data; k++)
				fscanf(fp, "%d", &M_matrix[j][k]);

		printf("%d\n", check_MSquare(M_matrix, no_data)); // ���� ������ �Ǻ� �Լ� ȣ��
	}

	fclose(fp);
}

/* ���� ������ �Ǻ� �Լ� */
int check_MSquare(int arr[][SIZE], int n)
{
	int arr2[202] = { 0 };
	int i, j;

	/* arr2���� 0 ~ n-1�� �� �� ������ ��, 
	   n ~ 2n-1�� �� �� ������ ��, 
	   2n, 2n+1�� �밢������ �� �� */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j) arr2[2*n] += arr[i][j];
			if ((i + j) == (n - 1)) arr2[2*n+1] += arr[i][j];
			arr2[i] += arr[i][j];
			arr2[i + n] += arr[j][i];
		}
	}
	
	/* ��������� �ƴϸ� -1��, ������ �� ���� ���� ��ȯ*/
	for (i = 0; i < 2*n+2; i++)
	{
		if (arr2[i] != arr2[0])
			return -1;
	}

	return arr2[0];
}