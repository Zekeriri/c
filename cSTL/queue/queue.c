#include"queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	QNode* newNode = BuyListNode(data);
	if (QueueEmpty(q))
	{
		q->front = newNode;
		q->rear = newNode;
		q->size++;
		return;
	}
	q->rear->pNext = newNode;
	q->rear = newNode;
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(!QueueEmpty(q));
	QNode* tmp = q->front;
	q->front = tmp->pNext;
	free(tmp);
	q->size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->size == 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	while (!QueueEmpty(q))
	{
		QueuePop(q);
	}
}
// 生成节点
QNode* BuyListNode(QDataType x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->pNext = NULL;
	newNode->data = x;
	return newNode;
}

