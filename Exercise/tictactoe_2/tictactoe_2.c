#include <stdio.h>
void reverse(char* str, int start)
{
    if (str[start] == '\0') {
        return;
    }
    if (str[start] == ' ') {
        start++;
    }
    int end = start + 1;
    while (str[end] != ' ' && str[end] != '\0') {
        end++;
    }
    reverse(str, end);
    for (int i = start; i < end; i++) {
        printf("%c", str[i]);
    }
    printf(" ");
}

int main() {
    char str[100];
    gets(str);
    reverse(str, 0);
    return 0;
}