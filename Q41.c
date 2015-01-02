/********************************************************************
*                                                                   *
* Problem 41 :                                                      *
*           ����/���� ������ ����                                   *
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

#define MAX(a,b) (((a) > (b)) ? (a) : (b)) // a,b �� ū �� ��ȯ
#define MIN(a,b) (((a) < (b)) ? (a) : (b)) // a,b �� ���� �� ��ȯ

#pragma warning (disable : 4996)

int vert_horiCheck(int x1, int y1, int x2, int y2); // ������ ���� ���� �˻�
int crossCheck(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4); // �� ������ ���� �� ��ȯ

void main(void)
{
	FILE *fp;
	int no_cases;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ �ݺ� Ƚ�� �о����

	for (i = 0; i < no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2); // ���� 1�� ��ǥ
		fscanf(fp, "%d %d %d %d", &x3, &y3, &x4, &y4); // ���� 2�� ��ǥ �о����

		printf("%d\n", crossCheck(x1, y1, x2, y2, x3, y3, x4, y4)); // 2���� ���� ���� �Ǻ� �Լ��̿�
	}

	fclose(fp);
}

int vert_horiCheck(int x1, int y1, int x2, int y2) // ������ 1, ������ 0�� ��ȯ
{
	if (y1 == y2)
		return 0;
	if (x1 == x2)
		return 1;
}

// ���� �����ϴ� ��� 1
// ���� �����ִ� ��� 2
// �ƴ� ��� 0 �� ��ȯ�Ѵ�.

int crossCheck(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (vert_horiCheck(x1, y1, x2, y2) == 0) // ����1�� ������ ���
	{
		int temp = x1;
		x1 = MIN(x1, x2);
		x2 = MAX(temp, x2); // x1 < x2
		temp = y3;
		y3 = MIN(y3, y4);
		y4 = MAX(temp, y4); // y3 < y4 �� ����� ����

		if ((x1 <= x3) && (x3 <= x2)) // ���������� x��ǥ�� ���򼱺� �ȿ� ���� ��
		{
			if ((y3 <= y1) && (y1 <= y4)) // ���򼱺��� y��ǥ�� �������� �ȿ� ���� ��
			{
				if ((y1 == y3) || (y1 == y4))
					return 2;
				else if ((x3 == x1) || (x3 == x2))
					return 2;
				// �� ������ ���ϴ� ����̴�

				else
					return 1;
				// �� ������ ���������ϴ� ����̴�
			}
			else
				return 0;
			// �� ������ ������ �ʴ� ����̴�
		}

		else
			return 0;
		// ���������� x��ǥ�� ���򼱺� �ۿ� ���� ���̹Ƿ� �� ������ ������ �ʴ´�
	}

	else // ����1�� ������ ���
	{
		int temp = x3;
		x3 = MIN(x3, x4);
		x4 = MAX(temp, x4); // x3 < x4
		temp = y1;
		y1 = MIN(y1, y2);
		y2 = MAX(temp , y2); // y1 < y2 �� ����� ����

		if ((x3 <= x1) && (x1 <= x4)) // ���������� x��ǥ�� ���򼱺� �ȿ� ���� ��
		{
			if ((y1 <= y3) && (y3 <= y2)) // ���򼱺��� y��ǥ�� �������� �ȿ� ���� ��
			{
				if ((y3 == y1) || (y3 == y2))
					return 2;
				else if ((x1 == x3) || (x1 == x4))
					return 2;
				// �� ������ ���ϴ� ����̴�

				else
					return 1;
				// �� ������ ���������ϴ� ����̴�
			}
			else
				return 0;
			// �� ������ ������ �ʴ� ����̴�
		}

		else
			return 0;
		// ���������� x��ǥ�� ���򼱺� �ۿ� ���� ���̹Ƿ� �� ������ ������ �ʴ´�
	}
}