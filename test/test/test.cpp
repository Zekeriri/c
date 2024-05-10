#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void Test(void)
{
    char* str = (char*)malloc(100);
    strcpy(str, "hello");
    free(str);
    if (str != NULL)
    {
        strcpy(str, "world");
        printf(str);
    }
}


int main()
{
    Test();
	return 0;
}
