#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void menu();
void game();
int main()
{
	srand((unsigned)time(NULL));
	menu();
	int input = 1;
	while(input)
	{
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			game();
			break;
		default:
			printf("Please re-enter your choice\n");
			break;
		}
	}
	printf("Exit");
	return 0;
}
void menu()
{
	printf("-----0.exit-----\n");
	printf("-----1.play-----\n");
}
void game()
{
	printf("Generate random number...\n");
	int num = rand()%100;
	
	int input = 0;
while (1)
		{
		printf("Please enter the number your guessed\n");
		do
		{
			scanf("%d", &input);
			if (input < 0 || input >= 100)
			{
				printf("Please re-enter the number your guessed\n");
			}
		} while (input < 0 || input >= 100);

		
			if (input > num)
			{
				printf("too big\n");
			}
			else if (input < num)
			{
				printf("too small\n");
			}
			else
			{
				printf("bingo\n");
				break;
			}
		}

}