#include"sequence_list.h"

// ˳����ʼ��
void SeqListInit(SeqList* psl)
{
	assert(psl);
	psl->capacity = 4;
	psl->array = (SLDataType*)malloc(sizeof(SLDataType) * psl->capacity);
	if (psl->array == NULL)
	{
		perror("malloc fail");
		return;
	}
	psl->size = 0;
}
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->capacity == psl->size)
	{
		int newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		psl->capacity = newcapacity;
		SLDataType* tmp = (SLDataType*)realloc(psl->array,sizeof(SLDataType) * psl->capacity);
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		psl->array = tmp;
	}
}
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListInsert(psl, psl->size, x);
}
// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	SeqListErase(psl, psl->size - 1);
}
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListInsert(psl, 0, x);
}
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	SeqListErase(psl, 0);
}
// ˳������
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i <psl->size ; i++)
	{
		if (psl->array[i]==x)
		{
			return i;
		}
	}
	return -1;
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);
	CheckCapacity(psl);
	for (int i = psl->size; i >pos; i--)
	{
		psl->array[i] = psl->array[i -1];
	}
	psl->array[pos] = x;
	psl->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);
	for (int i = pos; i <psl->size-1 ; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
// ˳�������
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	free(psl->array);
	psl->array = NULL;
	psl->capacity = 0;
	psl->size = 0;
}
// ˳����ӡ
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	printf("size:%zu\n",psl->size);
	printf("capacity:%zu\n", psl->capacity);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
// ˳����޸�
void SeqListModify(SeqList* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(0 <= pos && pos < psl->size);
	psl->array[pos] = x;
}