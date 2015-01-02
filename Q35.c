/********************************************************************
*                                                                   *
* Problem 35 :                                                      *
*           구간과 숫자의 포함관계                                  *
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

int in_intervalCheck(int a, int b, int m); // 폐구간 a,b 사이에 m이 있는지 검사하는 함수

void main(void)
{
	FILE *fp;
	int no_cases, a, b, m;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d %d %d", &a, &b, &m); // 데이타 읽어오기

		printf("%d\n", in_intervalCheck(a, b, m)); // 검사해서 출력
	}

	fclose(fp);
}

int in_intervalCheck(int a, int b, int m) // [a,b] 안에 m이 있으면 1, 없으면 0 반환
{
	if ((a <= m) && (m <= b))
		return 1;
	else
		return 0;
}