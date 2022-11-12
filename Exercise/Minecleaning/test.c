#include "game.h"

//��ӡ�˵�
void menu()
{
	printf("************************************\n");
	printf("********      1. play      *********\n");
	printf("********      0. exit      *********\n");
	printf("************************************\n");
}
//��Ϸ����
void game()
{
	//��ʼ������
	char mine[ROWS][COLS] = { 0 };//���úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//�Ų�����׵���Ϣ
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//����
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
}

//������
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	
	//ѡ�� 1. ��ʼ��Ϸ 0. �˳���Ϸ
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		menu();
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ���������������");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}