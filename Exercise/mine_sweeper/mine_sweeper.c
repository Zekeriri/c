#include "mine_sweeper.h"

void print_board(int board[ROW + 2][COL + 2], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (board[i][j] == 0)
			{
				printf("¡õ");
			}
			else
			{
				printf("¡î");
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
				printf("¡õ");
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