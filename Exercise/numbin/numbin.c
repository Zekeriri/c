#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count_binary(int num);
int main()
{
	int a = 15;
	printf("%d",count_binary(15));
}

int count_binary(int num)
{
	int count = 0;
	while (num!= 0)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	return count;
}