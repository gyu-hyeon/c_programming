/********************************************************************
*                                                                   *
* Problem 38 :                                                      *
*           ����/���� ���а� ���� ����                              *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 1�г�                    *
*                                               20143053  ������    *
*                                                                   *
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int positionCheck(int x1, int y1, int x2, int y2, int x3, int y3);
int vert_horiCheck(int x1, int y1, int x2, int y2);

void main(void)
{
	FILE *fp;
	int no_cases;
	int x1, x2, x3, y1, y2, y3;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ �ݺ� Ƚ�� �о����

	for (i = 0; i < no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3); // ����Ÿ �о����

		printf("%d\n", positionCheck(x1, y1, x2, y2, x3, y3));
	}

	fclose(fp);
}

int positionCheck(int x1, int y1, int x2, int y2, int x3, int y3) // ���а� ���� ���� �Լ�
{
	int temp = 0;
	temp = x1;
	x1 = (x1 <= x2) ? x1 : x2;
	x2 = (temp <= x2) ? x2 : temp; // x1 <= x2 �� ���߱� ���� �ۼ�

	temp = y1;
	y1 = (y1 <= y2) ? y1 : y2;
	y2 = (temp <= y2) ? y2 : temp; // y1 <= y2 �� ���߱� ���� �ۼ�

	if (vert_horiCheck(x1, y1, x2, y2) == 0) // ������ ������ ���
	{
		if (y1 != y3) // y1 == y2�̹Ƿ� y3�� y1�̳� y2�� ���� �ʴٸ� ���� �ۿ� ����
			return 0;
		else // y1 == y2 == y3 �� ���
		{
			if ((x1 <= x3) && (x3 <= x2)) // x3�� x1�� x2���̿� ���� ���
			{
				if ((x1 == x3) || (x2 == x3)) // x3�� x1Ȥ�� x2�� ���ٸ� ���� �� ������ �ϳ��� ����
					return 2;
				else // ���� �糡���� ���� �����Ƿ�
					return 1;
			}
			else // x3�� x1,x2 ���̿� �����Ƿ� ���йۿ� ����
				return 0;
		}
	}

	else // ������ ������ ���
	{
		if (x1 != x3) // x1 == x2 �̹Ƿ� x3�� x1�̳� x2�� ���� �ʴٸ� ���� �ۿ� ����
			return 0;
		else // x1 == x2 == x3 �� ���
		{
			if ((y1 <= y3) && (y3 <= y2)) // y3�� y1�� y2���̿� ���� ���
			{
				if ((y1 == y3) || (y2 == y3)) // y3�� y1Ȥ�� y2�� ���ٸ� ���� �� ������ �ϳ��� ����
					return 2;
				else // ���� �糡���� ���� �����Ƿ�
					return 1;
			}
			else // y3�� y1,y2 ���̿� �����Ƿ� ���йۿ� ����
				return 0;
		}
	}
}

int vert_horiCheck(int x1, int y1, int x2, int y2) // ������ 1, ������ 0�� ��ȯ
{
	if (y1 == y2)
		return 0;
	if (x1 == x2)
		return 1;
}