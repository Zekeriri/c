#include"sequence_list.h"


void Test1()
{
	SeqList List1;
	SeqListInit(&List1);
	SeqListPrint(&List1);
	SeqListPushBack(&List1, 1);
	SeqListPushBack(&List1, 2);
	SeqListPushBack(&List1, 3);
	SeqListPushBack(&List1, 4);
	SeqListPushBack(&List1, 5);
	SeqListPushBack(&List1, 6);
	SeqListPushFront(&List1, 7);
	SeqListPopFront(&List1);
	SeqListPopBack(&List1);
	SeqListModify(&List1, 1, 8);
	SeqListPrint(&List1);
	printf("%d ", SeqListFind(&List1,4));
	SeqListDestory(&List1);

}

int main()
{
	Test1();
}