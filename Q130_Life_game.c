/********************************************************************
*
* Problem 130 :
*                라이프 게임 (Life game)
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

//////////////////////////////  Function List  ////////////////////////////////////
int readCell(FILE *fp, char *arr, int column, int row);
void runLifeGame(char *arr, int column, int row, int t);
int aroundArr(char *arr, int pi, int pj, int column);
void printResultGame(char *arr, int column, int row);
int countAliveCell(char *arr, int column, int row);
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
		char *cell; // 셀의 위치를 저장할 포인터 변수
		int row, column, time; // 행, 열, 시간을 의미하는 변수

		fscanf(fp, "%d %d", &row, &column);
		cell = (char*)malloc(sizeof(char)*(row + 2)*(column + 2)); // (row + 2)*(column + 2) 크기로 동적할당

		time = readCell(fp, cell, column, row); // 시간을 스캔하여 저장하고 cell에 셀의 초기상태 입력
		runLifeGame(cell, column, row, time); // 라이프 게임 실행
		printResultGame(cell, column, row); // 라이프 게임 결과 출력

		free(cell); // 메모리 반납
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* cell 을 읽어오고 time 값 반납 */
int readCell(FILE *fp, char *arr, int column, int row)
{
	int i;
	int t; // 시간을 저장할 변수

	fscanf(fp, "%d", &t);
	memset(arr, 'X', sizeof(char)*(row + 2)*(column + 2)); // cell을 모두 X로 초기화

	/* 셀의 초기 조건 스캔 */
	for (i = 1; i <= row; i++)
	{
		fscanf(fp, "%s", arr + 1 + i*(column + 2));
		*(arr + (i + 1)*(column + 2) - 1) = 'X';
	}

	return t;
}

/* 라이프 게임 실행 */
void runLifeGame(char *arr, int column, int row, int t)
{
	int i, j;
	int arrdNoO = 0; // i,j 위치에서 주변 8칸의 O의 개수를 저장할 변수

	char *arr2 = (char*)malloc(sizeof(char)*(row + 2)*(column + 2));
	// 임시로 결과를 저장할 포인터변수 동적할당

	/* t 시간동안 라이프게임 실행 */
	while (t--)
	{
		memset(arr2, 'X', sizeof(char)*(row + 2)*(column + 2));

		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= column; j++)
			{
					arrdNoO = aroundArr(arr, i, j, column);

					if (arrdNoO <= 1) *(arr2 + i *(column + 2) + j) = 'X';
					if (arrdNoO == 2 && *(arr + i *(column + 2) + j) == 'O') *(arr2 + i *(column + 2) + j) = 'O';
					if (arrdNoO == 3) *(arr2 + i *(column + 2) + j) = 'O';
					if (arrdNoO >= 4) *(arr2 + i *(column + 2) + j) = 'X';
			}
		}

		memmove(arr, arr2, sizeof(char)*(row + 2)*(column + 2)); // 임시 결과값을 다시 cell에 저장
	}

	free(arr2); // 메모리 반납
}

/* 주변 8칸 O의 개수를 반환 */
int aroundArr(char *arr, int pi, int pj, int column)
{
	int i, j;
	int countNoO = 0;

	for (i = pi - 1; i <= pi + 1; i++)
	{
		for (j = pj - 1; j <= pj + 1; j++)
		{
			if ((i != pi || j != pj) && *(arr + i *(column + 2) + j) == 'O') countNoO++;
		}
	}

	return countNoO;
}

/* 라이프 게임 결과 출력 */
void printResultGame(char *arr, int column, int row)
{
	int i, j;
	printf("%d\n", countAliveCell(arr, column, row));

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= column ; j++)
		{
			printf("%c", *(arr + i *(column + 2) + j));
		}
		printf("\n");
	}
}

/* t시간후 살아있는 셀의 개수 반환 */
int countAliveCell(char *arr, int column, int row)
{
	int i, j;
	int countCell = 0; 

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= column; j++)
		{
			if (*(arr + i *(column + 2) + j) == 'O') countCell++;
		}
	}

	return countCell;
}