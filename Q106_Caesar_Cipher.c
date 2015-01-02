/********************************************************************
*
* Problem 106 :
*                시이저 암호 기법 (Caesar_Cipher)
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
#include <string.h>

#pragma warning (disable : 4996)
#define letter *(str + i)

//////////////////////////////  Function List  ////////////////////////////////////
char *read_message(FILE *fp);
char *change_message(char *str, int k);
void printResult(char *str);
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases, moving_num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		char *message = NULL; // 문자열을 담을 포인터 변수
		fscanf(fp, "%d", &moving_num); // 이동 횟수 스캔

		message = read_message(fp);
		message = change_message(message, moving_num);
		printResult(message);

		free(message);
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* 문자열을 읽어와 반환 */
char *read_message(FILE *fp)
{
	char *str = NULL;
	str = (char*)malloc(sizeof(char)* 101);
	fscanf(fp, "%s", str);

	return str;
}

/* 시이저 변환 */
char *change_message(char *str, int k)
{
	int i;

	for (i = 0; letter; i++)
	{
		if (letter >= 'A' && letter <= 'Z')
		{
			if (letter + k > 'Z') letter += k - 26;
			else letter += k;
		}
		else if (letter >= 'a' && letter <= 'z')
		{
			if (letter + k > 'z') letter += k - 26;
			else letter += k;
		}
	}

	return str;
}

/* 결과 출력 */
void printResult(char *str)
{
	int i;

	for (i = 0; letter; i++)
		printf("%c", letter);
	printf("\n");
}