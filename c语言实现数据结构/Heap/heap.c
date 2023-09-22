#include "heap.h"

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (hp->_a == NULL)
	{
		perror("malloc fail");
		return;
	}
	hp->_capacity = n;
	hp->_size = n;

	for (int i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}

	for (int i = (n-1-1)/2; i >=0 ; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
// �ѵĳ�ʼ��
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// �ѵ�����
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
// ���ϵ����㷨
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
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
// ���µ����㷨
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n && a[child] > a[child + 1])
		{
			child = child + 1;
		}
		if (a[parent] > a[child])
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
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	CheckCapacity(hp);
	hp->_a[hp->_size] = x;
	AdjustUp(hp->_a, hp->_size);
	hp->_size++;
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	hp->_size--;
	Swap(&hp->_a[0], &hp->_a[hp->_size]);
	AdjustDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
// �ѵ�����
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
// TopK
void PrintTopK(int* a, int n, int k)
{
	// 1. ����--��a��ǰk��Ԫ�ؽ���
	Heap hp1;
	HeapInit(&hp1);
	HeapCreate(&hp1, a, k);
	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ������������滻
	for (int i = k; i < n; i++)
	{
		if (a[i] > hp1._a[0])
		{
			hp1._a[0] = a[i];
		}
		AdjustDown(hp1._a, k, 0);
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", hp1._a[i]);
	}
	printf("\n");
}
// ������
void HeapSort(int* a, int n)
{
	for (int i = (n-1-1)/2; i >=0 ; i--)
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