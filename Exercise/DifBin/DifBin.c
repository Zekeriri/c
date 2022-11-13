#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void reverse(int* arr, int size);

int main()
{
	int bin1[32]={0};
	int bin2[32]={0};
	int num1 = 0;
	int num2 = 0;
	int len1 = 0;
	int len2 = 0;
	int count = 0;

	scanf("%d %d", &num1, &num2);
	while (num1 != 0)
	{
		len1++;
		bin1[len1 - 1] = num1 % 2;
		num1 = num1 / 2;
	}
	while (num2 != 0)
	{
		len2++;
		bin2[len2 - 1] = num2 % 2;
		num2 = num2 / 2;
	}
	reverse(bin1,32);
	reverse(bin2,32);
	//for (int i = 0; i < 32; i++)
	//{
	//	printf("%d ",bin1[i]);
	//}
	//printf("\n");
	//
	//for (int i = 0; i < 32; i++)
	//{
	//	printf("%d ",bin2[i]);
	//}

	for (int i = 0; i < 32; i++)
	{
		if (bin1[i] != bin2[i])
		{
			count++;
		}
	}
	printf("%d", count);
}

void reverse(int* arr, int size)
{
	int left = 0;
	int right = size - 1;
	int temp = 0;
	while (left < right)
	{
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}

}