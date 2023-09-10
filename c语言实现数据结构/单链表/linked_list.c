#include"linked_list.h"

// ��̬����һ�����
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
// �������ӡ
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
// ������β��
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pplist;
	*pplist = newNode;
}
// �������βɾ
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
// ������ͷɾ
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
// ���������
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
// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
// ��������posλ��֮��ɾ��
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
}