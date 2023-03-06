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