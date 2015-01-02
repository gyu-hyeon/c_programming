/********************************************************************
*
* Problem 51 :
*              �Ҽ�
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

int check_primeNum(int n); // �Ҽ��� ���θ� �Ǵ��ϴ� �Լ�

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
		fscanf(fp, "%d", &num); //�Ҽ��� ���� ���� �о����

		printf("%d\n", check_primeNum(num)); // num �� �Ҽ����θ� ��� 
	}

	fclose(fp);
}

// �Ҽ��̸� 1, �ƴϸ� 0�� ��ȯ
int check_primeNum(int n)
{
	int i;
	int count = 0;

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			count += 1;
		else
			continue;
	}

	if (count == 2)
		return 1;
	else
		return 0;
}