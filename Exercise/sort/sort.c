#include"sort.h"
// ��ӡ����
void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// ��������
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
// ��������
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i;
		while (a[i] < a[k-1]&&k>0)
		{
			k--;
		}
		int temp = a[i];
		for (int j = i; j > k; j--)
		{
			a[j] = a[j - 1];
		}
		a[k] = temp;
	}
}

// ϣ������
void ShellSort(int* a, int n)
{
	for (int gap = n/2; gap > 0 ; gap/=2)
	{
		for (int i = 0; i < gap; i++)
		{
			for (int j = i+gap; j < n; j+=gap)
			{
				int k = j;
				while (a[j]<a[k-gap]&&k>=gap)
				{	
					k -= gap;
				}
				int temp = a[j];
				for (int l = j; l >k ; l-=gap)
				{
					a[l] = a[l - gap];
				}
				a[k] = temp;
			}
		}
	}
}

// ѡ������
void SelectSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[k] > a[j])
			{
				k = j;
			}
		}
		swap(&a[k], &a[i]);
	}
}

// ������
void AdjustDwon(int* a, int n, int parent)
{
	//ѡ�����Һ�����С/����Ǹ�
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int j = n-1; j >0; j--)
	{
		//�����
		for (int i = (j - 1) / 2; i >= 0; i--)
		{
			AdjustDwon(a, j+1, i);
		}
		swap(&a[0], &a[j]);
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		bool hasSwapped = false;
		for (int j = n-1; j >=i ; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(&a[j], &a[j - 1]);
				hasSwapped = true;
			}
		}
		if (!hasSwapped)
		{
			break;
		}
	}
}

// ��������ݹ�ʵ��
void QuickSort(int a[], int left, int right)
{
	//PartSort1(a, left, right);
	//PartSort2(a, left, right);
	PartSort3(a, left, right);
}
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	if (right - left <= 1)
		return;
	int start = left;
	int end = right;

	// ���ջ�׼ֵ��array����� [left, right)�����е�Ԫ�ؽ��л���
	/*int div = partion(a, left, right);*/
	int div = left;
	int key = a[div];
	while (start<end)
	{
		while (a[end] >= key && start < end)
		{
			end--;
		}
		while (a[start] <= key && start < end)
		{
			start++;
		}
		swap(&a[start], &a[end]);
	}
	div = start;
	swap(&a[left], &a[div]);
	// ���ֳɹ�����divΪ�߽��γ������������� [left, div) �� [div+1, right)
	// �ݹ���[left, div)
	PartSort1(a, left, div);

	// �ݹ���[div+1, right)
	PartSort1(a, div + 1, right);
}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	if (right - left <= 1)
		return;
	int pivot = left;
	int key = a[pivot];
	int start = left;
	int end = right;
	while (start < end)
	{
		while (a[end] >= key && start < end)
		{
			end--;
		}
		swap(&a[end], &a[pivot]);
		pivot = end;
		while (a[start] <= key && start < end)
		{
			start++;
		}
		swap(&a[start], &a[pivot]);
		pivot = start;
	}
	a[pivot] = key;
	PartSort2(a, left, pivot - 1);
	PartSort2(a, pivot + 1, right);
}
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	if (right - left < 1)
		return;
	int prev = left;
	int cur = left + 1;
	int key = left;
	while(cur <=right)
	{
		while (cur <=right&&a[cur] <=a[key])
		{
			prev++;
			cur++;
		}
		while (cur <=right && a[cur]>a[key])
		{
			cur++;
		}
		if (cur<=right)
		{
			prev++;
			swap(&a[cur], &a[prev]);
			cur++;
		}
	}
	swap(&a[key], &a[prev]);
	PartSort3(a, left, prev - 1);
	PartSort3(a, prev+1, right);
}
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int left,int right)
{
	if (right-left<1)
	{
		return;
	}
	int mid = (left + right + 1) / 2;
	MergeSort(a, left, mid-1);
	MergeSort(a, mid,right);
	int n1 = mid - left;
	int n2 = right - mid+1;
	int* L = (int*)malloc(sizeof(int) * n1);
	int* R = (int*)malloc(sizeof(int) * n2);
	memcpy(L, a+left, n1 * sizeof(int));
	memcpy(R, a+mid, n2 * sizeof(int));
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			a[left + k] = L[i];
			i++;
			k++;
		}
		else
		{
			a[left + k] = R[j];
			j++;
			k++;
		}
	}
	while (i < n1)
	{
		a[left + k] = L[i];
		i++;
		k++;
	}
	while (j<n2)
	{
		a[left + k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int* countArray = (int*)malloc(sizeof(int) * (max - min + 1));
	for (int i = 0; i <max-min+1; i++)
	{
		countArray[i] = 0;
	}
	for (int i = 0; i <n ; i++)
	{
		countArray[a[i]-min]++;
	}
	int k = 0;
	for (int i = 0; i < max-min+1; i++)
	{
		while (countArray[i])
		{
			a[k] = i + min;
			k++;
			countArray[i]--;
		}
	}
}