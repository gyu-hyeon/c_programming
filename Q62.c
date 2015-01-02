/********************************************************************
*
* Problem 62 :
*              ����Ʈ ��ũ���� (Byte Scramble)
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
#include <math.h>

#pragma warning (disable : 4996)
typedef unsigned long myint; // myint�� ���� 2^32 - 1 ����

int main(void)
{
	FILE *fp;
	myint n;
	// n : �̵���ų ����

	int no_cases = 0;
	int i, j, k;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		myint mask = 0xFF; // 00000000 11111111
		myint afternum = 0; // n�� ��ȯ�� ����
		myint num[5] = { 0 };
		int change[5] = { 0 };
		// num[] : ����Ʈ ������ ������ ������ ������ ����
		// change[] : �̵��� ����Ʈ ��ġ

		fscanf(fp, "%lu %d %d %d %d", &n, &change[4], &change[3], &change[2], &change[1]); // ���� �о����

		/* n�� ����Ʈ ������ ������ num[]�� ���� */
		for (j = 1; j <= 4; j++)
		{
			num[j] = n & mask;
			mask *= pow(2, 8);
		}

		/* ��ȯ ���� */
		for (k = 1; k <= 4; k++)
		{
			if (change[k] > k)
			{
				num[change[k]] /= pow(2, 8 * (change[k] - k));
			}
			else if (change[k] < k)
			{
				num[change[k]] *= pow(2, 8 * (k - change[k]));
			}

			afternum |= num[change[k]];
		}

		printf("%lu\n", afternum);
	}
	fclose(fp);

	return 0;
}