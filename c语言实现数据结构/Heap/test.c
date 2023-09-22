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

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

void test2()
{
	Heap hp1;
	HeapInit(&hp1);
	int a[] = { 1,0,2,4,9,9,7,0,6 };
	HeapCreate(&hp1, a, sizeof(a) / sizeof(int));
	HeapDestroy(&hp1);
}

void test3()
{
	int a[] = { 1,0,2,4,9,9,7,0,6,11,22,33,44,55,66,77,88,99 };
	PrintTopK(a, 18, 10);
}

int main()
{
	TestTopk();
	//test3();
	return 0;
}