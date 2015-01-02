/********************************************************************
*
* Problem 137 :
*                지뢰 찾기 (Mine Sweeper)
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

typedef struct
{
	int row; // 행
	int column; // 열
	char *input_map; // 입력 맵
	char *result_map; // 결과 맵
	char *output_map; // (사용자에 의한) 출력 맵
} MS; // 지뢰찾기에 필요한 변수들을 포함시킨 구조체 선언

///////////////////////////// Function List ///////////////////////////////////
MS *readCell(FILE *fp, MS *ms); 
MS *operateResult(MS *ms); 
MS *isNearMine(MS *ms, int pi, int pj);
MS *runMindSweeper(MS *ms);
MS *floodFill(MS *ms, int pi, int pj);
void printResult(MS *ms); 
void freeMap(MS *ms); 
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////// Main () ///////////////////////////////////////
int main(void)
{
	FILE *fp;
	MS user_ms = { 0, 0, NULL, NULL, NULL }, *ms = &user_ms; // 구조체 변수, 구조체 포인터 변수 선언
	int no_cases;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		ms = readCell(fp, ms);
		ms = runMindSweeper(ms);
		printResult(ms);
		freeMap(ms);
	}

	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////

// 입력 맵에 조건을 읽어오고, 세 맵 초기화 및 동적할당
MS *readCell(FILE *fp, MS *ms)
{
	int i;

	fscanf(fp, "%d %d", &ms->column, &ms->row);

	// input_map 동적 할당 및 초기화
	ms->input_map = (char*)malloc(sizeof(char)*(ms->row + 2)*(ms->column + 2));
	memset(ms->input_map, '+', sizeof(char)*(ms->row + 2)*(ms->column + 2));

	// result_map 동적 할당 및 초기화
	ms->result_map = (char*)malloc(sizeof(char)*(ms->row + 2)*(ms->column + 2));
	memset(ms->result_map, '0', sizeof(char)*(ms->row + 2)*(ms->column + 2));

	// output_map 동적할당 및 초기화
	ms->output_map = (char*)malloc(sizeof(char)*(ms->row + 2)*(ms->column + 2));
	memset(ms->output_map, '+', sizeof(char)*(ms->row + 2)*(ms->column + 2));

	// input_map 읽어오기
	for (i = 1; i <= ms->row; i++)
	{
		fscanf(fp, "%s", ms->input_map + 1 + i*(ms->column + 2));
		*(ms->input_map + (i + 1)*(ms->column + 2) - 1) = '+';
	}

	return ms;
}

// 결과 맵에 입력 맵에 의한 결과 저장
MS *operateResult(MS *ms)
{
	int i, j;

	for (i = 1; i <= ms->row; i++)
	{
		for (j = 1; j <= ms->column; j++)
		{
			if (*(ms->input_map + i * (ms->column + 2) + j) == '*')
			{
				ms = isNearMine(ms, i, j);
			}
		}
	}

	return ms;
}

// 입력맵 지뢰위치에서 그 위치의 결과맵 주변에 숫자 1증가
MS *isNearMine(MS *ms, int pi, int pj)
{
	int i, j;

	for (i = pi - 1; i <= pi + 1; i++)
	{
		for (j = pj - 1; j <= pj + 1; j++)
		{
			if ((i == pi && j == pj) || (*(ms->input_map + i * (ms->column + 2) + j) == '*'))
				continue;
			else
				*(ms->result_map + i * (ms->column + 2) + j) += 1;
		}
	}

	return ms;
}

// 지뢰찾기 수행
MS *runMindSweeper(MS *ms)
{
	int i, j;

	ms = operateResult(ms);

	for (i = 1; i <= ms->row; i++)
	{
		for (j = 1; j <= ms->column; j++)
		{
			if (*(ms->input_map + i * (ms->column + 2) + j) == '?')
			{
				ms = floodFill(ms, i, j);
			}
		}
	}

	return ms;
}

// 입력맵의 사용자 클릭 위치를 기준으로, 출력 맵에 결과 맵의 숫자들을 저장
MS *floodFill(MS *ms, int pi, int pj)
{
	// 범위가 벗어나면 종료
	if (pi < 1 || pi > ms->row || pj < 1 || pj > ms->column)
		return ms;
	
	// 결과 맵에 값이 있다면 그값을 출력 맵에 저장 후 종료
	if (*(ms->result_map + pi * (ms->column + 2) + pj) >= '1')
	{
		*(ms->output_map + pi * (ms->column + 2) + pj) = *(ms->result_map + pi * (ms->column + 2) + pj);
		return ms;
	}

	// 출력 맵에 숫자 값이 있다면 종료
	if (*(ms->output_map + pi * (ms->column + 2) + pj) >= '0')
	{
		return ms;
	}

	// 아니면 0을 입력하고 8방향 재귀함수 호출
	else
	{
		*(ms->output_map + pi * (ms->column + 2) + pj) = '0';

		ms = floodFill(ms, pi, pj - 1);
		ms = floodFill(ms, pi, pj + 1);
		ms = floodFill(ms, pi - 1, pj);
		ms = floodFill(ms, pi + 1, pj);

		ms = floodFill(ms, pi - 1, pj - 1);
		ms = floodFill(ms, pi - 1, pj + 1);
		ms = floodFill(ms, pi + 1, pj - 1);
		ms = floodFill(ms, pi + 1, pj + 1);
	}
}

// 출력 맵 출력
void printResult(MS *ms)
{
	int i, j;

	for (i = 1; i <= ms->row; i++)
	{
		for (j = 1; j <= ms->column; j++)
		{
			printf("%c", *(ms->output_map + i * (ms->column + 2) +j));
		}
		printf("\n");
	}
}

// 메모리 반납
void freeMap(MS *ms)
{
	free(ms->input_map);
	free(ms->result_map);
	free(ms->output_map);
}