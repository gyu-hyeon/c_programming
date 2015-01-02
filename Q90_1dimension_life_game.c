/********************************************************************
*
* Problem 90 :
*              1차원 라이프 게임 (1-dimension life game)
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
#include <string.h>

#define SIZE 53 // 배열의 크기
#pragma warning(disable : 4996)

void run_game(int arr[], int arr2[], int n, int k); // 1차원 라이프 게임 실행 함수
void print_result(int arr[], int n); // 게임 실행 후 결과 출력 함수

int main(void)
{
	FILE *fp;
	int no_cases;
	int n, k; // 격자판의 크기 : n, 단위시간 : k
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		int cell[SIZE] = { 0 }; // 박테리아수를 저장할 배열
		int after_cell[SIZE] = { 0 }; // 게임 실행후 결과를 저장할 배열

		fscanf(fp, "%d %d", &n, &k);

		for (j = 1; j <= n; j++)
			fscanf(fp, "%d", &cell[j]);

		run_game(cell, after_cell, n, k); // 게임 실행 함수 호출
		print_result(after_cell, n); // 결과 출력 함수 호출
	}

	fclose(fp);
}

/* 1차원 라이프 게임 실행 */
void run_game(int arr[], int arr2[], int n, int k)
{
	int i;

	while (k--)
	{
		for (i = 1; i <= n; i++)
		{
			int neighbor = arr[i - 1] + arr[i + 1];

			if (neighbor < 3 || neighbor > 7)
			{
				if (arr[i] == 0) arr2[i] = arr[i];
				else arr2[i] = arr[i] - 1;
			}
			else if (neighbor >= 4 && neighbor <= 7)
			{
				if (arr[i] == 9) arr2[i] = arr[i];
				else arr2[i] = arr[i] + 1;
			}
			else if (neighbor == 3) arr2[i] = arr[i];
		}

		memmove(arr, arr2, sizeof(int)*SIZE); 
	}
}

/* 게임 실행 후 결과 출력 */
void print_result(int arr[], int n)
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}