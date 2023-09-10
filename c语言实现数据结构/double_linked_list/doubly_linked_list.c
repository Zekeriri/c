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
	if (LTEmpty(phead))
	{
		printf("sentinel\n");
	}
	else
	{
		printf("sentinel<==>");
		LTNode* cur = phead;
		while (cur->next != phead)
		{
			cur = cur->next;
			printf("%d<==>", cur->data);
		}
		printf("\n");
	}
}
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	
	return phead->next == phead;
}
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newNode = BuyLTNode(x);
	LTNode* prevNode = phead->prev;
	prevNode->next = newNode;
	newNode->prev = prevNode;
	newNode->next = phead;
	phead->prev = newNode;*/
	LTInsert(phead, x);
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newNode = BuyLTNode(x);
	LTNode* nextNode = phead->next;
	phead->next = newNode;
	newNode->prev = phead;
	newNode->next = nextNode;
	nextNode->prev = newNode;*/
	LTInsert(phead->next, x);
}
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	/*LTNode* prevNode = phead->prev->prev;
	free(phead->prev);
	prevNode->next = phead;
	phead->prev = prevNode;*/
	LTErase(phead->prev);
}
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	/*LTNode* nextNode = phead->next->next;
	free(phead->next);
	phead->next = nextNode;
	nextNode->prev = phead;*/
}
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead;
	while (cur->next != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 在pos之前插入
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newNode = BuyLTNode(x);
	LTNode* prevNode = pos->prev;
	prevNode->next = newNode;
	newNode->prev = prevNode;
	newNode->next = pos;
	pos->prev = newNode;
}
// 删除pos位置的值
void LTErase(LTNode* pos)
{
	LTNode* prevNode = pos->prev;
	LTNode* nextNode = pos->next;
	free(pos);
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
}
void LTDestroy(LTNode* phead)
{
	LTNode* cur = phead;
	LTNode* next = cur->next;
	while (next!=phead)
	{
		cur = next;
		next = cur->next;
		free(cur);
	}
	free(phead);
}