/********************************************************************
*
* Problem 129 :
*              8 Queen 문제
*
*********************************************************************/
/********************************************************************
*
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년
*                                                20143053 남규현
*
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CHESS_SIZE 9 // 체스판의 크기
#define SIZE 17 // 배열의 크기
#pragma warning(disable : 4996)

int queen_check(int arr[]);

int main(void)
{
	FILE *fp;
	int no_cases;
	int i, j, k;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		char queen[SIZE] = { 0 }; // 퀸의 좌표들을 읽어올 배열
		int check[48] = { 0 }; // 검사조건들에 대한 배열
		int chess[CHESS_SIZE][CHESS_SIZE] = { 0 }; // 퀸 들을 저장할 2차원 배열

		/* 좌표 스캔 */
		for (j = 0; j < 8; j++)
			fscanf(fp, "%s", queen + 2 * j);

		/* 체스판에 퀸의 좌표에 대해 1증가 (ex : a행 8열 -> 1행 8열)*/
		for (j = 0; j < SIZE; j += 2)
			chess[queen[j] - 96][queen[j + 1] - 48]++;

		/* check 값 계산 */
		for (j = 1; j < CHESS_SIZE; j++)
		{
			for (k = 1; k < CHESS_SIZE; k++)
			{
				check[j + k] += chess[j][k]; // check[2 ~ 16], 이중에 8개가 1이어야 한다.
				check[24 + j - k] += chess[j][k]; // check[17 ~ 31], 이중에 8개가 1어야 한다.
				check[31 + j] += chess[j][k]; // check[32 ~ 39], 이중에 모두 1이여야 한다.
				check[39 + j] += chess[k][j]; // check[40 ~ 47], 이중에 모두 1이여야 한다.
			}
		}

		printf("%d\n", queen_check(check));
	}

	fclose(fp);
}

/* 문제 조건을 만족하면 1을, 아니면 0을 반환 */
int queen_check(int arr[])
{
	int i;
	int count_a = 0, count_b = 0;

	for (i = 2; i < 48; i++)
	{
		if (i >= 2 && i <= 16 && arr[i] == 1) count_a++;
		if (i >= 17 && i <= 31 && arr[i] == 1) count_b++;
		if (i >= 32 && i <= 39 && arr[i] == 0) return 0; // 행마다 퀸이 1개만 있어야 한다
		if (i >= 40 && i <= 47 && arr[i] == 0) return 0; // 열마다 퀸이 1개만 있어야 한다
	}

	if (count_a != 8 || count_b != 8) return 0; // 대각선 합들(15개)중 퀸이 8개가 있어야 한다

	return 1; // 조건을 모두 만족시키지 않는다면(8 Queen 문제를 만족할경우) 1을 반환
}