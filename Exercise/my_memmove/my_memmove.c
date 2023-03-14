#include <stdio.h>
#include <string.h>

void* my_memmove(void* destination, const void* source, size_t num)
{

	char* dst = (char*)destination;
	char* scr = (char*)source;
	if (dst > scr)
	{
		for (int i = num - 1; i >= 0; i--)
		{
			*(dst + i) = *(scr + i);
		}
	}
	else
	{
		for (int i = 0; i < num; i--)
		{
			*(dst + i) = *(scr + i);
		}
	}
}

int main()
{
	char str[] = "memmove can be very useful......";
	my_memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}
