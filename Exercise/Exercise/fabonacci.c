#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int fibonacci_recursion(int n);
int fibonacci(int n);

int main05()
{
	printf("%d\n", fibonacci(10));
	printf("%d\n", fibonacci_recursion(10));
	return 0;
}

int fibonacci_recursion(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int c;
	for (int i = 2; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}



