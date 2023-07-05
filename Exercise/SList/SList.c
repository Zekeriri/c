#include"SList.h"


// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = NULL;
	newNode = (SListNode*)malloc(sizeof(SListNode));
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
	while (cur!= NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
}

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	if ((*pplist)== NULL)
	{
		(*pplist) = newNode;
	}
	else
	{
		SListNode* cur = (*pplist);
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
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
	assert(*pplist);
	SListNode* cur = (*pplist);
	if (cur->next == NULL)
	{
		free(cur);
		*pplist = NULL;
	}
	else
	{
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* cur = (*pplist);
		*pplist = cur->next;
		free(cur);
}