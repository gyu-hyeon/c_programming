/********************************************************************
*
* Problem 135 :
*                오셀로 (Othello)
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

#define SIZE 100
#pragma warning (disable : 4996)

int n; // 횟수

//////////////////////////////  Function List  ////////////////////////////////////
char* initializeBoard(void);
int* readGame(FILE *fp);
char* playOthello(char* board, int* num);
char* changeCell(char* board, int count, int pi, int pj);
int findMyCell(char* board, int count, int i1, int j1, int u1, int u2);
void printResult(char *arr);
/////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases, i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		char *board = NULL; // 보드판을 나타낼 포인터
		int *num = NULL; // 좌표들을 저장할 포인터

		board = initializeBoard(); 
		num = readGame(fp);
		board = playOthello(board, num);
		printResult(board);

		free(board);
		free(num);
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////

/* 보드판을 초기화 */
char* initializeBoard(void)
{
	char *arr = NULL;
	arr = (char*)malloc(sizeof(char)* SIZE);
	memset(arr, '+', sizeof(char)* SIZE);
	
	*(arr + 4 * 8 + 4) = 'O';
	*(arr + 5 * 8 + 5) = 'O';
	*(arr + 4 * 8 + 5) = 'X';
	*(arr + 5 * 8 + 4) = 'X';

	return arr;
}

/* 게임을 읽어오기 */
int* readGame(FILE *fp)
{
	int i, *arr = NULL;

	fscanf(fp, "%d", &n);
	arr = (int*)malloc(sizeof(int)*n * 2);

	for (i = 0; i < n * 2; i++) {
		fscanf(fp, "%d", arr + i);
	}
	return arr;
}

/* 오셀로 실행 */
char* playOthello(char* board, int* num)
{
	int i, count = 0; // count % 2 값이 0이면 검은색 차례, 1이면 흰색 차례

	for (i = 0; i < 2*n; i+=2){
		if (count % 2 == 0) *(board + *(num + i) * 8 + *(num + i + 1)) = 'X'; // 검은색 차례에 검은 돌을 좌표에 저장
		else *(board + *(num + i) * 8 + *(num + i + 1)) = 'O'; // 흰색 차례에 흰 돌을 좌표에 저장

		board = changeCell(board, count%2, *(num + i), *(num + i + 1)); // 돌을 둔 후, 변화를 보드에 저장
		count++;
	}

	return board;
}

/* 인접 8칸에서 상대방 돌을 찾고 조건에 때라 변화 */
char* changeCell(char* board, int count, int pi, int pj)
{
	int i, j, k;
	int count2;

	for (i = pi - 1; i <= pi + 1; i++){
		for (j = pj - 1; j <= pj + 1; j++)	{
			if ((i != pi || j != pj) && count == 0 && *(board + i * 8 + j) == 'O') {
				count2 = findMyCell(board, count, i, j, i - pi, j - pj);
				if (count2 != 0) {
					for (k = 0; k < count2; k++) { *(board + (i + (i - pi)*k) * 8 + (j + (j - pj)*k)) = 'X'; }
				}
				else continue;   
			} // 검은색 차례에서 흰색돌을 검은색으로...

			else if ((i != pi || j != pj) && count == 1 && *(board + i * 8 + j) == 'X') {
				count2 = findMyCell(board, count, i, j, i - pi, j - pj);
				if (count2 != 0){
					for (k = 0; k < count2; k++) { *(board + (i + (i - pi)*k) * 8 + (j + (j - pj)*k)) = 'O'; } 	
				}
				else continue;	
			} // 흰색 차례에서 검은 돌을 흰색으로...
		}
	}

	return board;
}

/* i1, j1에서 u1, u2 방향으로 나의 돌을 찾음 */
int findMyCell(char* board, int count, int i1, int j1, int u1, int u2)
{
	int i, j;
	int count2 = 1; // u1, u2방향으로 이동한 횟수

	for (i = i1 + u1, j = j1 + u2; (i >= 1 && i <= 8) && (j >= 1 && j <= 8); i += u1, j += u2)	{
		if (*(board + i * 8 + j) == '+') return 0; // 공백일시 0 반환
		if (count == 0 && *(board + i * 8 + j) == 'X') return count2; // 검은색 차례에서 검은돌 찾기
		else if (count == 1 && *(board + i * 8 + j) == 'O') return count2; // 흰색 차례에서 흰돌 찾기

		count2++;
	}

	return 0; // 찾지 못했으므로 (모두 상대방 돌이므로) 0반환
}

/* 오셀로 결과 출력 */
void printResult(char *arr)
{
	int i, j;
	int countO = 0, countX = 0; // O,X의 개수

	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 8; j++) {
			(*(arr + i * 8 + j) == 'O') ? countO++ : ((*(arr + i * 8 + j) == 'X') ? countX++ : 0);
		}
	}

	printf("%d %d\n", countX, countO);

	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 8; j++) {
			printf("%c", *(arr + i * 8 + j)); } printf("\n"); 
	}
}
