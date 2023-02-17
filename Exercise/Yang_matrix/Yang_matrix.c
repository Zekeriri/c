#include <stdio.h>

int findnum(int a[][3], int x, int y, int f) //第一个参数的类型需要调整
{
	int i = 0, j = y - 1; //从右上角开始遍历
	while (j >= 0 && i < x)
	{
		if (a[i][j] < f) //比我大就向下
		{
			i++;
		}
		else if (a[i][j] > f) //比我小就向左
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int a[][3] = { {1, 3, 5},
				  {3, 5, 7},
				  {5, 7, 9} }; //一个示例

	if (findnum(a, 3, 3, 2))
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}

	return 0;
}