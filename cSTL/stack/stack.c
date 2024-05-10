#include"stack.h"
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->capacity = 4;
	ps->top = 0;
	ps->a = (STDataType*)malloc(sizeof(STDataType) * ps->capacity);
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->top] = data;
	ps->top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
// ����
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->capacity = ps->top)
	{
		int newCapacity = ps->capacity == 4 ? 0 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newCapacity* sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("relloc fail");
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}
