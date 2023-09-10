#include"stack.h"

int Test1()
{
	Stack stack1;
	StackInit(&stack1);
	StackPush(&stack1, 1);
	StackPush(&stack1, 2);
	StackPop(&stack1);
	printf("%d\n", StackTop(&stack1));
}

int main()
{
	Test1();
	return 0;
}