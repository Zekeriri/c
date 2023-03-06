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
	//ºá
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
		{
			return board[i][0];
		}
	}
	//Êú
	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0)
		{
			return board[0][j];
		}
	}
	//Ð±
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