#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 10;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	int middle = 0;
	while (left <= right)
	{
		middle = left + (right - left) /2;
		if (key < arr[middle])
		{
			right = middle - 1;
		}
		else if(key > arr[middle])
		{
			left = middle + 1;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
	{
		printf("找到了，下标是%d", middle);
	}
	else
	{
		printf("没找到");
	}
	return 0;
}