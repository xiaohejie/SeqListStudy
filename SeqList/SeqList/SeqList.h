#pragma once 
#include <iostream>
#include <assert.h>
using namespace std;
//˳�����Ч�����������б���������
//��̬˳����̶���С��
//typedef int SLDataType;
//#define N 10
//
//struct SeqList {
//	SLDataType a[N];
//	int size;
//
//};
//
//void SeqListPushBack(struct SeqList* ps , SLDataType x);
//void SeqListPopBack(struct SeqList* ps);
//void SeqListPushFront(struct SeqList* ps , SLDataType x);
//void SeqListPopFront(struct SeqList* ps);


//��̬˳�����ƣ���С�ɱ䣩
typedef int SLDataType;

typedef struct SeqList {
	SLDataType *a;
	int size;			//��Ч���ݵĴ�С
	int capacity;		//����

}SL , SeqList;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
//ʵ��β��βɾ��ͷ��ͷɾ�ĸ��ӿ�
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

//����λ�õĲ���ɾ��
void SeqListInsert(SL* ps , int pos , SLDataType x);
void SeqListErase(SL* ps , int pos);