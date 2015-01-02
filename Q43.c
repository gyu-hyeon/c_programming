/********************************************************************
*                                                                  
* Problem 43 :                                                     
*           ������ ����                                            
*                                                                  
*********************************************************************/
/********************************************************************
*                                                                   
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 1�г�                   
*                                               20143053  ������   
*                                                                  
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int sequenceLength(int n); // ������ ���̸� ���ϴ� �Լ�

void main(void)
{
	FILE *fp;
	int no_cases, num;
	int i;

	fp = fopen("input.txt", "r");
	if (fp == NULL) exit(1);

	fscanf(fp, "%d", &no_cases); // �׽�Ʈ �ݺ� Ƚ�� �о����

	for (i = 0; i < no_cases; i++) // �׽�Ʈ �ݺ�
	{
		fscanf(fp, "%d", &num); // �ڿ����� �о����

		printf("%d\n", sequenceLength(num)); // num���� �����ϴ� ������ ���� ���
	}

	fclose(fp);
}

int sequenceLength(int n)
{
	int i = 1; // ������ ���̸� ��Ÿ���� ����

	while (1)
	{
		if (n != 1)
		{
			if (n % 4 == 0)
				n /= 4;

			else if (n % 2 == 0)
				n /= 2;

			else
				n = n * 3 + 1;

			i += 1; // ������ �����ϸ� i�� 1����
		}

		else
			break; // n = 1�̸� �ݺ� ����
	}

	return i;
}