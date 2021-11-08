#include "SList.h"
int main() {
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);

	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);

	SListPrint(pList); 

	SListPushFront(&pList , 0);
	SListPushFront(&pList , -1);
	SListPushFront(&pList , -2);
	SListPushFront(&pList , -3);

	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);

	SListPrint(pList);

	SListNode* pos = SListFind(pList, 1);
	if (pos == NULL)
	{
		cout << "所查找的数不存在！" << endl;
	}
	else
	{
		pos->data = 10;
		SListPrint(pList);
	}

	SListInsertAfter(pList, 40);
	SListInsertAfter(pList, 30);

	SListPrint(pList);

	SListEraseAfter(pList);
	SListEraseAfter(pList);
	SListEraseAfter(pList);

	SListPrint(pList);

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);

	SListPrint(pList);

	//SListInsert(&pList, pList, 100);
	SListErase(&pList, pList);

	SListPrint(pList);

	system("pause");
	return 0;
}