#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("---------ɨ��----------\n");
	//�����к�
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------ɨ��----------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//1. ��������±�
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//2. ������
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		int x;
		int y;
		printf("��������Ҫ�ų������꣺\n");
		scanf("%d %d", &x, &y);
		if (x < 1 && x > row && y < 1 && y > col)
		{
			printf("����Ƿ�������������\n");
			continue;
		}
		//�ظ�
		if (show[x][y] != '*')
		{
			printf("�ظ�������������\n");
			continue;
		}
		//����
		if (mine[x][y] == '1')
		{
			printf("BOOM!!!!!!!!\n");
			DisplayBoard(mine, ROW, COL);
			return;
		}
		//û����
		if (mine[x][y] == '0')
		{
			show[x][y] = get_mine_count(mine,x,y) + '0';
			win++;
			DisplayBoard(show, ROW, COL);
		}

	}
	if (win == row * col - EASY_COUNT)
	{
		printf("�ҳ��ϣ���Ӯ��");
	}
}

int get_mine_count(char mine[ROWS][COLS],int x, int y)
{
	return (mine[x-1][y-1] + mine[x][y-1] + mine[x+1][y-1] +
		mine[x-1][y] + mine[x][y] + mine[x+1][y] +
		mine[x-1][y+1] + mine[x][y+1] + mine[x+1][y+1] - 9 * '0');
}