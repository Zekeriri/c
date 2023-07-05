#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;
typedef struct SeqList
{
	SLDatatype* a;
	int size;
	int capacity;
}SL;

void SLInit(SL* psl);
void SLDestroy(SL* psl);
void SLPrint(SL* psl);

void SLPushBack(SL* psl, SLDatatype x);
void SLPushFront(SL* psl, SLDatatype x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

void SLInsert(SL* psl, int pos, SLDatatype x);
void SLErase(SL* psl, int pos);

int SLFind(SL* psl, SLDatatype x);
void SLModify(SL* psl, int pos, SLDatatype);
