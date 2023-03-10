#include <stdio.h>
void bubble_sort(int* arr, int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		int flag = 1;
		for (int j = sz-1; j > i; j--)
		{
			if (arr[j] > arr[j - 1]) 
			{
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
int main()
{
	int arr[10] = { 10,12,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	return 0;
}