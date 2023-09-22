#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;
typedef struct QListNode
{
    struct QListNode* next;
    QDataType value;
}QNode;

typedef struct {
    QNode* front;
    QNode* rear;
    int size;
    int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->front = NULL;
    obj->rear = NULL;
    obj->size = 0;
    obj->k = k;
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    obj->front = obj->rear = newNode;
    while (--k)
    {
        newNode = (QNode*)malloc(sizeof(QNode));
        obj->rear->next = newNode;
        obj->rear = obj->rear->next;
    }
    obj->rear->next = obj->front;
    obj->rear = obj->front;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!myCircularQueueIsFull(obj))
    {
        obj->rear->value = value;
        obj->rear = obj->rear->next;
        obj->size++;
        return true;
    }
    else
    {
        return false;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!myCircularQueueIsEmpty(obj))
    {
        obj->front = obj->front->next;
        obj->size--;
        return true;
    }
    else
    {
        return false;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->front->value;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    QNode* ret = obj->front;
    int n = obj->size;
    while (--n)
    {
        ret = ret->next;
    }
    return ret->value;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->k;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    // if (myCircularQueueIsEmpty(obj))
    // {
    //     return;
    // }
    // QNode* cur=obj->front;
    // QNode* next=cur->next;
    // int n=obj->k;
    // while(--n)
    // {
    //     free(cur);
    //     cur=next;
    //     next=cur->next;
    // }
    // free(next);
    // free(obj);
}

int main()
{
    MyCircularQueue* obj = myCircularQueueCreate(7);
    myCircularQueueEnQueue(obj,0);
    myCircularQueueEnQueue(obj,4);
    myCircularQueueEnQueue(obj,6);
    myCircularQueueEnQueue(obj,3);
    myCircularQueueDeQueue(obj);
    int a=myCircularQueueFront(obj);
    myCircularQueueDeQueue(obj);
    int b=myCircularQueueFront(obj);
    return 0;
}