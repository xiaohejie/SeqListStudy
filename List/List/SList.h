#pragma once
#include<iostream>
using namespace std;
#include "assert.h"

typedef int SListDataType;
//���
typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pphead , SListDataType x);		//β��
void SListPopBack(SListNode** pphead);						//βɾ
void SListPushFront(SListNode** pphead, SListDataType x);		//ͷ��
void SListPopFront(SListNode** pphead);						//ͷɾ
SListNode* SListFind(SListNode* phead, SListDataType x);	//����

void SListInsertAfter(SListNode* phead, SListDataType x);	//�ڵ�ǰλ�õĺ�һ��λ�ý������
void SListEraseAfter(SListNode* phead);						//�ڵ�ǰλ�õĺ�һ��λ�ý���ɾ��

// ��������posλ��֮ǰ����x
void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x);
// ������ɾ��posλ�õ�ֵ
void SListErase(SListNode** pplist, SListNode* pos);

void SListPrint(SListNode* phead);
SListNode* SListBuySListNode(SListDataType x);