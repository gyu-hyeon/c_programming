/********************************************************************
*
* Problem 50 :
*              약수의 합 구하기
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

int sum_divisor(int n); // 진약수의 합을 구하는 함수
int count_divisor(int n); // 진약수의 개수를 구하는 함수

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
		fscanf(fp, "%d", &num); // 진약수를 구할 숫자 읽어오기

		printf("%d %d\n", count_divisor(num), sum_divisor(num)); // num 의 진약수의 합과 개수 출력 
	}

	fclose(fp);
}

int count_divisor(int n) // n의 진약수 개수 반환
{
	int i;
	int count = 1;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			count += 2;
	}

	return count;
}

int sum_divisor(int n) // n의 진약수의 합 반환
{
	int i;
	int sum = 1;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
			sum += n / i;
		}
	}

	return sum;
}