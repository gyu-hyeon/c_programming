/********************************************************************
*
* Problem 106 :
*                ������ ��ȣ ��� (Caesar_Cipher)
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

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ ���̽��� ����
	for (i = 0; i < no_cases; i++)
	{
		char *message = NULL; // ���ڿ��� ���� ������ ����
		fscanf(fp, "%d", &moving_num); // �̵� Ƚ�� ��ĵ

		message = read_message(fp);
		message = change_message(message, moving_num);
		printResult(message);

		free(message);
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* ���ڿ��� �о�� ��ȯ */
char *read_message(FILE *fp)
{
	char *str = NULL;
	str = (char*)malloc(sizeof(char)* 101);
	fscanf(fp, "%s", str);

	return str;
}

/* ������ ��ȯ */
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

/* ��� ��� */
void printResult(char *str)
{
	int i;

	for (i = 0; letter; i++)
		printf("%c", letter);
	printf("\n");
}