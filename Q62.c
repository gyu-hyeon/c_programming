/********************************************************************
*
* Problem 62 :
*              바이트 스크램블 (Byte Scramble)
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
#include <math.h>

#pragma warning (disable : 4996)
typedef unsigned long myint; // myint의 범위 2^32 - 1 까지

int main(void)
{
	FILE *fp;
	myint n;
	// n : 이동시킬 숫자

	int no_cases = 0;
	int i, j, k;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 횟수 읽어오기

	for (i = 0; i<no_cases; i++) // 테스트 반복
	{
		myint mask = 0xFF; // 00000000 11111111
		myint afternum = 0; // n의 변환된 숫자
		myint num[5] = { 0 };
		int change[5] = { 0 };
		// num[] : 바이트 단위로 나누어 각각을 저장할 공간
		// change[] : 이동할 바이트 위치

		fscanf(fp, "%lu %d %d %d %d", &n, &change[4], &change[3], &change[2], &change[1]); // 숫자 읽어오기

		/* n을 바이트 단위로 나누어 num[]에 저장 */
		for (j = 1; j <= 4; j++)
		{
			num[j] = n & mask;
			mask *= pow(2, 8);
		}

		/* 변환 과정 */
		for (k = 1; k <= 4; k++)
		{
			if (change[k] > k)
			{
				num[change[k]] /= pow(2, 8 * (change[k] - k));
			}
			else if (change[k] < k)
			{
				num[change[k]] *= pow(2, 8 * (k - change[k]));
			}

			afternum |= num[change[k]];
		}

		printf("%lu\n", afternum);
	}
	fclose(fp);

	return 0;
}