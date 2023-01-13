#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int arr[56] = { 0 };
	int index = 0;
	int n = 10;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			index++;
			if (j == 1 || j == i)
			{
				arr[index] = 1;
			}
			else
			{
				arr[index] = arr[index - i] + arr[index - i + 1];
			}
			printf("%d ", arr[index]);
		}
		printf("\n");
	}
}