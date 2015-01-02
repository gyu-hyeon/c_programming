/********************************************************************
*
* Problem 74 :
*              �޷� ����ϱ�
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

int week_day(int y, int m); // ���ϼ� ���ϴ� �Լ�
int leap_year(int y); // ���� �˻� �Լ�
void print_calendar(int week, int y, int m); // �޷� ��� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, year, month;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ Ƚ�� �о����

	for (i = 0; i<no_cases; i++) // �׽�Ʈ �ݺ�
	{
		int week = 0;
		fscanf(fp, "%d %d", &year, &month); // ��¥ �о����
		
		week = week_day(year, month);
		print_calendar(week, year, month); // �޷� ���
	}

	fclose(fp);
}

/* y�� m�� 1�� �� ���ϼ� ��ȯ */
int week_day(int y, int m)
{
	int totalday = 0;
	int year1, year2;

	if (m <= 2)
	{
		y -= 1;
		m += 12;
	}

	year1 = y / 100;
	year2 = y % 100;

	totalday = ((21 * year1 / 4) + (5 * year2 / 4) + (26 * (m + 1) / 10)) % 7;

	return totalday;
}

/* �����̸� 1, �ƴϸ� 0 ��ȯ */
int leap_year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}

// 0:�Ͽ���, 1:������, 2:ȭ����, 3:������, 4:�����, 5:�ݿ���, 6:�����
/* �޷� ��� */
void print_calendar(int week, int y, int m)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int last;
	int i, j = 0;

	if (leap_year(y) == 1)
		month[1] += 1;

	printf("%d %d\n", y, m);

	/*---------------------------  ��¥ ��� --------------------------*/
	for (i = 1; i <= month[m - 1]; i++)
	{
		// ó�� 0 ��Ʈ ���
		while (week)
		{
			printf("0 ");
			j++;
			week--;
		}

		// ��¥ ���
		printf("%d ", i); 

		// ��ٲ�
		if ((i + j) % 7 == 0)
			printf("\n");
	}

	last = (i + j - 1) % 7;

	// ---------------------------------------------- ������ 0 ��Ʈ ���
	if (last != 0)
	{
		while (7 - last)
		{
			printf("0 ");
			last++;
		}

		printf("\n");
	}
}