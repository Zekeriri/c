#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n); 
// 堆的初始化
void HeapInit(Heap* hp);
// 堆的销毁
void HeapDestroy(Heap* hp);
// 向上调整算法
void AdjustUp(HPDataType* a, int child);
// 向下调整算法
void AdjustDown(HPDataType* a, int n, int parent);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 堆的扩容
void CheckCapacity(Heap* hp);
// TopK
void PrintTopK(int* a, int n, int k);
// 堆排序
void HeapSort(int* a, int n);