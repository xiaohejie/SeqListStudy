#pragma once 
#include <iostream>
#include <assert.h>
using namespace std;
//顺序表。有效数组在数组中必须是连续
//静态顺序表（固定大小）
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


//动态顺序表设计（大小可变）
typedef int SLDataType;

typedef struct SeqList {
	SLDataType *a;
	int size;			//有效数据的大小
	int capacity;		//容量

}SL , SeqList;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
//实现尾插尾删，头插头删四个接口
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

//任意位置的插入删除
void SeqListInsert(SL* ps , int pos , SLDataType x);
void SeqListErase(SL* ps , int pos);