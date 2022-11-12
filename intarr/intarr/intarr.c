#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int swap_array(int* arr1, int* arr2, int size);


int main()
{
	int array1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int array2[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(array1) / sizeof(array1[0]);
	swap_array(array1, array2, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n");


	for (int i = 0; i < size; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
}


int swap_array(int* arr1, int* arr2, int size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}
