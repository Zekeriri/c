#include "linked_list.h"

// 动态申请一个结点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newNode;
		return;
	}
	SListNode* prev = NULL;
	SListNode* cur = *pplist;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = newNode;
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newNode;
		return;
	}
	newNode->next = *pplist;
	*pplist = newNode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	SListNode* prev = NULL;
	SListNode* cur = *pplist;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	prev->next = NULL;
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	SListNode* head = *pplist;
	*pplist = (*pplist)->next;
	free(head);
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		if (x == cur->data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
// 单链表在pos位置之后删除
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* cur = pos->next;
	if (cur)
	{
		pos->next = cur->next;
		free(cur);
	}
}
