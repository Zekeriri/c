#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
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