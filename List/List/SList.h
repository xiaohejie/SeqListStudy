#pragma once
#include<iostream>
using namespace std;
#include "assert.h"

typedef int SListDataType;
//结点
typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pphead , SListDataType x);		//尾插
void SListPopBack(SListNode** pphead);						//尾删
void SListPushFront(SListNode** pphead, SListDataType x);		//头插
void SListPopFront(SListNode** pphead);						//头删
SListNode* SListFind(SListNode* phead, SListDataType x);	//查找

void SListInsertAfter(SListNode* phead, SListDataType x);	//在当前位置的后一个位置进行添加
void SListEraseAfter(SListNode* phead);						//在当前位置的后一个位置进行删除

// 单链表在pos位置之前插入x
void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x);
// 单链表删除pos位置的值
void SListErase(SListNode** pplist, SListNode* pos);

void SListPrint(SListNode* phead);
SListNode* SListBuySListNode(SListDataType x);