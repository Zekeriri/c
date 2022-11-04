#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int digitSum(int n);

int main02()
{
	printf("%d",digitSum(2345));
	return 0;
}

int digitSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return n % 10 + digitSum(n / 10);
	}
}