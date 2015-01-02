/********************************************************************
*
* Problem 61 :
*              패리티 비트
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

unsigned int even_parity(unsigned int n); // 짝수 패리티 비트를 사용하여 n의 값을 새롭게 반환하는 함수

void main(void)
{
	FILE *fp;
	int no_cases;
	unsigned int num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%u", &num); // 숫자 읽어오기

		printf("%u\n", even_parity(num)); // num의 패리티 비트를 정하여 만든 새로운 데이터 출력
	}

	fclose(fp);
}

unsigned int even_parity(unsigned int n) // 짝수 패리티 기법을 사용한 함수
{
	int count = 0; // 1의 개수를 세는 변수
	unsigned int num = n;
	int i;

	for (i = 0; i<31; i++)
	{
		if ((n & 1) == 1)
			count += 1;

		n = n >> 1;
	}

	if (count % 2 == 0)
		return num; // 1의 개수가 짝수 이면 그대로 반환
	else
		return num | 0x80000000; // 1의 개수가 홀수이면 맨 마지막 비트 즉, 2^32비트 부분에 1증가 하여 반환 
}