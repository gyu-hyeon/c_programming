/********************************************************************
*
* Problem 88 :
*              로또 6/45 (lotto 6/45)
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

#pragma warning(disable : 4996)

int lotto_check(int arr[]); // 로또 검사 함수
int bonus_check(int arr[]); // 보너스 숫자 검사 함수

int main(void)
{
	FILE *fp;
	int no_cases;
	int num[13] = { 0 }; // 번호를 읽어올 배열
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		for (j = 0; j < 13; j++)
			fscanf(fp, "%d", &num[j]); // 당첨 번호와 구입 번호 읽어오기

		printf("%d\n", lotto_check(num)); // 로또 검사 함수 호출
	}

	fclose(fp);
}

int lotto_check(int arr[])
{
	int i, j;
	int check = 0; // 당첨번호와 구입번호의 일치하는 숫자의 개수 (보너스 제외)

	/* 일치 검사 실행 */
	for (i = 0; i < 6; i++)
		for (j = 7; j < 13; j++)
			if (arr[i] == arr[j]) check++;

	/* 등수 반환 */
	switch (check)
	{
		case 3:
			return 5;
		case 4:
			return 4;
		case 5:
			if (bonus_check(arr) == 0) return 3;
			else return 2;
		case 6:
			return 1;
		default:
			return 0;
	}
}

/* 구입 번호에 보너스 번호가 있으면 1을, 아니면 0을 반환 */
int bonus_check(int arr[])
{
	int i;

	for (i = 7; i < 13; i++)
		if (arr[6] == arr[i]) return 1;

	return 0;
}