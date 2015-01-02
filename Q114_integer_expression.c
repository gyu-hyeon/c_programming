/********************************************************************
*
* Problem 114 :
*                정수 표현
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

int check_int(char* str);
int isodigit(char c);

int main(void)
{
	FILE *fp;

	int no_cases;
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		char str[300] = { 0 };
		char *str2 = NULL;

		fscanf(fp, "%s", str);
		
		printf("%d\n", check_int(str));
	}

	fclose(fp);

	return 0;
}

int check_int(char* str)
{
	int i;

	if (str[0] == '0') // 8진수, 16진수, 그외
	{
		if (str[1] == 'x' || str[1] == 'X') // 16진수, 그외
		{
			for (i = 2; i < strlen(str) ; i++)
			{
				if (!isxdigit(*(str+i)))
					return 0;
			}
			if (i == 2)
			{
				return 0;
			}
			return 16;
		}
		else // 8진수, 그외
		{
			for (i = 1; i < strlen(str); i++)
			{
				if (!isodigit(*(str + i)))
					return 0;
			}
			return 8;
		}
	}
	else // 10진수, 그외
	{
		for (i = 0; i < strlen(str); i++)
		{
			if (!isdigit(*(str + i)))
				return 0;
		}
		return 10;
	}
}

int isodigit(char c)
{
	if (c >= '0' && c <= '7')
		return 1;
	else
		return 0;
}