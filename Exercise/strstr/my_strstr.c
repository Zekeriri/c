#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char* my_strstr(char* str1, const char* str2)
{
    int size = strlen(str2);
    while (*str1)
    {
        if (strncmp(str1, str2, size) == 0)
        {
            return str1;
        }
        str1++;
    }
    return NULL;
}
int main()
{
    char str[] = "This is a simple string";
    char* pch;
    pch = my_strstr(str, "simple");
    if (pch != NULL)
        strncpy(pch, "sample", 6);
    puts(str);
    return 0;
}

