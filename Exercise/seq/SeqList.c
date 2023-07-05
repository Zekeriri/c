#include"SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);
	psl->a = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
	if (psl->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	psl->capacity = 4;
	psl->size = 0;
}

void SLDestroy(SL* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d", psl->a[i]);
	}
}
void SLCheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		SLDatatype* tmp = (SLDatatype*)realloc(psl->a, sizeof(SLDatatype) * psl->capacity * 2);
		if (tmp == NULL)
		{
			perror("relloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity *= 2;
	}
}

void SLPushBack(SL* psl, SLDatatype x)
{
	assert(psl);
	SLInsert(psl, psl->size, x);
}

void SLPushFront(SL* psl, SLDatatype x)
{
	assert(psl);
	SLInsert(psl, 0, x);
}

void SLPopBack(SL* psl)
{
	assert(psl);
	SLErase(psl, psl->size - 1);
}

void SLPopFront(SL* psl)
{
	assert(psl);
	SLErase(psl, 0);
}

void SLInsert(SL* psl, int pos, SLDatatype x)
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		--end;
	}
	psl->a[pos] = x;
	psl->size++;
}

void SLErase(SL* psl, int pos)
{
	assert(psl);
	assert(0 <= pos && pos < psl->size);
	int start = pos + 1;
	while (start<psl->size)
	{
		psl->a[start - 1] = psl->a[start];
		++start;
	}
	psl->size--;
}
int SLFind(SL* psl, SLDatatype x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return -1;
		}
	}
}

void SLModify(SL* psl, int pos, SLDatatype x)
{
	assert(psl);
	assert(0 <= pos && pos < psl->size);
	psl->a[pos] = x;
}