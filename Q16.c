/*********************************************************************************************
*                                                                                            *
* Problem 16:                                                                                *
*          끝자리 0의 개수 구하기                                                            *
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
	int i, j;
	int no_cases, no_data;
	unsigned int num; // 자연수의 범위가 1 ~ (2^31)-1
	int check_two, check_five; // num들을 소인수 분해 할때 2와 5의 개수

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); //---- 테스트 횟수 읽어오기

	for (i = 0; i < no_cases; i++) //---- 테스트 반복
	{
		fscanf(fp, "%d", &no_data); //---- 곱할 정수 개수 읽어오기
		check_two = check_five = 0; // 초기화

		for (j = 0; j < no_data; j++) //---- 곱셈 반복
		{
			fscanf(fp, "%d", &num); //---- 데이타 읽어오기

			while (num % 2 == 0) // num이 2로 나누어지면 
			{
				num /= 2; // num을 2로 나누고
				check_two += 1; // check_two 1증가
			}
			while (num % 5 == 0) // num이 5로 나누어지면
			{
				num /= 5; // num을 5로 나누고
				check_five += 1; // check_five 1증가
			}
		}
		
		printf("%d\n", (check_two >= check_five) ? check_five : check_two);
		// check_two와 check_five 중 작은 쪽을 출력한다.
		/* 예를 들어 check_two = 3, check_five = 4 였으면
		입력받은 정수들중 소인수분해를 했을때 2의 개수들이 3개, 5의 개수들이 4개 이므로
		정수들을 곱했을때 10의 개수는 2와 5의 곱의 개수인 3개이다. */
	}

	fclose(fp);
}