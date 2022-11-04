#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int kth_power(int n, int k);

int main01()
{
	printf("%d\n",kth_power(2, 3));
}

int kth_power(int n,int k)
{
	if (k == 1)
	{
		return n;
	}
	else
	{
		return n * kth_power(n, k-1);
	}
}