/********************************************************************
*
* Problem 63 :
*              해밍거리 (Hamming Distance)
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
typedef unsigned int myint; // myint의 범위 2^32 - 1 까지

void hamming_weight(myint n); // n의 해밍 무게를 출력하는 함수
void hamming_distance(myint n1, myint n2); // n1, n2사이의 해밍 거리를 출력하는 함수

void main(void)
{
	FILE *fp;
	int no_cases;
	myint num1, num2;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%u %u", &num1, &num2); // 숫자 읽어오기

		hamming_weight(num1);
		hamming_weight(num2); // num1, num2의 해밍무게 출력
		hamming_distance(num1, num2); // num1,num2 간의 해밍거리 출력
	}

	fclose(fp);
}

void hamming_weight(myint n) // n의 해밍무게 출력
{
	int i;
	int weight = 0;

	for (i = 0; i < 31; i++)
	{
		if ((n & 1) == 1)
			weight += 1;
		n = n >> 1;
	}

	printf("%d ", weight);
}

void hamming_distance(myint n1, myint n2) // n1, n2간의 해밍거리 출력
{
	int i;
	int distance = 0;

	for (i = 1; i <= 31; i++)
	{
		if (((n1 & 1) ^ (n2 & 1)) == 1)
			distance += 1;

		n1 = n1 >> 1;
		n2 = n2 >> 1;
	}

	printf("%d\n", distance);
}
