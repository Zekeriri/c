#include "doubly_linked_list.h"

void test1()
{
	LTNode* List1 = LTInit();
	LTPushBack(List1, 1);
	LTPushBack(List1, 2);
	LTPushBack(List1, 3);
	LTPushBack(List1, 4);
	LTPushBack(List1, 5);
	LTPushFront(List1, 6);
	LTPopFront(List1);
	LTPopBack(List1);
	LTInsert(LTFind(List1, 3),30);
	LTPrint(List1);
	LTDestroy(List1);
}
int main()
{
	test1();
}