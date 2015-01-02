/********************************************************************
*
* Problem 150 :
*                축구팀 순위
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
	char name[33];
	int win, draw, lose;
	int score;
} MST;

MST *sts[100] = { NULL };

///////////////////////////// Function List ///////////////////////////////////
MST **readTeam(FILE *fp, MST **st, int no_team);
MST **sortTeam(MST **st, int no_team);
int compare(MST *a, MST *b);
void printRank(MST **st, int no_team);
void freeTeams(MST **st, int no_team);
///////////////////////////////////////////////////////////////////////////////




/////////////////////////////// Main () ///////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		MST **st = NULL;
		int no_team;

		fscanf(fp, "%d", &no_team);

		st = readTeam(fp, st, no_team);
		st = sortTeam(st, no_team);
		printRank(st, no_team);
		freeTeams(st, no_team);
	}

	fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////

MST **readTeam(FILE *fp, MST **st, int no_team)
{
	MST *team = { NULL }, smp_team = { NULL };
	int i;

	st = (MST**)malloc(sizeof(MST*)* no_team);

	for (i = 0; i < no_team; i++)
	{
		team = (MST*)malloc(sizeof(MST));
		fscanf(fp, "%s %d %d %d", smp_team.name, &(smp_team.win), &(smp_team.draw), &(smp_team.lose));

		strcpy(team->name, smp_team.name);
		team->win = smp_team.win;
		team->draw = smp_team.draw;
		team->lose = smp_team.lose;
		team->score = smp_team.win * 2 + smp_team.draw;

		sts[i] = team;
	}

	st = sts;

	return st;
}

/*
MST **readTeam(FILE *fp, MST **st, int no_team)
{
	MST *sts[100] = { NULL }, team[100] = { NULL }, *smp_team = { NULL };
	int i;

	st = (MST**)malloc(sizeof(MST*)* no_team);

	for (i = 0; i < no_team; i++)
	{
		smp_team = (MST*)malloc(sizeof(MST));
		
		fscanf(fp, "%s %d %d %d", smp_team->name, &(smp_team->win), &(smp_team->draw), &(smp_team->lose));

		strcpy(team[i].name, smp_team->name);
		team[i].win = smp_team->win;
		team[i].draw = smp_team->draw;
		team[i].lose = smp_team->lose;
		team[i].score = smp_team->win * 2 + smp_team->draw;

		sts[i] = &team[i];
	}

	st = sts;

	return st;
}
*/

/*
MST **readTeam(FILE *fp, MST **st, int no_team)
{
	MST *smp_team = { NULL };
	int i;

	st = (MST**)malloc(sizeof(MST*)* no_team);

	for (i = 0; i < no_team; i++)
	{
		smp_team = (MST*)malloc(sizeof(MST));

		fscanf(fp, "%s %d %d %d", smp_team->name, &(smp_team->win), &(smp_team->draw), &(smp_team->lose));

		smp_team->score = smp_team->win * 2 + smp_team->draw;
		st[i] = smp_team;
	}

	return st;
}
*/

MST **sortTeam(MST **st, int no_team)
{
	qsort(st, no_team, sizeof(MST*), compare);

	return st;
}

int compare(MST *a, MST *b)
{
	return a->score - b->score;
}

void printRank(MST **st, int no_team)
{
	int i;

	for (i = 0; i < no_team; i++)
	{
		printf("%d\n", st[i]->score);
	}

	printf("\n"); // delete please... just check case end.
}

void freeTeams(MST **st, int no_team)
{
	int i;

	for (i = 0; i < no_team; i++)
	{
		free(sts[i]);
	}

	free(st);
}