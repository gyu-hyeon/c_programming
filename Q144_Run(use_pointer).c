/********************************************************************
*
* Problem 144 :
*                런 (Run) - (use pointer)
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
int len, k; // 데이타의 길이 len, 인덱스 k

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

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		int *arr = NULL, *result = NULL; // 데이타와 결과를 받아올 포인터 변수

		arr = readData(fp);
		result = executeRun(arr);
		printResult(result);

		free(arr);
		free(result); // 메모리 반납
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* 데이타를 읽어옴 */
int* readData(FILE *fp)
{
	int i, *arr = NULL;

	fscanf(fp, "%d", &len);
	arr = (int*)malloc(sizeof(int)*(len+1));
	memset(arr, 0, sizeof(int)*(len + 1)); // 0으로 초기화

	for (i = 0; i < len; i++){
		fscanf(fp, "%d", arr + i);
	} // 데이타 스캔

	return arr;
}

/* Run 실행 */
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

/* 결과 출력 */
void printResult(int *arr)
{
	int i;

	for (i = 0; i < k; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
}