#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int year, month;
    int years[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (scanf("%d %d", &year, &month) != EOF) 
    {
        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)&&month==2)
        {
            printf("29\n");
        }
        else
        {
            printf("%d\n", years[month -1]);
        }
        
    }
    return 0;
}