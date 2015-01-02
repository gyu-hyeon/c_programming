/********************************************************************
*
* Problem 81 :
*              주사위 숫자 분포 (2)
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
	int no_cases, num;
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);

	for (i = 0; i < no_cases; i++)
	{
		int num1, num2;
		int count[13] = { 0 }; // 인접한 두 숫자들의 분포를 저장할 배열

		fscanf(fp, "%d", &num);
		// 주사위 2개를 던지는 횟수

		for (j = 0; j < num; j++)
		{
			fscanf(fp, "%d %d", &num1, &num2);
			count[num1 + num2] += 1;
		}

		for (j = 2; j < 13; j++)
			printf("%d ", count[j]);
		// 분포 출력
		printf("\n");
	}
	fclose(fp);
}