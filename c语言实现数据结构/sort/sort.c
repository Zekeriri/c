#include"sort.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	for (int i = 1; i< n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end>=0)
		{
			if (a[end]>tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3+1;
		for (int i = 0; i < n-gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end>=0)
			{
				if (a[end]>tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;
		for (int j = 1; j < n-i; j++)
		{
			if (a[j-1]>a[j])
			{
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				exchange = true;
			}
		}

		if (exchange==false)
		{
			break;
		}
	}
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n-1;
	while (begin<=end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[mini] > a[i])
			{
				mini = i;
			}
			if (a[maxi]<a[i])
			{
				maxi = i;
			}
		}
		Swap(&a[mini], &a[begin]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
//void HeapSort(int* a, int n)
//{
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}
int partion(int* a, int begin, int end)
{
	return begin;
}
void QuickSort(int* a, int begin, int end)
{
	////1.hoare版本
	//if (end - begin <= 1)
	//	return;
	//int left = begin;
	//int right = end-1;
	//// 按照基准值对array数组的 [left, right)区间中的元素进行划分
	//int div = partion(a, left, right);
	//while (left < right)
	//{
	//	while (left<right && a[right] >= a[div])
	//	{
	//		right--;
	//	}
	//	while (left<right && a[left] <= a[div])
	//	{
	//		left++;
	//	}
	//	Swap(&a[left], &a[right]);
	//}
	//Swap(&a[left], &a[div]);
	//div = left;
	//// 划分成功后以div为边界形成了左右两部分 [left, div) 和 [div+1, right)
	//// 递归排[left, div)
	//QuickSort(a, begin, div);
	//// 递归排[div+1, right)
	//QuickSort(a, div + 1, end);

	////2.挖坑法
	//if (end - begin <= 1)
	//	return;
	//int left = begin;
	//int right = end - 1;
	//int pivot = partion(a, begin, end);
	//while (left < right)
	//{
	//	while (left < right && a[right] >= a[pivot])
	//	{
	//		right--;
	//	}
	//	Swap(&a[right], &a[pivot]);
	//	pivot = right;

	//	while (left < right && a[left] <= a[pivot])
	//	{
	//		left++;
	//	}
	//	Swap(&a[left], &a[pivot]);
	//	pivot = left;
	//}
	////Swap(&a[left], &a[pivot]);
	//QuickSort(a, begin, pivot);
	//QuickSort(a, pivot + 1, end);

	//前后指针版本
	if (end - begin <= 1)
		return;
	int prev = begin;
	int cur = begin+1;
	int pivot = partion(a, begin, end);
	while (cur < end)
	{
		if (cur)
	}

}
void QuickSortNonR(int* a, int begin, int end);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void CountSort(int* a, int n);
