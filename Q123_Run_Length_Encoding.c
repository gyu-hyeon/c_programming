/********************************************************************
*
* Problem 123 :
*                Run Length Encoding
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
#include <ctype.h>

#pragma warning (disable : 4996)

char *strschc(char *str, char *start);
char *strschup(char *str, char *start);

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases;
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		char *p1 = NULL, *p2 = NULL, str[1001] = { 0 };
		int cases = 0, sum = 0, count = 0, str_num = 0;

		fscanf(fp, "%d %s", &cases, str);

		if (cases == 0)
		{
			printf("%d ", strlen(str));
			p1 = str; // p1은 시작 지점, p2는 반환 지점

			do
			{
				p2 = strschc(str, p1);

				for (j = 0; j < (p2 - p1) / 256; j++)
				{
					count += 2;
				}
				count += 2;
				p1 = p2;
			} while (*p2 != NULL);

			printf("%d ", count);

			p1 = str;
			do
			{
				p2 = strschc(str, p1);

				for (j = 0; j < (p2 - p1) / 256; j++)
				{
					printf("%d%c", 0, *p1);
				}
				printf("%d%c", (p2 - p1) % 256, *p1);
				p1 = p2;
			} while (*p2 != NULL);

			printf("\n");
		}
		else
		{
			sum = count = 0;
			p1 = str;

			do
			{
				char str_part[1001] = { 0 };

				p2 = strschup(str, p1);
				strncpy(str_part, p1, p2 - p1);
				str_num = atoi(str_part);

				if (str_num == 0) str_num = 256;
				sum += str_num;
				count += 2;
				p1 = p2 + 1;
			} while (*p1 != NULL);

			printf("%d %d ", sum, count);

			p1 = str;

			do
			{
				char str_part[1001] = { 0 };

				p2 = strschup(str, p1);
				strncpy(str_part, p1, p2 - p1);
				str_num = atoi(str_part);

				if (str_num == 0) str_num = 256;
				memset(str_part, *p2, str_num);

				printf("%s", str_part);

				p1 = p2+1;
			} while (*p1 != NULL);
			printf("\n");

		}
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

char *strschc(char *str, char *start)
{
	int i;

	for (i = start - str; str[i] == *start; i++);

	return str + i;
}

char *strschup(char *str, char *start)
{
	int i;

	for (i = start - str; isupper(str[i]) == 0; i++);

	return str + i;
}