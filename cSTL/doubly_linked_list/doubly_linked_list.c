#include "doubly_linked_list.h"

LTNode* BuyLTNode(LTDataType x)
{
    LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
    if (newNode == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
LTNode* LTInit()
{
    LTNode* phead = BuyLTNode(-1);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}
void LTPrint(LTNode* phead)
{
    assert(phead);
    printf("Sentinel Guard<->");
    LTNode* cur = phead->next;
    while (phead != cur)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
bool LTEmpty(LTNode* phead)
{
    assert(phead);
    return phead != phead->next;
}
void LTPushBack(LTNode* phead, LTDataType x)
{
    assert(phead);
    LTInsert(phead,x);
}
void LTPushFront(LTNode* phead, LTDataType x)
{
    assert(phead);
    LTInsert(phead->next, x);
}
void LTPopBack(LTNode* phead)
{
    assert(phead);
    assert(!LTEmpty(phead));
    LTErase(phead->prev);
}
void LTPopFront(LTNode* phead)
{
    assert(phead);
    assert(!LTEmpty(phead));
    LTErase(phead->next);
}
LTNode* LTFind(LTNode* phead, LTDataType x)
{
    assert(phead);
    LTNode* cur = phead->next;
    while (phead != cur)
    {
        if (cur->data == x) return cur;
        cur = cur->next;
    }
    return NULL;
}
// 在pos之前插入
void LTInsert(LTNode* pos, LTDataType x)
{
    LTNode* newNode = BuyLTNode(x);
    LTNode* prev = pos->prev;
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = pos;
    pos->prev = newNode;
}
// 删除pos位置的值
void LTErase(LTNode* pos)
{
    assert(pos);
    LTNode* prev = pos->prev;
    LTNode* next = pos->next;
    prev->next = next;
    next->prev = prev;
    free(pos);
}
void LTDestroy(LTNode* phead)
{
    assert(phead);
    LTNode* cur = phead->next;
    while (phead != cur)
    {
        LTNode* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(phead);
}