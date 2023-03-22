#include "SeqList.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	SeqListPushFront(&s, 10);
	SeqListPrint(&s);
	SeqListFind(&s, 3);
	SeqListInsert(&s, 2, 22);
	SeqListErase(&s, 2);
	SeqListPrint(&s);

}
int main()
{

	TestSeqList1();
	return 0;
}
