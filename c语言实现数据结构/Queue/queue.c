#include"queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newNode->data = data;
	newNode->pNext = NULL;
	if (QueueEmpty(q))
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		q->rear->pNext = newNode;
		q->rear = newNode;
	}
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* Node = q->front;
	if (q->front->pNext == NULL)
	{
		assert(q->rear->pNext == NULL);
		q->front = NULL;
	}
	else
	{
		q->front = q->front->pNext;
	}
	free(Node);
	q->size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->pNext;
		free(cur);
		cur = next;
	}
}