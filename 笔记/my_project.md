## 三子棋

```c
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void p(int board[][3]);
void print_board(int board[][3]);
void cp(int board[][3]);
int is_win(int board[][3]);
void game();
void menu();
int main()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		menu();
		int input = -1;
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("exit\n");
			return 0;
		case 1:
			game();
			break;
		default:
			printf("Please re-select\n");
			break;
		}
	}
}
void menu()
{
	printf("-----0.exit-----\n");
	printf("-----1.play-----\n");
}
void game()
{
	int board[3][3] = { 0 };
	print_board(board);
	while (1)
	{
		int win = 0;
		cp(board);
		print_board(board);
		if (is_win(board))
		{
			printf("Defeat");
			return;
		}
		p(board);
		print_board(board);
		if (is_win(board))
		{
			printf("Win");
			return;
		}
	}

}
void print_board(int board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("\n");
		for (int j = 0; j < 3; j++)
		{
			switch (board[i][j])
			{
			case 0:
				printf("   ");
				break;
			case 1:
				printf(" O ");
				break;
			case -1:
				printf(" X ");
				break;
			}
		}
		printf("\n");
	}
}
void cp(int board[][3])
{
	while (1)
	{
		int x = rand() % 3 + 1;
		int y = rand() % 3 + 1;
		if (!is_repeated(board, x, y))
		{
			board[x - 1][y - 1] = -1;
			break;
		}
	}
}
void p(int board[][3])
{
	printf("Please enter X Y\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if ((!is_repeated(board, x, y)) && x <= 3 && y <= 3 && x >= 1 && y >= 1)
		{
			board[x - 1][y - 1] = 1;
			break;
		}
		printf("Please re-enter!");
	}
}
int is_repeated(int board[][3], int x, int y)
{
	if (board[x - 1][y - 1] == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int is_win(int board[][3])
{
	//横
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
		{
			return board[i][0];
		}
	}
	//竖
	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0)
		{
			return board[0][j];
		}
	}
	//斜
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
	{
		return board[0][0];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != 0)
	{
		return board[1][1];
	}
	return 0;
}
```



## 扫雷

mine_sweeper.h

```c
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 10
#define COL 10
#define NUMS 10

void print_board(int board[ROW + 2][COL + 2],int row,int col);
void initialize_board(int board[ROW + 2][COL + 2], int row, int col);
void print_game_board(int board[ROW + 2][COL + 2], int game_board[ROW + 2][COL + 2], int row, int col);
```

mine.sweeper.c

```c
#include "mine_sweeper.h"

void print_board(int board[ROW + 2][COL + 2], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (board[i][j] == 0)
			{
				printf("□");
			}
			else
			{
				printf("☆");
			}
		}
		printf("\n");
	}
}

void initialize_board(int board[ROW + 2][COL + 2], int row, int col)
{
	for (int i = 1; i <= NUMS; i++)
	{
		while (1)
		{
			int r = rand() % row + 1;
			int c = rand() % col + 1;
			if (board[r][c] == 0)
			{
				board[r][c] = 1;
				break;
			}

		}
	}
}

void print_game_board(int board[ROW + 2][COL + 2], int game_board[ROW + 2][COL + 2], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (game_board[i][j] == 0)
			{
				printf("□");
			}
			else if(board[i][j]==1)
			{
				printf("game over\n");
			}
			else
			{
				printf(" %d", board[i-1][j-1] + board[i-1][j] + board[i-1][j+1] + board[i][j-1] + board[i][j+1] + board[i+1][j-1] + board[i+1][j] + board[i+1][j+1]);
			}
		}
		printf("\n");
	}
}
```

test.c

```c
#include "mine_sweeper.h"
void menu();
void game();

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("Please enter:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("exit\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("Input error, please re-enter\n");
			break;
		}
	} while (input);

}

void menu()
{
	printf("-----0.exit-----\n");
	printf("-----1.play-----\n");
}

void game()
{
	int x = 0;
	int y = 0;
	int board[ROW + 2][COL + 2] = { 0 };
	int game_board[ROW + 2][COL + 2] = { 0 };
	int row = ROW;
	int col = COL;
	initialize_board(board, row, col);
	print_board(board,row,col);
	print_game_board(board, game_board, row, col);
	while (1)
	{
		scanf("%d %d", &x,&y);
		game_board[x][y] = 1;
		print_game_board(board, game_board, row, col);
	}
}
```

