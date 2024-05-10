#include"stack.h"

int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 100);
	printf("%d ", StackTop(&s));
	StackPop(&s);
}