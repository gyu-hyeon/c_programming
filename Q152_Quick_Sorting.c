/********************************************************************
*
* Problem 152 :
*                퀵 정렬 (Quick Sorting)
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
int icompare(int *a, int *b);
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
		int *arr = NULL, size;
		fscanf(fp, "%d", &size);
		arr = (int*)malloc(sizeof(int)*size);

		for (j = 0; j < size; j++)
			fscanf(fp, "%d", (arr + j));

		qsort(arr, size, sizeof(int), icompare);

		for (j = 0; j < size; j++)
			printf("%d ", *(arr + j));

		printf("\n");

		free(arr);
	}

	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////

int icompare(int *a, int *b)
{
	return (*a - *b);
}