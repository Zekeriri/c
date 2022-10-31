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
		//打印菜单
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//game函数中是猜数字的整个路基逻辑
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
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
	//1. 生成随机数
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	//2. 猜数字

	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &num);
		if (num < ret)
		{
			printf("猜小了\n");
		}
		else if (num > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
