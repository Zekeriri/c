#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

void A(int* murder)
{
	murder[1] = 0;
}
void B(int* murder)
{
	murder[3] = 1;
}
void C(int* murder)
{
	murder[4] = 1;
}
void D(int* murder)
{
	murder[4] = 0;
}
int check(int* murder)
{
	int j = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (murder[i] == 1)
		{
			j++;
		}
	}
	if (j == 1)
	{
		return 1;
	}
	return 0;
}

void print(int* murder)
{
	for (int i = 1; i <= 4; i++)
	{
		printf("%d", murder[i]);
	}
	printf("\n");
}

int main()
{
	
	for (int i = 1; i <= 4; i++)
	{
		int murder[5] = { 0 };
		switch (i)
		{
		case 1:
			B(murder);
			C(murder);
			D(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		case 2:
			A(murder);
			C(murder);
			D(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		case 3:
			B(murder);
			A(murder);
			D(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		case 4:
			B(murder);
			C(murder);
			A(murder);
			if (check(murder))
			{
				print(murder);
			}
			break;
		default:
			break;
		}

	}
}