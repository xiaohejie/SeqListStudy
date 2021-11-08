#include "SList.h"

//打印链表
void SListPrint(SListNode* phead) {
	SListNode* cur = phead;
	while (cur != NULL)
	{
		cout << cur->data << "  ";
		cur = cur->next;
	}
	cout << endl;
}

//申请结点
SListNode* SListBuySListNode(SListDataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		cout << "申请结点失败！" << endl;
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}
//尾插
void SListPushBack(SListNode** pphead, SListDataType x) {
	SListNode* newNode = SListBuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//找尾
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;	
	}
}

//头插
void SListPushFront(SListNode** pphead, SListDataType x) {
	//申请一个结点
	SListNode* newNode = SListBuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;

}

//尾删
void SListPopBack(SListNode** pphead) {
	//1、空
	//2、一个结点
	//3、一个以上结点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

//头删
void SListPopFront(SListNode** pphead) {
	//1、空
	//2、一个结点  +  3、一个以上结点
	if (*pphead == NULL)
	{
		return;
	}
	else 
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next; 
	}
}

//查找
SListNode* SListFind(SListNode* phead, SListDataType x) {
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在当前位置的后一个位置进行添加
void SListInsertAfter(SListNode* pos, SListDataType x) {
	assert(pos);

	SListNode* newNode = SListBuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//在当前位置的后一个位置进行删除
void SListEraseAfter(SListNode* pos) {
	assert(pos);
	if (pos->next)
	{
		SListNode* next = pos->next;
		SListNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}

//// 单链表在pos位置之前插入x
//void SListInsert(SListNode** pphead, SListNode* pos, SListDataType x) {
//	
//	SListNode* newNode = SListBuySListNode(x);
//	if (*pphead == NULL)
//	{
//		return;
//	}
//	else
//	{
//		SListNode* prev = *pphead;
//		SListNode* cur = *pphead;
//		while (cur->next != pos)
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//		prev->next = newNode;
//		newNode->next = cur;
//
//	}
//}


// 单链表删除pos位置的值
void SListErase(SListNode** pphead, SListNode* pos) {
	//1、空
	//2、一个结点
	//3、一个以上结点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* cur = *pphead;
		while (cur->next != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
		
	}
}
