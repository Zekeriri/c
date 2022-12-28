#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
    int n;
    int arr[20]={0};
    while (scanf("%d", &n) != EOF) 
    { 
        int i = 0;
        while (n>0)
        {
            arr[i++] = i % 6;
            n = n / 6;
        }
        for (i--; i >= 0; i--)
        {
            printf("%d", arr[i]);
        }
        
    }
    return 0;
}
