/********************************************************************
*
* Problem 50 :
*              ����� �� ���ϱ�
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

int sum_divisor(int n); // ������� ���� ���ϴ� �Լ�
int count_divisor(int n); // ������� ������ ���ϴ� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d", &num); // ������� ���� ���� �о����

		printf("%d %d\n", count_divisor(num), sum_divisor(num)); // num �� ������� �հ� ���� ��� 
	}

	fclose(fp);
}

int count_divisor(int n) // n�� ����� ���� ��ȯ
{
	int i;
	int count = 1;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			count += 2;
	}

	return count;
}

int sum_divisor(int n) // n�� ������� �� ��ȯ
{
	int i;
	int sum = 1;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
			sum += n / i;
		}
	}

	return sum;
}