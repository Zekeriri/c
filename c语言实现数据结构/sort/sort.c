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
void HeapSort(int* a, int n);
void QuickSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void CountSort(int* a, int n);
