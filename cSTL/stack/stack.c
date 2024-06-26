#include"stack.h"
// 初始化栈 
void StackInit(Stack* ps)
{
	ps->capacity = 4;
	ps->top = 0;
	ps->a = (STDataType*)malloc(sizeof(STDataType) * ps->capacity);
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->top] = data;
	ps->top++;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
// 扩容
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
