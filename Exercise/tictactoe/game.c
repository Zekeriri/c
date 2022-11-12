#include "game.h"
//��ʼ�˵�
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
		printf("��ѡ��->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��лл����");
			Sleep(1000);
			break;
		default:
			printf("ѡ���������������");
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
			printf("��Ӯ��");
			return;
		case 2:
			printf("������");
			return;
		case 3:
			printf("ƽ��");
			return;
		default:
			break;
		}

		cp(board);
		print_board(board, ROW, COL);
		switch (is_win(board))
		{
		case 1:
			printf("��Ӯ��");
		case 2:
			printf("������");
		case 3:
			printf("ƽ��");
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
	printf("����ƶ�\n�������µ�����:\n");
	do
	{
		printf("�������µ�����:\n");
		scanf("%d %d", &x, &y); 
	} while (isrep(board,x,y)&&(is_legal(board,x,y)));
	board[x -1][y -1] = 'O';

}

void cp(char board[ROW][COL])
{
	int x;
	int y;
	printf("��������\n");
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
		printf("�ظ�������������\n");
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
		printf("����Ƿ�������������\n");
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