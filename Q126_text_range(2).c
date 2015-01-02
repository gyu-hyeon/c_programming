/********************************************************************
*
* Problem 126 :
*                텍스트 맞춤 - 가운데 / 양끝 맞춤
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


int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	int no_cases; 
	int i, j;

	fscanf(fp, "%d", &no_cases);
	for (i = 0; i < no_cases; i++)
	{
		char *word[2010] = { NULL };
		char buf_word[55] = { 0 };
		int count = 0, size, num, last;
		int L, R, MID;
		int cnt_word = 0;

		fscanf(fp, "%d", &size);


		// 문자열들 @@.. 까지 스캔
		while (1)
		{
			fscanf(fp, "%s", buf_word);

			if (strcmp(buf_word, "@@@@@@") == 0) 
				break;

			word[count] = (char*)malloc(sizeof(char)*strlen(buf_word) + 1);
			strcpy(word[count++], buf_word);
		}

		// 가운데 정렬
		do
		{
			int cnt = 0, word_sum = 0;

			while (cnt_word != count && cnt - 1 + word_sum < size)
			{
				word_sum += strlen(word[cnt_word++]);
				cnt++;
			}

			if (cnt_word != count && cnt - 1 + word_sum > size)
			{
				word_sum -= strlen(word[--cnt_word]);
				cnt--;
			}

			if (cnt_word == count && cnt - 1 + word_sum > size)
			{
				word_sum -= strlen(word[--cnt_word]);
				cnt--;
			}

			for (L = 0; L < (size - word_sum - cnt + 1) / 2; L++)
			{
				printf("_");
			}

			for (MID = cnt_word - cnt; MID < cnt_word; MID++)
			{
				printf("%s%s", word[MID], (MID == cnt_word - 1)?"":"_");
			}

			for (R = 0; R < (size - word_sum - cnt + 1) / 2 + (size - word_sum - cnt + 1) % 2; R++)
			{
				printf("_");
			}

			printf("\n");
		} while (word[cnt_word] != NULL);
		
		cnt_word = last = 0;
	
		// 양끝 정렬
		do
		{
			int cnt = 0, word_sum = 0, cnt_space = 0, *space = NULL;

			while (cnt_word != count && cnt - 1 + word_sum < size)
			{
				word_sum += strlen(word[cnt_word++]);
				cnt++;
			}

			if (cnt_word != count && cnt - 1 + word_sum > size)
			{
				word_sum -= strlen(word[--cnt_word]);
				cnt--;
			}

			if (cnt_word == count && cnt - 1 + word_sum > size)
			{
				word_sum -= strlen(word[--cnt_word]);
				cnt--;
			}

			if (cnt_word == count && cnt - 1 + word_sum < size)
			{
				last++;
			}

			cnt_space = size - word_sum;

			if (cnt != 1)
			{
				space = (int*)malloc(sizeof(int)* (cnt - 1));
				num = cnt_space / (cnt - 1);
				
				for (j = 0; j < cnt - 1; j++)
				{
					*(space + j) = num;
				}

				for (j = 0; j < cnt_space % (cnt - 1); j++)
				{
					*(space + cnt - 2 - j) += 1;
				}
			}


			if (last == 0)
			{
				num = 0;
				for (MID = cnt_word - cnt; MID < cnt_word; MID++)
				{
					printf("%s", word[MID]);

					if (MID == cnt_word - 1 && cnt == 1 && cnt_word != count)
					{
						// size 까지 언더바 출력
						for (j = 0; j < cnt_space; j++)
						{
							printf("_");
						}
					}
					else
					{
						if (cnt == 1)
						{
							if (cnt_word == count);
							else
							{
								// size 까지 언더바 출력
								for (j = 0; j < cnt_space; j++)
								{
									printf("_");
								}
							}
						}

						else
						{
							// 언더바 출력
							for (j = 0; j < *(space + num); j++)
							{
								printf("_");
							}
							num++;
						}
					}
				}
			}

			else
			{
				for (MID = cnt_word - cnt; MID < cnt_word; MID++)
				{
					printf("%s%s", word[MID], (MID == cnt_word - 1) ? "" : "_");
				}
			}

			if (cnt != 1)
			{
				free(space);
			}

			printf("\n");
		} while (word[cnt_word] != NULL);

		for (j = 0; j < count; j++)
		{
			free(word[j]);
		}
	}

	fclose(fp);
}
