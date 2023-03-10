#include <stdio.h>
int my_strlen(char* str)
{
	/*if (*str == '\0')
	{
		return 0;
	}
	return 1 + my_strlen(str + 1);*/
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char str[10] = "abcde";
	printf("%d", my_strlen(str));
}