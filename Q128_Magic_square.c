/********************************************************************
*
* Problem 128 :
*              매직 스퀘어 (Magic square)
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

#define SIZE 100 // 배열의 크기
#pragma warning(disable : 4996)

int check_MSquare(int arr[][SIZE], int n); // 매직 스퀘어 판별 함수

int main(void)
{
	FILE *fp;
	int no_cases, no_data;
	int i, j, k;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		int M_matrix[SIZE][SIZE] = { 0 }; // 행렬의 원소들을 저장할 2차원 배열
		fscanf(fp, "%d", &no_data);

		/* 배열에 원소들 저장 */
		for (j = 0; j < no_data; j++)
			for (k = 0; k < no_data; k++)
				fscanf(fp, "%d", &M_matrix[j][k]);

		printf("%d\n", check_MSquare(M_matrix, no_data)); // 매직 스퀘어 판별 함수 호출
	}

	fclose(fp);
}

/* 매직 스퀘어 판별 함수 */
int check_MSquare(int arr[][SIZE], int n)
{
	int arr2[202] = { 0 };
	int i, j;

	/* arr2에서 0 ~ n-1은 각 행 원소의 합, 
	   n ~ 2n-1은 각 열 원소의 합, 
	   2n, 2n+1은 대각선원소 의 합 */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j) arr2[2*n] += arr[i][j];
			if ((i + j) == (n - 1)) arr2[2*n+1] += arr[i][j];
			arr2[i] += arr[i][j];
			arr2[i + n] += arr[j][i];
		}
	}
	
	/* 매직스퀘어가 아니면 -1을, 맞으면 한 행의 합을 반환*/
	for (i = 0; i < 2*n+2; i++)
	{
		if (arr2[i] != arr2[0])
			return -1;
	}

	return arr2[0];
}