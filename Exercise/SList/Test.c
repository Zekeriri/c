#include"SList.h"

TestSList1()
{
	SListNode* list1=NULL;
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 4);
	SListPushFront(&list1, 1);
	SListPopFront(&list1);
	SListPopFront(&list1);
	SListPopFront(&list1);
	SListPrint(list1);
}

int main()
{
	TestSList1();

	return 0;
}