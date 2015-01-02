/********************************************************************
*
* Problem 135 :
*                ������ (Othello)
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

#define SIZE 100
#pragma warning (disable : 4996)

int n; // Ƚ��

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

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ ���̽��� ����
	for (i = 0; i < no_cases; i++)
	{
		char *board = NULL; // �������� ��Ÿ�� ������
		int *num = NULL; // ��ǥ���� ������ ������

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

/* �������� �ʱ�ȭ */
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

/* ������ �о���� */
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

/* ������ ���� */
char* playOthello(char* board, int* num)
{
	int i, count = 0; // count % 2 ���� 0�̸� ������ ����, 1�̸� ��� ����

	for (i = 0; i < 2*n; i+=2){
		if (count % 2 == 0) *(board + *(num + i) * 8 + *(num + i + 1)) = 'X'; // ������ ���ʿ� ���� ���� ��ǥ�� ����
		else *(board + *(num + i) * 8 + *(num + i + 1)) = 'O'; // ��� ���ʿ� �� ���� ��ǥ�� ����

		board = changeCell(board, count%2, *(num + i), *(num + i + 1)); // ���� �� ��, ��ȭ�� ���忡 ����
		count++;
	}

	return board;
}

/* ���� 8ĭ���� ���� ���� ã�� ���ǿ� ���� ��ȭ */
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
			} // ������ ���ʿ��� ������� ����������...

			else if ((i != pi || j != pj) && count == 1 && *(board + i * 8 + j) == 'X') {
				count2 = findMyCell(board, count, i, j, i - pi, j - pj);
				if (count2 != 0){
					for (k = 0; k < count2; k++) { *(board + (i + (i - pi)*k) * 8 + (j + (j - pj)*k)) = 'O'; } 	
				}
				else continue;	
			} // ��� ���ʿ��� ���� ���� �������...
		}
	}

	return board;
}

/* i1, j1���� u1, u2 �������� ���� ���� ã�� */
int findMyCell(char* board, int count, int i1, int j1, int u1, int u2)
{
	int i, j;
	int count2 = 1; // u1, u2�������� �̵��� Ƚ��

	for (i = i1 + u1, j = j1 + u2; (i >= 1 && i <= 8) && (j >= 1 && j <= 8); i += u1, j += u2)	{
		if (*(board + i * 8 + j) == '+') return 0; // �����Ͻ� 0 ��ȯ
		if (count == 0 && *(board + i * 8 + j) == 'X') return count2; // ������ ���ʿ��� ������ ã��
		else if (count == 1 && *(board + i * 8 + j) == 'O') return count2; // ��� ���ʿ��� �� ã��

		count2++;
	}

	return 0; // ã�� �������Ƿ� (��� ���� ���̹Ƿ�) 0��ȯ
}

/* ������ ��� ��� */
void printResult(char *arr)
{
	int i, j;
	int countO = 0, countX = 0; // O,X�� ����

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
