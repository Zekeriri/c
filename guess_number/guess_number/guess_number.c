#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void menu();
void game();

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//game�������ǲ����ֵ�����·���߼�
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}

void menu()
{
	printf("|------------------------|\n");
	printf("|         1. play        |\n");
	printf("|         0. exit        |\n");
	printf("|------------------------|\n");
}

void game()
{
	int num = 0;
	//1. ���������
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	//2. ������

	while (1)
	{
		printf("�������:>");
		scanf("%d", &num);
		if (num < ret)
		{
			printf("��С��\n");
		}
		else if (num > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
