#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print_digit(int n);

int main04()
{
	int n = 139138;
	print_digit(n);
	return 0;
}

void print_digit(int n)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		print_digit(n / 10);
		printf("%d", n % 10);
	}
}