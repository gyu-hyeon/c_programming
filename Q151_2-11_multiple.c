/********************************************************************
*
* Problem 151 :
*                2-11의 배수
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

///////////////////////////// Function List ///////////////////////////////////
int isMultipleOf_2(char *nstr);
int isMultipleOf_3(char *nstr);
int isMultipleOf_4(char *nstr);
int isMultipleOf_5(char *nstr);
int isMultipleOf_6(char *nstr);
int isMultipleOf_7(char *nstr);
int isMultipleOf_8(char *nstr);
int isMultipleOf_9(char *nstr);
int isMultipleOf_10(char *nstr);
int isMultipleOf_11(char *nstr);
int(*isMultipleOf[12]) (char *nstr) = { NULL, NULL, isMultipleOf_2, isMultipleOf_3, isMultipleOf_4, isMultipleOf_5, isMultipleOf_6, isMultipleOf_7, isMultipleOf_8, isMultipleOf_9, isMultipleOf_10, isMultipleOf_11 };
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////// Main () ///////////////////////////////////////
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
		char nstr[101] = { 0 };
		fscanf(fp, "%s", nstr);

		for (j = 2; j < 12; j++)
			printf("%d ", isMultipleOf[j](nstr));

		printf("\n");
	}

	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////

int isMultipleOf_2(char *nstr)
{
	if ((nstr[strlen(nstr) - 1] - '0') % 2) return 0;
	else return 1;
}

int isMultipleOf_3(char *nstr)
{
	int i, sum = 0;

	for (i = 0; i < strlen(nstr); i++) sum += nstr[i] - '0';

	if (sum % 3 == 0) return 1;
	else return 0;
}

int isMultipleOf_4(char *nstr)
{
	int last2 = 0;

	if (strlen(nstr) >= 2) last2 = atoi(nstr + strlen(nstr) - 2);
	else last2 = atoi(nstr);

	if (last2 % 4 == 0) return 1;
	else return 0;
}

int isMultipleOf_5(char *nstr)
{
	int last = (nstr[strlen(nstr) - 1] - '0');

	if (last == 0 || last == 5) return 1;
	else return 0;
}

int isMultipleOf_6(char *nstr)
{
	if (isMultipleOf_2(nstr) && isMultipleOf_3(nstr)) return 1;
	else return 0;
}

int isMultipleOf_7(char *nstr)
{
	int num = 0;
	char nstr2[101] = { 0 };

	if (strlen(nstr) >= 2)
	{
		num = ((nstr[0] - '0') * 3 + (nstr[1] - '0'));
		itoa(num, nstr2, 10);
		strcat(nstr2, nstr + 2);

		if (strlen(nstr2) == 1)
		{
			if (atoi(nstr2) % 7 == 0) return 1;
			else return 0;
		}
		else isMultipleOf_7(nstr2);
	}
	else
	{
		if (atoi(nstr) % 7 == 0) return 1;
		else return 0;
	}
}

int isMultipleOf_8(char *nstr)
{
	int last3 = 0;

	if (strlen(nstr) >= 3) last3 = atoi(nstr + strlen(nstr) - 2);
	else last3 = atoi(nstr);

	if (last3 % 8 == 0) return 1;
	else return 0;
}

int isMultipleOf_9(char *nstr)
{
	int i, sum = 0;

	for (i = 0; i < strlen(nstr); i++) sum += nstr[i] - '0';

	if (sum % 9 == 0) return 1;
	else return 0;
}

int isMultipleOf_10(char *nstr)
{
	int last = (nstr[strlen(nstr) - 1] - '0');

	if (last == 0) return 1;
	else return 0;
}

int isMultipleOf_11(char *nstr)
{
	int i, odd_sum = 0, even_sum = 0;

	for (i = 0; i < strlen(nstr); i++)
	{
		if (i % 2 == 0)	even_sum += nstr[i] - '0';
		else odd_sum += nstr[i] - '0';
	}

	if ((abs(even_sum - odd_sum)) % 11 == 0) return 1;
	else return 0;
}