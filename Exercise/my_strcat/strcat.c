#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* my_strcat(char* destination, const char* source)
{
	char* st = destination;
	while (*destination++);
	destination--;
	while (*destination++ = *source++);
	return st;
}

int main()
{
	char str[80];
	strcpy(str, "these ");
	my_strcat(str, "strings ");
	my_strcat(str, "are ");
	my_strcat(str, "concatenated.");
	puts(str);
	return 0;
}