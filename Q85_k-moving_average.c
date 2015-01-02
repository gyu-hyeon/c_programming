/********************************************************************
*
* Problem 85 :
*              이동 평균 (k-moving average)
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

#pragma warning(disable : 4996)

void moving_average(int arr[], int n, int k); // 이동 평균 실행 및 출력 함수

int main(void)
{
	FILE *fp;
	int no_cases, no_data;
	int num[256] = { 0 }; // 수열을 저장할 배열
	int i, j; 
	int k; // 주기

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d", &no_data);

		/* 수열들을 저장 */
		for (j = 0; j < no_data; j++)
		{
			fscanf(fp, "%d", &num[j]);
		}

		fscanf(fp, "%d", &k);

		moving_average(num, no_data, k); // 이동평균 함수 호출
	}
	
	fclose(fp);
}

/* 이동 평균 실행 및 수열 출력 */
void moving_average(int arr[], int n, int k)
{
	int i, j;
	int average_arr[256] = { 0 };

	printf("%d ", n - k + 1);

	for (i = 0; i < n - k + 1; i++)
	{
		for (j = i; j < k + i; j++)
		{
			average_arr[i] += arr[j];
		}

		printf("%d ", average_arr[i] / k);
	}

	printf("\n");
}
