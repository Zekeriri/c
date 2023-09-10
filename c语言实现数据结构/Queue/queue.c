#include"queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
// ���ٶ��� 
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