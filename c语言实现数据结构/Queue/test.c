#include"queue.h"

void test1()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	//QueuePop(&q1);
	//QueuePop(&q1);
	//QueuePop(&q1);
	printf("front:%d\n", QueueFront(&q1));
	printf("rear:%d\n", QueueBack(&q1));
	QueueDestroy(&q1);
}

int main()
{
	test1();
	return 0;
}