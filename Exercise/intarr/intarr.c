#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void init(int *arr,int size);
void print(int *arr,int size);
void reverse(int *arr,int size);
void bubble(int *arr, int size);

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, size);
	print(arr,size);

	/*reverse(arr,size);
	print(arr,size);
	init(arr, size);
	print(arr, size);*/

	return 0;
}

//ʵ�ֺ���init() ��ʼ������Ϊȫ0
void init(int *arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
void print(int *arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
//ʵ��reverse()  �����������Ԫ�ص����á�
void reverse(int *arr,int size)
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
//ʵ��ð������
void bubble(int *arr, int size)
{
	int temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}