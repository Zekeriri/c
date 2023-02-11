#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char a1[100] = { 0 };
	char a2[100] = { 0 };
	char a3[100] = { 0 };
	gets(a1);
	gets(a2);
	for (int i = 0; i < sizeof(a1); i++)
	{
		for (int j = 0; j < sizeof(a2); j++)
		{
			if (a1[i] == a2[j])
			{
				a3[i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < sizeof(a1); i++)
	{
		if (a3[i] == 0)
		{
			printf("%c", a1[i]);
		}
	}
}