#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contact.h"
void menu()
{
	printf("_____1.add____2.del_____");
	printf("_____3.search_4.modify__");
	printf("_____5.show___6.sort____");
	printf("_____0.exit");
}
int main()
{
	int input = 0;
	PeoInfo data[100];
	int sz;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			printf("�˳�ͨѶ¼");
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while ();
	return 0;

}