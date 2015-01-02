/********************************************************************
*
* Problem 91 :
*              버블 정렬 (Bubble sorting)
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

#define SIZE 100 // 배열의 크기
#pragma warning(disable : 4996)

void bubble_sorting(int arr[], int n); // 버블 정렬 실행 함수
void print_sort(int arr[], int n); // 정렬 결과 출력 함수

int main(void)
{
	FILE *fp;
	int no_cases, no_data;
	int num[SIZE] = { 0 }; // 숫자들 저장할 배열
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d", &no_data);

		for (j = 0; j < no_data; j++)
			fscanf(fp, "%d", &num[j]); // 배열에 정렬할 숫자들 저장

		bubble_sorting(num, no_data); // 버블 정렬 함수 호출
		print_sort(num, no_data); // 정렬결과 출력 함수 호출
	}

	fclose(fp);
}

/* 버블 정렬 실행 */
void bubble_sorting(int arr[], int n)
{
	int i, j, temp;

	for (i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

/* 결과 출력 */
void print_sort(int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}