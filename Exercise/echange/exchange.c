#include <stdio.h>
int main()
{
	int a = 2;
	int b = 3;
	int c = a ^ b;
	a = a ^ c;
	b = b ^ c;
	return 0;
}