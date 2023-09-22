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

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n); 
// �ѵĳ�ʼ��
void HeapInit(Heap* hp);
// �ѵ�����
void HeapDestroy(Heap* hp);
// ���ϵ����㷨
void AdjustUp(HPDataType* a, int child);
// ���µ����㷨
void AdjustDown(HPDataType* a, int n, int parent);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// �ѵ�����
void CheckCapacity(Heap* hp);
// TopK
void PrintTopK(int* a, int n, int k);
// ������
void HeapSort(int* a, int n);