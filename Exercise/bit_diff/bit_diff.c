#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((a>>i&1)!=(b>>i&1))
        {
            count++;
        }
    }
    printf("%d", count);
}