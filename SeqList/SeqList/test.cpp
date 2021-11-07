#include <iostream>
using namespace std;
#include "SeqList.h"
//≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
void TestSeqList1() {
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s , 1);
	SeqListPushBack(&s , 2);
	SeqListPushBack(&s , 3);
	SeqListPushBack(&s , 4);
	SeqListPushBack(&s , 5);
	SeqListPushBack(&s , 6);
	SeqListPushBack(&s , 7);
	SeqListPushBack(&s , 8);
	//SeqListPushBack(&s , 9);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	SeqListPushFront(&s , -1);
	SeqListPushFront(&s , -2);
	SeqListPushFront(&s , -3);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListInsert(&s , 2 , 5);
	SeqListInsert(&s , 2 , 4);
	SeqListInsert(&s , 2 , 3);

	SeqListPrint(&s);

	SeqListErase(&s ,1);
	SeqListErase(&s ,1);
	SeqListErase(&s ,1);

	SeqListPrint(&s);

	int pos = SeqListFind(&s, 2);
	if (pos != -1) {
		SeqListErase(&s, pos);
	}

	SeqListPrint(&s);
	SeqListDestroy(&s);
}	
int main() {
	TestSeqList1();
	system("pause");
	return 0;
}