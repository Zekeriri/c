#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void digit(double n,int i)
{
	i++;
	if (n < 10)
	{
		printf("%d", (int)n);
		if (i % 3 == 0)
		{
			putchar(',');
		}
		return;
	}
	digit(n / 10,i);
	printf("%d", (int)n % 10);
	if ((i % 3 == 0)&&(i!=3))
	{
		putchar(',');
	}
	
}

int main()
{
	double n = 0;
	while (scanf("%lf", &n) != EOF)
	{
		digit(n,2);
	}
	return 0;
}