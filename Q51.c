/********************************************************************
*
* Problem 51 :
*              소수
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

int check_primeNum(int n); // 소수의 여부를 판단하는 함수

void main(void)
{
	FILE *fp;
	int no_cases, num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &num); //소수를 구할 숫자 읽어오기

		printf("%d\n", check_primeNum(num)); // num 의 소수여부를 출력 
	}

	fclose(fp);
}

// 소수이면 1, 아니면 0을 반환
int check_primeNum(int n)
{
	int i;
	int count = 0;

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			count += 1;
		else
			continue;
	}

	if (count == 2)
		return 1;
	else
		return 0;
}