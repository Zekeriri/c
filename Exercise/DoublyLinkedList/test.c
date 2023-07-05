#include"DoublyLinkedList.h"

void TestList1()
{
	ListNode* plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//ListPushFront(plist, 1);
	//ListPushFront(plist, 2);
	//ListPushFront(plist, 3);
	//ListPushFront(plist, 4);

	ListNode* pos= ListFind(plist, 3);
	if (pos)
	{
		ListInsert(pos, 30);
	}

	ListPrint(plist);
}

int main()
{
	TestList1();
}