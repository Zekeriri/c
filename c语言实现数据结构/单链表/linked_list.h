#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
// 1����ͷ+����+��ѭ��������ɾ���ʵ��
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ�����
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ��������posλ��֮��ɾ��
void SListEraseAfter(SListNode* pos);