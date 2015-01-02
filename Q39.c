/********************************************************************
*                                                                   *
* Problem 39 :                                                      *
*           사각형과 점                                             *
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

int pointPositionCheck(int x1, int y1, int x2, int y2, int a, int b); // 점의 위치여부 반환 함수

void main(void)
{
	FILE *fp;
	int no_cases;
	int x1, y1, x2, y2, a, b;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2); // 사각형 좌표 읽어오기 -- 아래 주석 참조
		fscanf(fp, "%d %d", &a, &b); // 점 좌표 읽어오기
		
		printf("%d\n", pointPositionCheck(x1, y1, x2, y2, a, b)); // 점의 위치 여부 출력
	}

	fclose(fp);
}

/* 0-----------------0 (x2, y2)
   |                 |
   |                 |
   0-----------------0
   (x1, y1)                   */

int pointPositionCheck(int x1, int y1, int x2, int y2, int a, int b) // 점의 위치 여부 반환
{
	// 내부에 있을 경우 0
	// 외부에 있을 경우 1
	// 변에 있을 경우 2 
	// 꼭지점에 있을 경우 3 을 각각 반환

	if ((a >= x1) && (a <= x2) && (b >= y1) && (b <= y2)) // 사각형 선을 포함하여 점이 내부에 있을 경우
	{
		if ((a > x1) && (a < x2) && (b > y1) && (b < y2)) // 점이 내부에 있을 경우
			return 0;

		else if ((a == x1) || (a == x2)) // 점이 왼변 혹은 오른변에 있을 경우
		{
			if ((b == y1) || (b == y2)) // 점이 꼭지점에 있을 경우
				return 3;
			else // 점이 변에 있을 경우
				return 2;
		}

		else // 점이 윗변 혹은 아랫변에 있을 경우
		{
			if ((a == x1) || (a == x2)) // 점이 꼭지점에 있을 경우
				return 3;
			else // 점이 변에 있을 경우
				return 2;
		}
	}

	else // 점이 사각형 외부에 있을 경우
		return 1;
}