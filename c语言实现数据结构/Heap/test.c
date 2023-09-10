#include"heap.h"

void test1()
{
	Heap hp1;
	HeapInit(&hp1);
	HeapPush(&hp1, 1);
	HeapPush(&hp1, 2);
	HeapPush(&hp1, 3);
	HeapPush(&hp1, 8);
	HeapPush(&hp1, 7);
	HeapPush(&hp1, 6);
	HeapPush(&hp1, 5);
	HeapPop(&hp1);
	HeapDestroy(&hp1);

}

int main()
{
	test1();
	return 0;
}