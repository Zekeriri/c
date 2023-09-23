#include"sort.h"
#include"stack.h"

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
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // begin >= mid
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}
//1.hoare�汾
int PartSort1(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int left = begin;
	int right = end - 1;
	/*
	����Ҫ���ұ��ߣ����������ߣ�
	�������һ��������Ҳ�������
	��׼ֵ�ģ��ᵼ��left == right
	�������������ұ߻�û���ߣ�����
	�����ֵһ�����ڻ�׼ֵ����󽻻�
	�ͻ�����⣬����һ��Ҫ���ұ��ߣ�
	��ʹ���һ���Ҳ���С�ڻ�׼ֵ�ģ�
	����������������ߴ�ʱ��û�ߣ�
	һ���Ȼ�׼ֵС����󽻻��϶�û������
	*/
	while (left < right)
	{
		while (left < right && a[right] >= key)
			right--;

		while (left < right && a[left] <= key)
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[begin], &a[left]);
	return left;
}
//2.�ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int left = begin;
	int right = end - 1;
	int key = a[begin];
	while (left < right)
	{
		while (left < right && a[right] >= key)
			right--;

		a[left] = a[right];

		while (left < right && a[left] <= key)
			left++;

		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
//3.ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;

	while (cur < end)
	{
		// cur��С����С����ǰ�����������
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		++cur;
	}

	Swap(&a[begin], &a[prev]);

	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (end-begin<=1)
		return;

	if (end-begin < 10)
	{
		InsertSort(a + begin, end -begin);
	}
	else
	{
		int pivot = PartSort2(a, begin, end);
		QuickSort(a, begin, pivot);
		QuickSort(a, pivot + 1, end);
	}
}
void QuickSortNonR(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	Stack st;
	StackInit(&st, 10);
	//���������
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}
	//ջ��Ϊ�գ�˵������û���������
	while (!StackEmpty(&st))
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		//���ŵ�������
		int div = PartSort3(a, left, right);

		// �Ѵ���1���������������ջ
		if (left < div)
		{
			StackPush(&st, div);
			StackPush(&st, left);
		}

		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}
}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + ((right - left) >> 2);
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	int l1 = left;
	int r1 = mid;
	int l2 = mid + 1;
	int r2 = right;
	int i = 0;
	while (l1 <= r1 && l2 <= r2)
	{
		if (a[l1] < a[l2])
		{
			tmp[i] = a[l1];
			l1++;
		}
		else
		{
			tmp[i] = a[l2];
			l2++;
		}
		i++;
	}
	while (l1 <= r1)
	{
		tmp[i] = a[l1++];
		i++;
	}
	while (l2 <= r2)
	{
		tmp[i] = a[l2++];
		i++;
	}
	memcpy(a + left, tmp, sizeof(int) * (right - left + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void Merge(int* a, int left, int mid, int right, int* tmp)
{
	int l1 = left;
	int r1 = mid;
	int l2 = mid+1 ;
	int r2 = right;
	int i = 0;
	while (l1 <= r1 && l2 <= r2)
	{
		if (a[l1] < a[l2])
		{
			tmp[i] = a[l1];
			l1++;
		}
		else
		{
			tmp[i] = a[l2];
			l2++;
		}
		i++;
	}
	while (l1 <= r1)
	{
		tmp[i] = a[l1++];
		i++;
	}
	while (l2 <= r2)
	{
		tmp[i] = a[l2++];
		i++;
	}
	memcpy(a + left, tmp, sizeof(int) * (right - left + 1));
}
void MergeSortNonR(int* a, int n)
{
	int k = 1;
	int* tmp = (int*)malloc(sizeof(int) * n);
	while (k < n)
	{
		int i = 0;
		while (i+k-1 < n)
		{
			int left = i;
			int mid = i + k-1;
			int right = mid + k;
			if (right >=n)
			{
				right = n - 1;
			}
			Merge(a, left, mid, right, tmp);
			i += k;
		}
		k *= 2;
	}
	free(tmp);
}
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}
	//�ҵ����ݵķ�Χ
	int range = max - min + 1;
	int* countArray = (int*)malloc(range * sizeof(int));
	memset(countArray, 0, sizeof(int) * range);
	//��������λ�ã����Խ�ʡ�ռ�
	for (int i = 0; i < n; ++i)
	{
		countArray[a[i] - min]++;
	}
	//���ܴ����ظ������ݣ��м����漸��
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArray[i]--)
		{
			a[index++] = i + min;
		}
	}
}