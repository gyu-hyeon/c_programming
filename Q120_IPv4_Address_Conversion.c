/********************************************************************
*
* Problem 120 :
*                IPv4 �ּ� ��ȯ (IPv4 Address Conversion)
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

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ ���̽��� ����
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

				/* ip_num �� ip�������� ���� */
				p[j] = strchr((j == 0 ? ip : p[j - 1]) + 1, (j == 3 ? '\0' : '.'));
				// . �Ǵ� NULL ���� ������ �ּ� ��ġ�� ����

				strncpy(ip_part, (j == 0 ? ip : p[j - 1] + 1), (j == 0 ? p[j] - ip : p[j] - p[j - 1] - 1));		
				// .������ �ִ� ����(����)���� ip_num�� ����

				ip_num[j] = atoi(ip_part);
				// ������ ��ȯ

				sum |= ip_num[j] << 8 * (3 - j);
				// ip�� 32��Ʈ ������ ����
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
