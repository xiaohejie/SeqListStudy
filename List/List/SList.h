#pragma once
#include<iostream>
using namespace std;

typedef int SListDataType;
//���
typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pphead , SListDataType x);		//β��
void SListPopBack(SListNode** pphead);						//βɾ
void SListPushFront(SListNode* phead, SListDataType x);		//ͷ��
void SListPopFront(SListNode* phead);						//ͷɾ

void SListPrint(SListNode* phead);
SListNode* SListBuySListNode(SListDataType x);