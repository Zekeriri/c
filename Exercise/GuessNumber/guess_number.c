#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
int check(char* rank, char name, int r);
int is_repeat(char* rank, char name);
int main()
{
	for (int a = 1; a <= 2; a++)
	{
		char rank[7] = "      ";
		if (a == 1)
		{
			check(rank, 'B', 2);
		}
		else
		{
			check(rank, 'A', 3);
		}
		for (int b = 1; b <= 2; b++)
		{
			if (b == 1)
			{
				check(rank, 'B', 2);
			}
			else
			{
				check(rank, 'E', 4);
			}
			for (int c = 1; c <= 2; c++)
			{
				if (c == 1)
				{
					check(rank, 'C', 1);
				}
				else
				{
					check(rank, 'D', 2);
				}
				for (int d = 1; d <= 2; d++)
				{
					if (d == 1)
					{
						check(rank, 'C', 5);
					}
					else
					{
						check(rank, 'D', 1);
					}
					for (int e = 1; e <= 2; e++)
					{
						if (e == 1)
						{
							check(rank, 'E', 4);
						}
						else
						{
							check(rank, 'A', 1);
						}
						int j = 0;
						for (int i = 1; i <= 5; i++)
						{
							if (rank[i]!= ' ')
							{
								j++;
							}
						}
						if (j == 4)
						{
							for (int i = 1; i <= 5; i++)
							{
								printf("%c", rank[i]);
							}
							printf("\n");
						}
					}
				}
			}
		}
	}

}

int check(char* rank, char name, int r)
{
	if (is_repeat(rank,name) || (rank[r] == name))
	{
		rank[r] = name;
		return 1;
	}
	else
	{
		return 0;
	}
}

int is_repeat(char* rank, char name)
{
	for (int i = 0; i <= 5; i++)
	{
		if (rank[i] == name)
		{
			return 0;
		}
	}
	return 1;
}