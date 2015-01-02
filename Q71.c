/********************************************************************
*
* Problem 71 :
*              ���� ����ϱ�
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

int day_of_week(int y, int m, int d); // ���� ��ȯ �Լ�
int leap_year(int y); // ���� �˻� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, year, month, day;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d %d %d", &year, &month, &day); // ���� �о����

		printf("%d\n", day_of_week(year, month, day));
	}

	fclose(fp);
}

int day_of_week(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalday;
	int weekday;
	int i;

	totalday = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	// (y - 1) �� ������ ���ϼ�

	if (leap_year(y) == 1)
		month[1] += 1;

	for (i = 0; i < (m - 1); i++)
		totalday += month[i];
	// (m - 1) �� ������ ���ϼ�

	totalday += d; // d�� ������ ���ϼ�

	weekday = totalday % 7;
	// 0:�Ͽ���, 1:������, 2:ȭ����, 3:������, 4:�����, 5:�ݿ���, 6:�����

	return weekday;
}

int leap_year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}