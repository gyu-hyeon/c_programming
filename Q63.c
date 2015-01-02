/********************************************************************
*
* Problem 63 :
*              �عְŸ� (Hamming Distance)
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
typedef unsigned int myint; // myint�� ���� 2^32 - 1 ����

void hamming_weight(myint n); // n�� �ع� ���Ը� ����ϴ� �Լ�
void hamming_distance(myint n1, myint n2); // n1, n2������ �ع� �Ÿ��� ����ϴ� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases;
	myint num1, num2;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%u %u", &num1, &num2); // ���� �о����

		hamming_weight(num1);
		hamming_weight(num2); // num1, num2�� �عֹ��� ���
		hamming_distance(num1, num2); // num1,num2 ���� �عְŸ� ���
	}

	fclose(fp);
}

void hamming_weight(myint n) // n�� �عֹ��� ���
{
	int i;
	int weight = 0;

	for (i = 0; i < 31; i++)
	{
		if ((n & 1) == 1)
			weight += 1;
		n = n >> 1;
	}

	printf("%d ", weight);
}

void hamming_distance(myint n1, myint n2) // n1, n2���� �عְŸ� ���
{
	int i;
	int distance = 0;

	for (i = 1; i <= 31; i++)
	{
		if (((n1 & 1) ^ (n2 & 1)) == 1)
			distance += 1;

		n1 = n1 >> 1;
		n2 = n2 >> 1;
	}

	printf("%d\n", distance);
}
