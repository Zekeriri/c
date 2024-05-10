#include"sort.h"
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++)
		{
			for (int j = i+gap; j < n; j+=gap)
			{
				int end = j - gap;
				int tmp = a[j];
				while (end>=0)
				{
					if (a[end]>tmp)
					{
						a[j] = a[j - gap];
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
}

// 选择排序
void SelectSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		Swap(&a[i], &a[min]);
	}
}

// 堆排序
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	if (child < n && a[child] < a[child + 1]) child = child + 1;
	while (child < n && a[parent] < a[child])
	{
		Swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
		if (child < n && a[child] < a[child + 1]) child = child + 1;
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j > i; j--)
		{
			if (a[j]<a[j-1])
			{
				Swap(&a[j], &a[j - 1]);
			}
		}
	}
}

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int pivot = GetMidIndex(a, left, right - 1);
	Swap(&a[left], &a[pivot]);
	pivot = left;
	right--;
	while (left < right)
	{
		while (left < right && a[right]>=a[pivot]) right--;
		while (left < right && a[left] <= a[pivot]) left++;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[pivot], &a[right]);
	return right;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int pivot = GetMidIndex(a, left, right - 1);
	int key = a[pivot];
	right--;
	while (left < right)
	{
		while (left<right && a[right]>=key) right--;
		a[left] = a[right];
		while (left<right && a[left]<=key) left++;
		a[right] = a[left];
	}
	a[right] = key;
	return right;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int pivot = GetMidIndex(a, left, right - 1);
	Swap(&a[left], &a[pivot]);
	int prev = left;
	int cur = left + 1;
	int key = a[left];
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur) Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[prev],&a[left]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (right - left < 1) return;
	int pivot = PartSort1(a, left, right);
	//int pivot = PartSort2(a, left, right);
	//int pivot = PartSort3(a, left, right);
	QuickSort(a, left, pivot);
	QuickSort(a, pivot + 1, right);
}
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (a[begin] > a[end])
	{
		if (a[mid] > a[begin]) return begin;
		else if (a[mid] < a[end]) return end;
		else return mid;
	}
	else  //a[end]>a[begin]
	{
		if (a[mid] > a[end]) return end;
		else if (a[mid] < a[begin]) return begin;
		else return mid;
	}
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	std::stack<std::pair<int, int>> s;
	s.push(std::make_pair(left, right));
	while (!s.empty())
	{
		auto bounds = s.top();
		s.pop();
		int begin = bounds.first;
		int end = bounds.second;
		if (end - begin < 1) continue;
		int pivot = PartSort3(a, begin, end);
		s.push(std::make_pair(begin, pivot));
		s.push(std::make_pair(pivot+1, end));
	}
}

// 归并排序递归实现
void MergeSort(int* a, int left, int right)
{
	if (right - left <= 1) return;
	int mid = left + (right - left) / 2;
	MergeSort(a, left, mid);
	MergeSort(a, mid, right);
	int cur1 = left;
	int cur2 = mid;
	int cur = 0;
	int* tmp = (int*)malloc(sizeof(int) * (right - left));
	while (cur1 < mid && cur2 < right)
	{
		if (a[cur1] < a[cur2]) tmp[cur++] = a[cur1++];
		else tmp[cur++] = a[cur2++];
	}
	while (cur1 < mid) tmp[cur++] = a[cur1++];
	while (cur2 < right) tmp[cur++] = a[cur2++];
	memcpy(a + left, tmp, sizeof(int) * (right - left));
	free(tmp);
}
void Merge(int* a, int left,int mid,int right)
{
	if (right - left <= 1) return;
	int cur1 = left;
	int cur2 = mid;
	int cur = 0;
	int* tmp = (int*)malloc(sizeof(int) * (right - left));
	while (cur1 < mid && cur2 < right)
	{
		if (a[cur1] < a[cur2]) tmp[cur++] = a[cur1++];
		else tmp[cur++] = a[cur2++];
	}
	while (cur1 < mid) tmp[cur++] = a[cur1++];
	while (cur2 < right) tmp[cur++] = a[cur2++];
	memcpy(a + left, tmp, sizeof(int) * (right - left));
	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int k = 1;
	while (k < n)
	{
		int left = 0;
		int mid = left + k; 
		int right = mid + k;
		while (mid <= n)
		{
			if (right > n) right = n;
			Merge(a, left, mid,right);
			left = right;
			mid = left + k;
			right = mid + k;
		}
		k *= 2;
	}
}

// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	int* arr = (int*)calloc((max - min + 1), sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arr[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < max - min + 1; i++)
	{
		while (arr[i]--) a[j++] = i + min;
	}
}

