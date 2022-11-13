#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col);

//打印棋盘
void print_board(char board[ROW][COL], int row, int col);

//玩家下棋
void player_move(char board[ROW][COL], int row, int col);

//电脑下棋
void computer_move(char board[ROW][COL], int row, int col);

//判断输赢的函数
char is_win(char board[ROW][COL], int row, int col);

//游戏开始
void start();

//游戏过程
void game();

//打印菜单
void menu();



int main()
{
	start();
	return 0;
}



void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			//printf("---|---|---\n");
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	printf("Player Round\n");
	while (1)
	{
		printf("Please enter the number to be played:>");
		int x = 0;
		int y = 0;
		int input = -1;
		scanf("%d", &input);
		//转化为坐标
		switch (input)
		{
		case 1:
			x = 1;
			y = 1;
			break;
		case 2:
			x = 1;
			y = 2;
			break;
		case 3:
			x = 1;
			y = 3;
			break;
		case 4:
			x = 2;
			y = 1;
			break;
		case 5:
			x = 2;
			y = 2;
			break;
		case 6:
			x = 2;
			y = 3;
			break;
		case 7:
			x = 3;
			y = 1;
			break;
		case 8:
			x = 3;
			y = 2;
			break;
		case 9:
			x = 3;
			y = 3;
			break;
		default:
			x = -1;
			y = -1;
			break;
		}
		//坐标合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("This coordinate is occupied, please re-enter\n");
			}
		}
		else//坐标非法
		{
			printf("Coordinate illegal\n");
		}
	}
}

//电脑下棋
//随机生成坐标，只要坐标没有被占用，就下棋
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("Computer Round:\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
}

//判断棋盘是否满了
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//判断输赢
//判断输赢的代码要告诉我：电脑赢了？玩家赢了？玩家赢？游戏继续？
//电脑赢:#
//玩家赢:*
//平局：Q
//游戏继续：C
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//判断三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//平局？
	if (is_full(board, row, col) == 1)
	{
		return 'Q';
	}

	//继续
	//没有玩家或者电脑赢，也没有平局，游戏继续
	return 'C';
}

//打印菜单
void menu()
{
	printf(" 1 | 2 | 3\n");
	printf("---|---|---\n");
	printf(" 4 | 5 | 6\n");
	printf("---|---|---\n");
	printf(" 7 | 8 | 9 \n\n");
	printf("**   The game is afoot！   **\n");
	printf("**         Y. play         **\n");
	printf("**         N. eixt         **\n");
	printf("** Please input 'Y' or 'N' **\n");
}

//游戏内容
void game()
{
	//存放玩家或者电脑的落子情况
	char board[ROW][COL];
	char ret = 0;
	//初始化一下棋盘为全空格
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);

	//选择先后手
	printf("Please select to go first or second?\n");
	printf("            1. first                \n");
	printf("            2. second               \n");

	int input = 0;
	while (1)
	{
		printf("Please select:>");
		scanf("%d", &input);
		if ((input == 1 || input == 2))
		{
			break;
		}
		else
		{
			printf("Wrong input, please reselect\n");
		}
	}

	if (input == 1)
	{//先手
		while (1)
		{
			player_move(board, ROW, COL);
			print_board(board, ROW, COL);
			//判断输赢
			ret = is_win(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
			computer_move(board, ROW, COL);
			print_board(board, ROW, COL);
			//判断输赢
			ret = is_win(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
		}
		if (ret == 'X')
			printf("You lose\n\n\n");
		else if (ret == 'O')
			printf("You win\n\n\n");
		else if (ret == 'Q')
			printf("Tie\n\n\n");
	}
	else
	{//后手
		{
			while (1)
			{
				computer_move(board, ROW, COL);
				print_board(board, ROW, COL);
				//判断输赢
				ret = is_win(board, ROW, COL);
				if (ret != 'C')
				{
					break;
				}
				player_move(board, ROW, COL);
				print_board(board, ROW, COL);
				//判断输赢
				ret = is_win(board, ROW, COL);
				if (ret != 'C')
				{
					break;
				}
			}
			if (ret == 'X')
				printf("You lose\n\n\n");
			else if (ret == 'O')
				printf("You win\n\n\n");
			else if (ret == 'Q')
				printf("Tie\n\n\n");
		}
	}

}

//游戏开始
void start()
{
	srand((unsigned int)time(NULL));
	char YNinput=' '; //玩家输入的 Y or N
	int input = -1;
	do
	{
		menu();
		printf("Please select:>");
		fflush(stdin);//清空缓冲区
		YNinput=getchar();

		if (YNinput == 'Y' || YNinput == 'y')
		{
			input = 1;
		}
		else 
		if (YNinput == 'N' || YNinput == 'n')
		{
			input = 0;
		}
		else
		{
			input = -1;
		}

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit the game\n");
			break;
		default:
			printf("\nWrong input, please reselect\n\n");
			break;
		}
	} while (input);
}

