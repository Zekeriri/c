#include "SeqList.h";
static void check_capacity(SeqList* ps)
{
	if (ps->capacity == ps->size)
	{
		SLDateType* ptr = (SLDateType*)realloc(ps->a, ps->capacity * MUL_SIZE * sizeof(SLDateType));
		if (ptr == NULL)
		{
			perror("check_capacity::relloc");
		}
		ps->capacity *= MUL_SIZE;
		printf("increase successful\n");
	}
}

void SeqListInit(SeqList* ps)
{
	ps->size = 0;
	ps->capacity = DEFAULT_SIZE;
	SLDateType* ptr = (SLDateType*)calloc(DEFAULT_SIZE, sizeof(SLDateType));
	if (ptr == NULL)
	{
		perror("SeqListInit::calloc");
		return;
	}
	ps->a = ptr;
}

void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps = NULL;
}

void SeqListPrint(const SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf(print_SLDateType, ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	check_capacity(ps);
	ps->a[ps->size]=x;
	ps->size += 1;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	check_capacity(ps);
	memmove(ps->a + 1, ps->a, sizeof(SLDateType) * (ps->size));
	ps->a[0]=x;
	ps->size += 1;
}

void SeqListPopFront(SeqList* ps)
{
	printf("delete front\n");
	memmove(ps->a, ps->a + 1, sizeof(SLDateType) * (ps->size));
	ps->size -= 1;
}

void SeqListPopBack(SeqList* ps)
{
	printf("delete back\n");
	ps->size -= 1;
}


int SeqListFind(const SeqList* ps, SLDateType x)
{
	SLDateType input = x;

	for (SLDateType i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == input)
		{
			printf("找到了，下标是%d\n", i);
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	check_capacity(ps);
	int input = 0;
	input = x;
	memmove(ps->a + pos+1, ps->a+pos, sizeof(SLDateType) * (ps->size-pos));
	ps->a[pos] = input;
	ps->size += 1;
}

void SeqListErase(SeqList* ps, int pos)
{
	memmove(ps->a + pos, ps->a + pos+1, sizeof(SLDateType) * (ps->size - pos));
	ps->size -= 1;
}