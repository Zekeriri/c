#include "game.h"

//打印菜单
void menu()
{
	printf("************************************\n");
	printf("********      1. play      *********\n");
	printf("********      0. exit      *********\n");
	printf("************************************\n");
}
//游戏流程
void game()
{
	//初始化棋盘
	char mine[ROWS][COLS] = { 0 };//布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//排查出的雷的信息
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//埋雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}

//主流程
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	
	//选择 1. 开始游戏 0. 退出游戏
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		menu();
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新输入");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}