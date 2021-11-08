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

//ͷ��
void SListPushFront(SListNode** pphead, SListDataType x) {
	//����һ�����
	SListNode* newNode = SListBuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;

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

//ͷɾ
void SListPopFront(SListNode** pphead) {
	//1����
	//2��һ�����  +  3��һ�����Ͻ��
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

//����
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

//�ڵ�ǰλ�õĺ�һ��λ�ý������
void SListInsertAfter(SListNode* pos, SListDataType x) {
	assert(pos);

	SListNode* newNode = SListBuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//�ڵ�ǰλ�õĺ�һ��λ�ý���ɾ��
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

//// ��������posλ��֮ǰ����x
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


// ������ɾ��posλ�õ�ֵ
void SListErase(SListNode** pphead, SListNode* pos) {
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
