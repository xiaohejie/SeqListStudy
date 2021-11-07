#pragma once
#include<iostream>
using namespace std;

typedef int SListDataType;
//结点
typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pphead , SListDataType x);		//尾插
void SListPopBack(SListNode** pphead);						//尾删
void SListPushFront(SListNode* phead, SListDataType x);		//头插
void SListPopFront(SListNode* phead);						//头删

void SListPrint(SListNode* phead);
SListNode* SListBuySListNode(SListDataType x);