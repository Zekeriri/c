#include"DoublyLinkedList.h"

// 创建返回链表的头结点.
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

// 双向链表销毁
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

// 双链表打印
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

// 双向链表查找
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

// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
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

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead,x);
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	ListErase(pHead->prev);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead->next, x);
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	ListErase(pHead->next);
}