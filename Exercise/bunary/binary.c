#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int bin[32]={0};
	int odd[16]={0};
	int even[16]={0};
	int num = 15;
	int len = 0;
	while (num != 0)
	{
		len++;
		bin[len-1] = num % 2;
		num = num / 2;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d", bin[i]);
	}
	printf("\n");
	int index = 0;
	for (int i = 0;i<len;i++)
	{
		if (i%2==0)
		{
			odd[i / 2] = bin[len - i - 1];
		}
		else
		{
			even[i / 2] = bin[len - i - 1];
		}
	}

	if (len % 2 == 1)
	{
		printf("奇数序列：");
		for (int i = 1; i < len / 2 + 1; i++)
			printf("%d ", odd[i]);
		printf("\n");
		printf("偶数序列：");
		for (int i = 1; i < len / 2; i++)
			printf("%d ", even[i]);
		printf("\n");
	}
	else
	{
		printf("奇数序列：");
		for (int i = 0; i < len / 2; i++)
			printf("%d ", odd[i]);
		printf("\n");
		printf("偶数序列：");
		for (int i = 0; i < len / 2; i++)
			printf("%d ", even[i]);
		printf("\n");
	}
}