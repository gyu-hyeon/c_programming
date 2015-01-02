/********************************************************************
*
* Problem 120 :
*                IPv4 주소 변환 (IPv4 Address Conversion)
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
typedef unsigned int myint;

//////////////////////////////////  Main()  ////////////////////////////////////////
int main(void)
{
	FILE *fp;
	int no_cases, cases;
	int i, j;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // 테스트 케이스의 개수
	for (i = 0; i < no_cases; i++)
	{
		char ip[16] = { 0 }, *p[4] = { NULL }, *stop;
		myint ip_num[4] = { 0 }, sum = 0, mask = 0xFF000000;

		fscanf(fp, "%d %s", &cases, ip);

		if (cases == 1)
		{
			for (j = 0; j < 4; j++)
			{
				char ip_part[4] = { 0 };

				/* ip_num 에 ip정수값을 저장 */
				p[j] = strchr((j == 0 ? ip : p[j - 1]) + 1, (j == 3 ? '\0' : '.'));
				// . 또는 NULL 값을 가지는 주소 위치를 저장

				strncpy(ip_part, (j == 0 ? ip : p[j - 1] + 1), (j == 0 ? p[j] - ip : p[j] - p[j - 1] - 1));		
				// .사이의 있는 숫자(문자)들을 ip_num에 복사

				ip_num[j] = atoi(ip_part);
				// 정수로 변환

				sum |= ip_num[j] << 8 * (3 - j);
				// ip를 32비트 정수로 연산
			}

			printf("%u\n", sum);
		}
		else
		{
			sum = strtoul(ip, &stop, 10);
			for (j = 0; j < 4; j++)
			{
				ip_num[j] = (sum & mask) >> 8 * (3 - j);
				mask >>= 8;
				printf("%d%s", ip_num[j], (j == 3 ? "\n" : "."));
			}
		}
	}

	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////
