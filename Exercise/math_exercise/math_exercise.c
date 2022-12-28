#include<stdio.h>

int main()
{
	int count = 0;
	for (int i = 100000; i < 1000000; i++)
	{
		int originalInteger = i;
		int remainder = 0;
		int reversedInteger = 0;

		// ·­×ª
		while (originalInteger != 0)
		{
			remainder = originalInteger % 10;
			reversedInteger = reversedInteger * 10 + remainder;
			originalInteger /= 10;
		}
		if (i == reversedInteger)
		{
			count++;
		}
	}
	printf("%d", count);

}