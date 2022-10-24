#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void max(int,int);
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    max(a, b);
}
void max(int x, int y)
{
    if (x > y)
        printf("%d", x);
    else
        printf("%d", y);
}