/********************************************************************
*
* Problem 81 :
*              �ֻ��� ���� ���� (2)
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

#pragma warning (disable : 4996)

int main(void)
{
	FILE *fp;
	int no_cases, num;
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);

	for (i = 0; i < no_cases; i++)
	{
		int num1, num2;
		int count[13] = { 0 }; // ������ �� ���ڵ��� ������ ������ �迭

		fscanf(fp, "%d", &num);
		// �ֻ��� 2���� ������ Ƚ��

		for (j = 0; j < num; j++)
		{
			fscanf(fp, "%d %d", &num1, &num2);
			count[num1 + num2] += 1;
		}

		for (j = 2; j < 13; j++)
			printf("%d ", count[j]);
		// ���� ���
		printf("\n");
	}
	fclose(fp);
}