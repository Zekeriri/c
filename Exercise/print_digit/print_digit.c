#include <stdio.h>
void print_digit(int num)
{
	if (num == 0)
	{
		return;
	}
	print_digit(num / 10);
	printf("%d", num % 10);
}
int main()
{
	int num = 9876;
	print_digit(num);
}