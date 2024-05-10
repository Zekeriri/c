#include "linked_list.h"

void Test1()
{
	SListNode* List1 = NULL;
	SListPushBack(&List1, 1);
	SListPushBack(&List1, 2);
	SListPushBack(&List1, 3);
	SListPushBack(&List1, 4);
	SListPushBack(&List1, 5);
	SListPushFront(&List1, 6);
	printf("%p \n", SListFind(List1, 2));
	SListEraseAfter(SListFind(List1, 2), 100);

	SListPopBack(&List1);
	SListPopFront(&List1);
	SListPrint(List1);
}

int main()
{
	Test1();
	return 0;
}