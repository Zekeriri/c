#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int step_counter(int n)
{
	if (n==1)
	{
		return 1;
	}
	if (n == 0)
	{
		return 1;
	}
	return step_counter(n - 2) + step_counter(n - 1);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", step_counter(n));
}