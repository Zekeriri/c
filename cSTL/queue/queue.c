#include"queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
// ��β����� 
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
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(!QueueEmpty(q));
	QNode* tmp = q->front;
	q->front = tmp->pNext;
	free(tmp);
	q->size--;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->size == 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	while (!QueueEmpty(q))
	{
		QueuePop(q);
	}
}
// ���ɽڵ�
QNode* BuyListNode(QDataType x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->pNext = NULL;
	newNode->data = x;
	return newNode;
}

