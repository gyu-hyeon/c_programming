/********************************************************************
*
* Problem 109 :
*                ������ ���� ��ȯ (Convert Numeral System(3))
*
*********************************************************************/
/********************************************************************
*
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 1�г�
*                                                20143053 ������
*
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)
typedef unsigned int myint;

//////////////////////////////  Function List  ////////////////////////////////////
char *readHexDNum(FILE *fp);
myint convertNum(char *num);
void printResult(myint num);
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ ���̽��� ����
	for (i = 0; i < no_cases; i++)
	{
		// char *num = NULL;

		// num = readHexDNum(fp);

		// printf("%d\n", strlen(num));
		// num = convertNum(num);
		// printResult(num);

		// free(num);
		myint num = 0;
		fscanf(fp, "%x", &num);

		printf("%d\n", num);




	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////
/*
char *readHexDNum(FILE *fp)
{
	char *num = NULL;
	num = (char*)malloc(sizeof(char)* 9);

	fscanf(fp, "%s", num);
	return num;
}

myint convertNum(char *num)
{
	int length = strlen(num), i;
	myint sum = 0;

	for (i = 0; *(num + i); i++)
	{
		sum += *(num + i)
	}

}

void printResult(char *num)
{
	printf("%d", num);
}
*/