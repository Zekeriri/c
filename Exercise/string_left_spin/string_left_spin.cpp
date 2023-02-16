#include <stdio.h>
void left_spin(char* str, int);
void spin(char* str,int k);
int main()
{
	char str[5] = "ABCD";
	int k = 2;
	left_spin(str, k);
	printf("%s", str);
	return 0;
}
void left_spin(char* str, int k)
{
	for (int i = 0; i < k; i++)
	{
		spin(str, 4);
	}
}
void spin(char* str,int k)
{
	char temp = str[0];
	for (int i = 0; i < k-1; i++)
	{
		str[i] = str[i + 1];
	}
	str[k - 1] = temp;
}