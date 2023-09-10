#include"linked_list.h"

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
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	newNode->next = NULL;
	if (*pplist == NULL)
	{
		*pplist = newNode;
		return;
	}
	SListNode* cur = *pplist;
	SListNode* next = cur->next;
	while (next)
	{
		cur = next;
		next = cur->next;
	}
	cur->next = newNode;
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pplist;
	*pplist = newNode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);
	SListNode* prev = NULL;
	SListNode* cur = *pplist;
	SListNode* next = cur->next;
	while (next)
	{
		prev = cur;
		cur = next;
		next = next->next;
	}
	free(cur);
	if (prev!=NULL)
	{
		prev->next = NULL;
	}
	else
	{
		*pplist = NULL;
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);
	SListNode* cur = *pplist;
	SListNode* next = cur->next;
	free(cur);
	if (next != NULL)
	{
		*pplist = next;
	}
	else
	{
		*pplist = NULL;
	}
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{

	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
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
	assert(pos->next);
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
}