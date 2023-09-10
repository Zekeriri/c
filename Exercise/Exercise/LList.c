#include<stdio.h>
#include<stdlib.h>


int main()
{
    int money = 0;
    for (int i = 0; i < 7; i++)
    {
        money = (100000 + money) * 1.05;
    }
    printf("%d", money);
    return 0;
}