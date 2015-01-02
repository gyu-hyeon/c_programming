/********************************************************************
*                                                                   *
* Problem 38 :                                                      *
*           수직/수평 성분과 점의 교차                              *
*                                                                   *
*********************************************************************/
/********************************************************************
*                                                                   *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년                    *
*                                               20143053  남규현    *
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

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3); // 데이타 읽어오기

		printf("%d\n", positionCheck(x1, y1, x2, y2, x3, y3));
	}

	fclose(fp);
}

int positionCheck(int x1, int y1, int x2, int y2, int x3, int y3) // 선분과 점의 관계 함수
{
	int temp = 0;
	temp = x1;
	x1 = (x1 <= x2) ? x1 : x2;
	x2 = (temp <= x2) ? x2 : temp; // x1 <= x2 로 맞추기 위해 작성

	temp = y1;
	y1 = (y1 <= y2) ? y1 : y2;
	y2 = (temp <= y2) ? y2 : temp; // y1 <= y2 로 맞추기 위해 작성

	if (vert_horiCheck(x1, y1, x2, y2) == 0) // 선분이 수평일 경우
	{
		if (y1 != y3) // y1 == y2이므로 y3가 y1이나 y2랑 같지 않다면 선분 밖에 있음
			return 0;
		else // y1 == y2 == y3 의 경우
		{
			if ((x1 <= x3) && (x3 <= x2)) // x3가 x1과 x2사이에 있을 경우
			{
				if ((x1 == x3) || (x2 == x3)) // x3가 x1혹은 x2와 같다면 선분 양 끝점중 하나에 있음
					return 2;
				else // 선분 양끝점에 있지 않으므로
					return 1;
			}
			else // x3가 x1,x2 사이에 없으므로 선분밖에 있음
				return 0;
		}
	}

	else // 선분이 수직일 경우
	{
		if (x1 != x3) // x1 == x2 이므로 x3가 x1이나 x2랑 같지 않다면 선분 밖에 있음
			return 0;
		else // x1 == x2 == x3 의 경우
		{
			if ((y1 <= y3) && (y3 <= y2)) // y3가 y1과 y2사이에 있을 경우
			{
				if ((y1 == y3) || (y2 == y3)) // y3가 y1혹은 y2와 같다면 선분 양 끝점중 하나에 있음
					return 2;
				else // 선분 양끝점에 있지 않으므로
					return 1;
			}
			else // y3가 y1,y2 사이에 없으므로 선분밖에 있음
				return 0;
		}
	}
}

int vert_horiCheck(int x1, int y1, int x2, int y2) // 수직은 1, 수평은 0을 반환
{
	if (y1 == y2)
		return 0;
	if (x1 == x2)
		return 1;
}