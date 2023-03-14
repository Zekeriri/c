/* memcpy example */
#include <stdio.h>
#include <string.h>

void* my_memcpy(void* destination, const void* source, size_t num)
{
	char* dst = (char*)destination;
	char* src = (char*)source;
	for (int i = 0; i < num; i++)
	{
		*dst++ = *src++;
	}

}

struct {
	char name[40];
	int age;
} person, person_copy;

int main()
{
	char myname[] = "Pierre de Fermat";

	/* using memcpy to copy string: */
	my_memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	/* using memcpy to copy structure: */
	my_memcpy(&person_copy, &person, sizeof(person)); void* memcpy(void* destination, const void* source, size_t num);

	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	return 0;
}