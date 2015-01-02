/********************************************************************
*
* Problem 85 :
*              �̵� ��� (k-moving average)
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

void moving_average(int arr[], int n, int k); // �̵� ��� ���� �� ��� �Լ�

int main(void)
{
	FILE *fp;
	int no_cases, no_data;
	int num[256] = { 0 }; // ������ ������ �迭
	int i, j; 
	int k; // �ֱ�

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d", &no_data);

		/* �������� ���� */
		for (j = 0; j < no_data; j++)
		{
			fscanf(fp, "%d", &num[j]);
		}

		fscanf(fp, "%d", &k);

		moving_average(num, no_data, k); // �̵���� �Լ� ȣ��
	}
	
	fclose(fp);
}

/* �̵� ��� ���� �� ���� ��� */
void moving_average(int arr[], int n, int k)
{
	int i, j;
	int average_arr[256] = { 0 };

	printf("%d ", n - k + 1);

	for (i = 0; i < n - k + 1; i++)
	{
		for (j = i; j < k + i; j++)
		{
			average_arr[i] += arr[j];
		}

		printf("%d ", average_arr[i] / k);
	}

	printf("\n");
}
