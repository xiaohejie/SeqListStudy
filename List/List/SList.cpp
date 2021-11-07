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