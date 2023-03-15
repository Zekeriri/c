#define _CRT_SECURE_NO_WARNINGS
#include "contact.h";
void menu()
{
	printf("________________________\n");
	printf("_____1.add____2.del_____\n");
	printf("_____3.search_4.modify__\n");
	printf("_____5.show___2.sort____\n");
	printf("_____0.exit\n");
	printf("________________________\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	int input = 0;
	Contact con;
	//init contact
	InitContact(&con);
	do
	{
		menu();
		printf("please choose:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("exit contact\n");
			break;
		default:
			printf("choose false\n");
			break;
		}
	} while (1);
}