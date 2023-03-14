#include <stdio.h>
#include <string.h>
char* my_strcpy(char* destination, const char* source)
{
	char* cp = destination;
	while (*cp++ = *source++);
	return cp;
}

int main()
{
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	my_strcpy(str2, str1);
	my_strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}

size_t my_strlen(const char* str)
{
	char* eos = str;
	while (*eos++);
	return eos - str - 1;
}

int main()
{
	char szInput[256];
	printf("Enter a sentence: ");
	gets(szInput);
	printf("The sentence entered is %u characters long.\n", (unsigned)my_strlen(szInput));
	return 0;
}

#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */
#include <string.h>

void my_qsort(void* base, size_t num, size_t size,
    int (*compar)(const void*, const void*))
{
    char* st = (char*)base;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = num-1; j >i; j--)
        {
            if (compar(st+(j)*size, st+(j - 1))*size)
            {
                char temp[16];
                memcpy(temp, st + (j)*size, size);
                memcpy(st + (j)*size, st + (j - 1)* size, size);
                memcpy(st + (j - 1) * size, temp, size);
            }
        }
    }
}
int compare(const void* a, const void* b)
{
    if (*(char*)a - *(char*)b > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char str[] = {"attack on titan"};
    puts(str);
    my_qsort(str, sizeof(str)-1, sizeof(char), compare);
    puts(str);
    return 0;
}

#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>
int my_strcmp(const char* str1, const char* str2)
{
    while (1)
    {
        if (*str1 == *str2 && *str1 == '\0')
        {
            return 0;
        }
        else if (*str1 == '\0')
        {
            return -1;
        }
        else if (*str2 == '\0')
        {
            return 1;
        }
        if (*str1 == *str2)
        {
            str1++;
            str2++;
        }
        else 
        {
            return *str1 - *str2;
        }
    }
}


int main()
{
    char key[] = "apple";
    char buffer[80];
    do {
        printf("Guess my favorite fruit? ");
        fflush(stdout);
        scanf("%79s", buffer);
    } while (my_strcmp(key, buffer) != 0);
    puts("Correct answer!");
    return 0;
}