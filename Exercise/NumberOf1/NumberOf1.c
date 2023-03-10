#include<stdio.h>
int NumberOf1(int n) 
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (1 << i & n)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    printf("%d", NumberOf1(-1));
}