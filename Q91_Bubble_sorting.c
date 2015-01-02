/********************************************************************
*
* Problem 91 :
*              ���� ���� (Bubble sorting)
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

void bubble_sorting(int arr[], int n); // ���� ���� ���� �Լ�
void print_sort(int arr[], int n); // ���� ��� ��� �Լ�

int main(void)
{
	FILE *fp;
	int no_cases, no_data;
	int num[SIZE] = { 0 }; // ���ڵ� ������ �迭
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d", &no_data);

		for (j = 0; j < no_data; j++)
			fscanf(fp, "%d", &num[j]); // �迭�� ������ ���ڵ� ����

		bubble_sorting(num, no_data); // ���� ���� �Լ� ȣ��
		print_sort(num, no_data); // ���İ�� ��� �Լ� ȣ��
	}

	fclose(fp);
}

/* ���� ���� ���� */
void bubble_sorting(int arr[], int n)
{
	int i, j, temp;

	for (i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

/* ��� ��� */
void print_sort(int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}