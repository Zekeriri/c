#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	char digitStr[100];
	gets(str);
	int count = 0;
	int num = 0;
	int len = strlen(str);
	printf("%d", len);
	for (int i = 0; i < len; i++)
		if (str[i] <= '9' && str[i] >= '0')
		{
			digitStr[count] = str[i];
			count++;
		}
	digitStr[count]='\0';
	printf("The string has %d characters that are digits: %s\n", count, digitStr);
	//reverse
	printf("The string printed in reverse is: ");
	for (int i = 0; i < count; i++)
	{
		printf("%c", digitStr[count - i - 1]);
	}
	// integer
	while (digitStr[count - 1] == '0')
	{
		count--;
	}
	for (int i = count - 1; i >= 0; i--)
		num = num * 10 + digitStr[i] - '0';
	printf("\nThe integer value is: %d\n",num);
	return 0;
}