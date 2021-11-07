#include "SList.h"

//��ӡ����
void SListPrint(SListNode* phead) {
	SListNode* cur = phead;
	while (cur != NULL)
	{
		cout << cur->data << "  ";
		cur = cur->next;
	}
	cout << endl;
}

//������
SListNode* SListBuySListNode(SListDataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		cout << "������ʧ�ܣ�" << endl;
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}
//β��
void SListPushBack(SListNode** pphead, SListDataType x) {
	SListNode* newNode = SListBuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//��β
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;	
	}
}

//βɾ
void SListPopBack(SListNode** pphead) {
	//1����
	//2��һ�����
	//3��һ�����Ͻ��
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