#include"sort.h"

//// 测试排序的性能对比
//void TestOP()
//{
//	srand(time(0));
//	const int N = 100000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//
//	}
//
//	int begin1 = clock();
//	InsertSort(a1, N);
//	int end1 = clock();
//
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//
//	int begin3 = clock();
//	SelectSort(a3, N);
//	int end3 = clock();
//
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//
//	int begin5 = clock();
//	QuickSort(a5, 0, N - 1);
//	int end5 = clock();
//
//	int begin6 = clock();
//	MergeSort(a6, N);
//	int end6 = clock();
//
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("QuickSort:%d\n", end5 - begin5);
//	printf("MergeSort:%d\n", end6 - begin6);
//
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestInsertSort()
{
	int a[] = { 2,4,3,1,4,9,0,8,8,4 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestShellSort()
{
	int a[] = { 2,4,3,1,4,9,0,8,8,4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestBubbleSort()
{
	int a[] = { 2,4,3,1,4,9,0,8,8,4 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestSelectSort()
{
	int a[] = { 2,4,3,1,4,9,0,8,8,4 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestQuickSort()
{
	int a[] = { 2,4,3,1,4,9,0,8,8,4,2,4,3,1,4,9,0,8,8,4,2,4,3,1,4,9,0,8,8,4,2,4,3,1,4,9,0,8,8,4,2,4,3,1,4,9,0,8,8,4 };
	//int a[] = { 2,4,3,1,4,9,0,8,8,4 };

	QuickSortNonR(a, 0, sizeof(a) / sizeof(int));
	//QuickSort(a, 0, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestMergeSort()
{
	int a[] = { 2,4,3,1,4,9,0,8,8,4 };
	//MergeSort(a, 0, sizeof(a) / sizeof(int));
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestCountSort()
{
	int a[] = { 2,4,3,1,4,9,0,8,8,4 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestMergeSort();
	TestCountSort();
	return 0;
}
