#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int factorial_recursion(int n);
int factorial(int n);

int main07()
{
	printf("%d\n", factorial_recursion(5));
	printf("%d\n", factorial(5));
}

int factorial_recursion(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n*factorial(n - 1);
	}
}

int factorial(int n)
{
	int k = 1;
	for (int i = 1; i <= n; i++)
	{
		k *= i;
	}
	return k;
}
