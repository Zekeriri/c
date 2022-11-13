#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n = 0;
    int num_2 = 0;
    int num_1 = 0;
    int sum = 0;
    scanf("%d", &n);
    num_2 = n / 2;
    num_1 = n % 1;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        int a = num_1 + num_2;
        int b = 1;
        int c = 1;
        for (int j = 1; j <= num_2; j++)
        {
            c = c * a / b;
            a--;
            b++;
        }
        sum += c;
        num_2 -= 1;
        num_1 += 2;
    }
    printf("%d", sum);
    return 0;
}