#include "heap.h"

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的初始化
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// 堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// 向上调整算法
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}	
// 向下调整算法
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n && a[child] < a[child + 1])
		{
			child = child + 1;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent*2+1;
		}
		else
		{
			break;
		}
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	CheckCapacity(hp);
	hp->_a[hp->_size] = x;
	AdjustUp(hp->_a, hp->_size);
	hp->_size++;
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	hp->_size--;
	Swap(&hp->_a[0], &hp->_a[hp->_size]);
	AdjustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
// 堆的扩容
void CheckCapacity(Heap*hp)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, newCapacity*sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		hp->_a = tmp;
		hp->_capacity = newCapacity;
	}
}