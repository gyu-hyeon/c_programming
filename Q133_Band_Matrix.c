/********************************************************************
*
* Problem 133 :
*                밴드 행렬 (Band Matrix)
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

typedef struct matrix_size
{
	int *matA;
	int size;
	int s, t;
} MS; // 행렬연산에 쓰일 멤버 변수들의 구조체

//////////////////////////////  Function List  ////////////////////////////////////
void readMatrix(FILE *fp, MS ms);
int calcBand(MS ms);
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	MS ms;
	int no_cases;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		int sum = 0;
		fscanf(fp, "%d", &ms.size); // 행렬의 크기 스캔

		ms.matA = (int*)malloc(sizeof(int)*ms.size*ms.size); // 행렬 동적할당
		readMatrix(fp, ms);

		fscanf(fp, "%d %d", &ms.s, &ms.t);
		sum = calcBand(ms);
		printf("%d\n", sum);
		
		free(ms.matA); // 메모리 반납
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* 행렬을 읽어옴 */
void readMatrix(FILE *fp, MS ms)
{
	int i;

	for (i = 0; i < ms.size*ms.size; i++)
	{
		fscanf(fp, "%d", ms.matA + i);
	}
}

/* 밴드 계산 */
int calcBand(MS ms)
{
	int i, j, k;
	int sum = 0;

	for (k = ms.s; k <= ms.t; k++)
	{
		for (i = 0; i < ms.size; i++)
		{
			for (j = 0; j < ms.size; j++)
			{
				if ((j - i) == k) sum += *(ms.matA + i*ms.size + j);
			}
		}
	}

	return sum;
}
