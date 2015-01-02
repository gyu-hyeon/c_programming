/********************************************************************
*                                                                  
* Problem 43 :                                                     
*           수열의 길이                                            
*                                                                  
*********************************************************************/
/********************************************************************
*                                                                   
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년                   
*                                               20143053  남규현   
*                                                                  
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int sequenceLength(int n); // 수열의 길이를 구하는 함수

void main(void)
{
	FILE *fp;
	int no_cases, num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 반복 횟수 읽어오기

	for (i = 0; i < no_cases; i++) // 테스트 반복
	{
		fscanf(fp, "%d", &num); // 자연수를 읽어오기

		printf("%d\n", sequenceLength(num)); // num으로 시작하는 수열의 길이 출력
	}

	fclose(fp);
}

int sequenceLength(int n)
{
	int i = 1; // 수열의 길이를 나타내는 변수

	while (1)
	{
		if (n != 1)
		{
			if (n % 4 == 0)
				n /= 4;

			else if (n % 2 == 0)
				n /= 2;

			else
				n = n * 3 + 1;

			i += 1; // 조건을 만족하면 i값 1증가
		}

		else
			break; // n = 1이면 반복 종료
	}

	return i;
}