/********************************************************************
*
* Problem 70 :
*              1�� 1���� ���� ����ϱ�
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

int day_of_week(int y); // ���� ��ȯ �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, year;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d", &year); // ���� �о����

		printf("%d\n", day_of_week(year));
	}

	fclose(fp);
}

int day_of_week(int y)
{
	int totalday;
	int weekday;

	totalday = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + 1;
	// y�� 1�� 1�� ������ ���ϼ�

	weekday = totalday % 7;
	// 0:�Ͽ���, 1:������, 2:ȭ����, 3:������, 4:�����, 5:�ݿ���, 6:�����

	return weekday;
}