#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void recursion(char* arr);
void reverse_string(char* arr);
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	recursion(arr);
	printf("%s",arr);
	return 0;
}

void recursion(char* arr)
{
	char* left = arr;
	char* right = arr + strlen(arr) - 1;
	char temp = *left;
	*left = *right;
	*right = '\0';
	if (strlen(arr+1) >= 2)
	{
		recursion(arr+1);
	}
	*right = temp;
}
void reverse_string(char* arr)
{
	char* left = arr;
	char* right = arr + strlen(arr) - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}