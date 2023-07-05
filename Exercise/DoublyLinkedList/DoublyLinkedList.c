#include"DoublyLinkedList.h"

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	head->next = head;
	head->prev = head;
	return head;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur!=pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}

// ˫�����ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	printf("sentinel value<==>");
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		printf("%d<==>", cur->data);
		cur = next;
	}
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = next;
	next->prev = newNode;
}

bool isEmpty(ListNode* pos)
{
	if (pos->next == pos)
		return false;
	else
		return true;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(isEmpty(pos));
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next -> prev = prev;
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead,x);
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	ListErase(pHead->prev);
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead->next, x);
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	ListErase(pHead->next);
}