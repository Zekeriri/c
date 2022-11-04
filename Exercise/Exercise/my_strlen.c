#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int my_strlen_recursive(char* str);
int my_strlen(char* str);

int main03()
{
	char str[20] = "Attack on Titan";
	printf("%s\n", str);
	printf("%d\n", my_strlen(str));
	printf("%d\n", my_strlen_recursive(str));
	
	return 0;
}

int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}

int my_strlen_recursive(char* str)
{
	if ((*str) == '\0')
	{
		return 0;
	}
	else
	{
		str++;
		return 1 + my_strlen(str);
	}

}