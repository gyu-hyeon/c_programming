/********************************************************************
*
* Problem 61 :
*              �и�Ƽ ��Ʈ
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

unsigned int even_parity(unsigned int n); // ¦�� �и�Ƽ ��Ʈ�� ����Ͽ� n�� ���� ���Ӱ� ��ȯ�ϴ� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases;
	unsigned int num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%u", &num); // ���� �о����

		printf("%u\n", even_parity(num)); // num�� �и�Ƽ ��Ʈ�� ���Ͽ� ���� ���ο� ������ ���
	}

	fclose(fp);
}

unsigned int even_parity(unsigned int n) // ¦�� �и�Ƽ ����� ����� �Լ�
{
	int count = 0; // 1�� ������ ���� ����
	unsigned int num = n;
	int i;

	for (i = 0; i<31; i++)
	{
		if ((n & 1) == 1)
			count += 1;

		n = n >> 1;
	}

	if (count % 2 == 0)
		return num; // 1�� ������ ¦�� �̸� �״�� ��ȯ
	else
		return num | 0x80000000; // 1�� ������ Ȧ���̸� �� ������ ��Ʈ ��, 2^32��Ʈ �κп� 1���� �Ͽ� ��ȯ 
}