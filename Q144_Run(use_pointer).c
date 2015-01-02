/********************************************************************
*
* Problem 144 :
*                �� (Run) - (use pointer)
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
int len, k; // ����Ÿ�� ���� len, �ε��� k

//////////////////////////////  Function List  ////////////////////////////////////
int* readData(FILE *fp);
int* executeRun(int* arr);
void printResult(int *arr);
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
		int *arr = NULL, *result = NULL; // ����Ÿ�� ����� �޾ƿ� ������ ����

		arr = readData(fp);
		result = executeRun(arr);
		printResult(result);

		free(arr);
		free(result); // �޸� �ݳ�
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* ����Ÿ�� �о�� */
int* readData(FILE *fp)
{
	int i, *arr = NULL;

	fscanf(fp, "%d", &len);
	arr = (int*)malloc(sizeof(int)*(len+1));
	memset(arr, 0, sizeof(int)*(len + 1)); // 0���� �ʱ�ȭ

	for (i = 0; i < len; i++){
		fscanf(fp, "%d", arr + i);
	} // ����Ÿ ��ĵ

	return arr;
}

/* Run ���� */
int* executeRun(int* arr)
{
	int i, j;
	int *result = NULL;
	int count = 1;

	result = (int*)malloc(sizeof(int)*(len)* 2);
	memset(result, 0, sizeof(int)*(len)* 2);
	k = 0;

	for (i = 0; i < len; i++) {
		*(result + k++) = *(arr + i);
		for (j = i; j < len; j++)
		{
			if (i == len - 1) { 
				*(result + k++) = 1; break; 
			}
			if (*(arr + i) == *(arr + j + 1)){
				*(result + k)+=1;
				continue;
			}
			else{
				*(result + k) += 1;
				k++;
				i = j;
				break;
			}
		}
		if (j == len)
		{
			k++;
			i = j;
		}
	}

	return result;
}

/* ��� ��� */
void printResult(int *arr)
{
	int i;

	for (i = 0; i < k; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
}