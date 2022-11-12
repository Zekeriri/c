#include "game.h"
//开始菜单
void menu()
{
	srand((unsigned int)time(NULL));
	printf("****************\n");
	printf("**** 1.play ****\n");
	printf("**** 0.exit ****\n");
	printf("****************\n");
	int input = 0;
	do
	{
		printf("请选择->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏，谢谢游玩");
			Sleep(1000);
			break;
		default:
			printf("选择错误，请重新输入");
			break;
		}
	} while (input);
}

void game()
{
	char board[ROW][COL];
	init(board,ROW,COL);
	print_board(board, ROW, COL);
	while (1)
	{
		player(board);
		print_board(board, ROW, COL);
		switch (is_win(board))
		{
		case 1:
			printf("你赢了");
			return;
		case 2:
			printf("你输了");
			return;
		case 3:
			printf("平局");
			return;
		default:
			break;
		}

		cp(board);
		print_board(board, ROW, COL);
		switch (is_win(board))
		{
		case 1:
			printf("你赢了");
		case 2:
			printf("你输了");
		case 3:
			printf("平局");
			return;
		default:
			break;
		}
	}
}

void init(char board[ROW][COL],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][COL], int row, int col)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
		
	}

}

int is_win(char board[ROW][COL])
{
	if (win(board,'O'))
	{
		return 1;
	}
	else
		if (win(board,'X'))
	{
		return 2;
	}
	
	if (full(board))
	{
		return 3;
	}
	//continue
	return 0;
}

void player(char board[ROW][COL])
{
	int x;
	int y;
	printf("玩家移动\n请输入下的坐标:\n");
	do
	{
		printf("请输入下的坐标:\n");
		scanf("%d %d", &x, &y); 
	} while (isrep(board,x,y)&&(is_legal(board,x,y)));
	board[x -1][y -1] = 'O';

}

void cp(char board[ROW][COL])
{
	int x;
	int y;
	printf("电脑下棋\n");
	do
	{
		x = rand() % ROW+1;
		y = rand() % COL+1;
	} while (isrep(board, x, y) || (is_legal(board, x, y)));
	board[x - 1][y - 1] = 'X';
}

int isrep(char board[ROW][COL], int x, int y)
{
	if (' ' == board[x-1][y-1])
	{
		return 0;
	}
	else
	{
		printf("重复，请重新输入\n");
		return 1;
	}
}

int is_legal(char board[ROW][COL], int x, int y)
{
	if (x<=3 && x>=1 &&y<=3 && y>=1)
	{
		return 0;
	}
	else
	{
		printf("坐标非法，请重新输入\n");
		return 1;
	}
}

int full(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

int win(char board[ROW][COL],char piece)
{
	for (int i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == piece)
			return 1;
	}
	for (int i = 0; i < ROW; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == piece)
			return 1;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == piece)
	{
		return 1;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == piece)
	{
		return 1;
	}
	return 0;
}