/********************************************************************
*                                                                   *
* Problem 41 :                                                      *
*           수직/수평 선분의 교차                                   *
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

#define MAX(a,b) (((a) > (b)) ? (a) : (b)) // a,b 중 큰 값 반환
#define MIN(a,b) (((a) < (b)) ? (a) : (b)) // a,b 중 작은 값 반환

#pragma warning (disable : 4996)

int vert_horiCheck(int x1, int y1, int x2, int y2); // 선분의 수직 수평 검사
int crossCheck(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4); // 두 선분의 관계 값 반환

void main(void)
{
	FILE *fp;
	int no_cases;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2); // 선분 1의 좌표
		fscanf(fp, "%d %d %d %d", &x3, &y3, &x4, &y4); // 선분 2의 좌표 읽어오기

		printf("%d\n", crossCheck(x1, y1, x2, y2, x3, y3, x4, y4)); // 2개의 선분 교차 판별 함수이용
	}

	fclose(fp);
}

int vert_horiCheck(int x1, int y1, int x2, int y2) // 수직은 1, 수평은 0을 반환
{
	if (y1 == y2)
		return 0;
	if (x1 == x2)
		return 1;
}

// 완전 교차하는 경우 1
// 서로 접해있는 경우 2
// 아닌 경우 0 을 반환한다.

int crossCheck(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (vert_horiCheck(x1, y1, x2, y2) == 0) // 선분1이 수평일 경우
	{
		int temp = x1;
		x1 = MIN(x1, x2);
		x2 = MAX(temp, x2); // x1 < x2
		temp = y3;
		y3 = MIN(y3, y4);
		y4 = MAX(temp, y4); // y3 < y4 를 만드는 과정

		if ((x1 <= x3) && (x3 <= x2)) // 수직선분의 x좌표가 수평선분 안에 있을 때
		{
			if ((y3 <= y1) && (y1 <= y4)) // 수평선분의 y좌표가 수직선분 안에 있을 때
			{
				if ((y1 == y3) || (y1 == y4))
					return 2;
				else if ((x3 == x1) || (x3 == x2))
					return 2;
				// 두 선분이 접하는 경우이다

				else
					return 1;
				// 두 선분이 완전교차하는 경우이다
			}
			else
				return 0;
			// 두 선분은 만나지 않는 경우이다
		}

		else
			return 0;
		// 수직선분의 x좌표가 수평선분 밖에 있을 때이므로 두 선분은 만나지 않는다
	}

	else // 선분1이 수직일 경우
	{
		int temp = x3;
		x3 = MIN(x3, x4);
		x4 = MAX(temp, x4); // x3 < x4
		temp = y1;
		y1 = MIN(y1, y2);
		y2 = MAX(temp , y2); // y1 < y2 를 만드는 과정

		if ((x3 <= x1) && (x1 <= x4)) // 수직선분의 x좌표가 수평선분 안에 있을 때
		{
			if ((y1 <= y3) && (y3 <= y2)) // 수평선분의 y좌표가 수직선분 안에 있을 때
			{
				if ((y3 == y1) || (y3 == y2))
					return 2;
				else if ((x1 == x3) || (x1 == x4))
					return 2;
				// 두 선분이 접하는 경우이다

				else
					return 1;
				// 두 선분이 완전교차하는 경우이다
			}
			else
				return 0;
			// 두 선분은 만나지 않는 경우이다
		}

		else
			return 0;
		// 수직선분의 x좌표가 수평선분 밖에 있을 때이므로 두 선분은 만나지 않는다
	}
}