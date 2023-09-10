#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		assert(pq->phead == NULL);
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//1，一个节点
	//2，多个节点
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL && pq->ptail == NULL;
}


typedef struct {
	Queue* q1;
	Queue* q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* s = (MyStack*)malloc(sizeof(MyStack));
	s->q1 = (Queue*)malloc(sizeof(Queue));
	s->q2 = (Queue*)malloc(sizeof(Queue));
	QueueInit(s->q1);
	QueueInit(s->q2);
	return s;
}

void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(obj->q1) && QueueEmpty(obj->q2))
	{
		QueuePush(obj->q1, x);
	}
	if (!QueueEmpty(obj->q1))
	{
		QueuePush(obj->q1, x);
	}
	if (!QueueEmpty(obj->q2))
	{
		QueuePush(obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	if (!QueueEmpty(obj->q1))
	{
		while (QueueSize(obj->q1) != 1)
		{
			QueuePush(obj->q2, QueueFront(obj->q1));
			QueuePop(obj->q1);
		}
		int tmp = QueueFront(obj->q1);
		QueuePop(obj->q1);
		return tmp;
	}
	if (!QueueEmpty(obj->q2))
	{
		while (QueueSize(obj->q2) != 1)
		{
			QueuePush(obj->q1, QueueFront(obj->q2));
			QueuePop(obj->q2);
		}
		int tmp = QueueFront(obj->q2);
		QueuePop(obj->q2);
		return tmp;
	}
	return -1;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(obj->q1))
	{
		return QueueBack(obj->q1);
	}
	if (!QueueEmpty(obj->q2))
	{
		return QueueBack(obj->q2);
	}
	return -1;
}

bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(obj->q1) && QueueEmpty(obj->q2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myStackFree(MyStack* obj) {
	QueueDestroy(obj->q1);
	QueueDestroy(obj->q2);
	free(obj->q1);
	free(obj->q2);
	free(obj);
}

int main()
{
	MyStack* s = myStackCreate();
	myStackPush(s, 1);
	int a=myStackPop(s);
	bool b=myStackEmpty(s);
	return 0;
}