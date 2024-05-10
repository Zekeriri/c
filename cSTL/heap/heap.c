#include"heap.h"

void swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp= *x;
	*x = *y;
	*y = tmp;
}
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_capacity = n;
	hp->_size = n;
	for (int i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	for (int i = (n-2)/2; i >=0 ; i--)
	{
		AdjustDown(hp->_a, n, i);
	}
}
// 堆的初始化
void HeapInit(Heap* hp)
{
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// 堆的销毁
void HeapDestroy(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// 向上调整算法
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0&&a[child] > a[parent])
	{
		swap(&a[child], &a[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
}
// 向下调整算法
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	if (child<n && a[child] < a[child + 1]) child = child + 1;
	while (child < n && a[parent] < a[child])
	{
		swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
		if (child<n && a[child] < a[child + 1]) child = child + 1;
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	CheckCapacity(hp);
	hp->_a[hp->_size] = x;
	AdjustUp(hp->_a, hp->_size);
	hp->_size++;
}
// 堆的删除
void HeapPop(Heap* hp)
{
	swap(&hp->_a[0], &hp->_a[hp->_size-1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
// 堆的扩容
void CheckCapacity(Heap* hp)
{
	if (hp->_capacity == hp->_size)
	{
		int newCapacity = hp->_capacity==0?4:hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a,sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("relloc fail");
			return;
		}
		hp->_capacity = newCapacity;
		hp->_a = tmp;
	}
}
// TopK
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	HeapInit(&hp);
	HeapCreate(&hp, a, k);
	for (int i = k; i < n; i++)
	{
		int tmp = a[i];
		if (a[i] < hp._a[0])
		{
			hp._a[0] = a[i];
			AdjustDown(hp._a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
}
// 堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	for (int i = n-1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		AdjustDown(a, i,0);
	}
}

