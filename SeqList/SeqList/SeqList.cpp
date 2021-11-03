#include "SeqList.h"

//需要进行初始化
void SeqListInit(SL* ps) {
	//方法1：
	/*s.size = 0;
	s.a = NULL;
	s.capacity = 0;*/

	//方法二：
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		cout << "申请内存失败！" << endl;
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//进行打印
void SeqListPrint(SL* ps) {
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		cout << ps->a[i] << "   ";
	}
	cout << endl;
}

//检查扩容
void SeqListCheckCapacity(SL* ps) {
	assert(ps);
	//如果满了需要增容
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;//增容一般增两倍
		//增容使用realloc
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			cout << "扩容失败！" << endl;
			exit(-1);
		}
	}
}

//实现尾插，四个接口
void SeqListPushBack(SL* ps, SLDataType x) {
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}
//尾删
void SeqListPopBack(SL* ps) {
	assert(ps);
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}
//头插
void SeqListPushFront(SL* ps, SLDataType x) {
	assert(ps);
	SeqListCheckCapacity(ps);
	
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
//头删
void SeqListPopFront(SL* ps) {
	assert(ps);
	SeqListCheckCapacity(ps);

	for (size_t i = 0; i < ps->size - 1 ; i++)
	{ 
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//任意位置的插入
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
//任意位置的删除
void SeqListErase(SL* ps, int pos) {
	assert(ps);
	SeqListCheckCapacity(ps);

	for (size_t i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
