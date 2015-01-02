/*********************************************************************************************
*                                                                                            *
* Problem 5:                                                                                 *
*          부활절 날짜 계산                                                                  *
*                                                                                            *
*********************************************************************************************/

/*********************************************************************************************
*                                                                                            *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1학년                                             *
*                                                                20143053 남규현             *
*                                                                                            *
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

void compute_easter(int y);

void main(void)
{
	FILE *fp;
	int i;
	int no_cases;
	int year;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);

	for (i = 0; i < no_cases; i++)
	{
		fscanf(fp, "%d", &year);
		compute_easter(year);
	}

	fclose(fp);
}

void compute_easter(int y)
{
	int c, n, t, i, j, k, l, p, q;
	int month, day;

	c = y / 100;
	n = y - ((y / 19) * 19);
	t = (c - 17) / 25;
	i = (c - (c / 4) - ((c - t) / 3)) + ((n * 19) + 15);
	j = i - ((i / 30) * 30);
	k = j - ((j / 28) * (1 - (j / 28)) * (29 / (j + 1)) * ((21 - n) / 11));
	l = (y + (y / 4) + j + 2) - c + (c / 4);
	p = l - ((l / 7) * 7);
	q = k - p;
	month = ((q + 40) / 44) + 3;
	day = (q + 28) - ((month / 4) * 31);

	printf("%d %d\n", month, day);
}