/*********************************************************************************************
*                                                                                            *
* Problem 8:                                                                                 *
*          주어진 정수의 최대, 최소 구하기                                                   *
*                                                                                            *
*********************************************************************************************/

/*********************************************************************************************
*                                                                                            *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년                                             *
*                                                                20143053 남규현             *
*                                                                                            *
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

void main(void)
{
	FILE *fp;
	int i, j;
	int no_cases, no_data, data;
	int min, max; // 최소값, 최대값

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수

	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d", &no_data); // 테스트 수들의 개수

		fscanf(fp, "%d", &data); // 테스트 수
		min = max = data; // min, max 값에 첫번째 data 값을 넣는다

		for (j = 1; j < no_data; j++)
		{
			fscanf(fp, "%d", &data);

			min = (min > data) ? data : min; // 다음 data 값과 비교하여 연산
			max = (max < data) ? data : max;
		}

		printf("%d %d\n", max, min); // 최소 최대값 출력
	}

	fclose(fp);
}