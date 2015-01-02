/********************************************************************
*
* Problem 82 :
*              시험 점수 분포
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

#pragma warning (disable : 4996)

int main(void)
{
	FILE *fp;
	int no_cases, num; // 테스트 케이스, 점수의 개수
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);

	for (i = 0; i < no_cases; i++)
	{
		int score[100] = { 0 }; // 점수를 저장할 배열
		int count[101] = { 0 }; // 각 점수의 개수를 저장할 배열

		fscanf(fp, "%d", &num);

		/* 점수를 입력받아 score[], 점수에 따른 개수 저장 */
		for (j = 0; j < num; j++)
		{
			fscanf(fp, "%d", &score[j]);
			count[score[j]] += 1;
		}

		/* count[] : 점수와 개수 출력 */
		for (j = 0; j < 101; j++)
		{
			if (count[j] != 0)
				printf("%d %d ", j, count[j]);
		}

		printf("\n");
	}

	fclose(fp);
}