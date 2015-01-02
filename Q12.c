/*********************************************************************************************
*                                                                                            *
* Problem 12:                                                                                *
*          수열에서 연속적인 세 자연수와의 관계                                              *
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
	int no_cases, no_data, data;
	int i, j;
	int num1 = 0, num2 = 0, num3 = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &no_data); // 수열 속 자연수 개수 읽어오기

		for (j = 0; j < no_data; j++) // 자연수 개수만큼 반복
		{
			fscanf(fp, "%d", &data); // 데이타 읽어오기

			if (j == 0) num1 = data; // 첫째항을 num1에 저장
			if (j == 1) num2 = data; // 둘째항을 num2에 저장

			if (j >= 2)
			{
				num3 = data; // j+1번째 항을 num3에 저장

				if ((num1 <= num2) && (num2 <= num3)) a += 1;
				if ((num1 >= num2) && (num2 >= num3)) b += 1;
				if ((num1 == num2) && (num2 == num3)) c += 1;
				if (((num1 == num2) && (num1 != num3)) || ((num1 == num3) && (num3 != num2)) || ((num2 == num3) && (num3 != num1))) d += 1;
				if ((num1 != num2) && (num2 != num3) && (num3 != num1)) e += 1;
				// 각각의 경우들에 대해 경우값 연산

				num1 = num2;
				num2 = num3; // 다음 반복을 위한 작업
			}
		}

		printf("%d %d %d %d %d\n", a, b, c, d, e); // 경우값 출력
		a = b = c = d = e = 0; // 다음 반복을 위해 경우값 초기화
	}

	fclose(fp);
}