/********************************************************************
*
* Problem 64 :
*              체크썸 (Checksum)
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

int checksum(myint n); // 체크썸을 이용한 데이터 오류 검출 함수

void main(void)
{
	FILE *fp;
	int no_cases;
	myint num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%u", &num); // 숫자 읽어오기

		printf("%d\n", checksum(num)); // 데이터 오류 검출
	}

	fclose(fp);
}

int checksum(myint n) // 데이터가 정상적으로 수신 됬다면 1을, 아니면 0을 반환 한다
{
	myint mask = 0xFF;
	myint n1 = 0, n2 = 0, n3 = 0, n4 = 0; // n4는 체크썸(하위 1바이트), n3, n2, n1은 순서대로 상위 3바이트
	myint sum = 0;

	n4 = n & mask;
	mask <<= 8;
	n1 = n & mask;
	mask <<= 8;
	n2 = n & mask;
	mask <<= 8;
	n3 = n & mask;
	// n의 바이트 구조를 알아냄 : n3n2n1n4

	n1 >>= 8;
	n2 >>= 16;
	n3 >>= 24;
	// 더하기 위해 쉬프트 연산을 함

	sum = n1 + n2 + n3;

	while (sum / 256 != 0)
		sum -= 256;
	// n1, n2, n3 값을 더하여, 그 값이 256보다 작아질 때까지 256을 뺀다

	sum = 255 - sum;
	// 체크썸 값을 연산한다

	if (n4 == sum) 
		return 1;
	else
		return 0;
	// 수신 데이터로 구한 체크썸 값과 송신 데이터의 체크썸 값이 같다면 1을, 아니면 0을 반환한다.
}