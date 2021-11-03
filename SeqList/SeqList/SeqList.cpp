#include "SeqList.h"

//��Ҫ���г�ʼ��
void SeqListInit(SL* ps) {
	//����1��
	/*s.size = 0;
	s.a = NULL;
	s.capacity = 0;*/

	//��������
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		cout << "�����ڴ�ʧ�ܣ�" << endl;
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//���д�ӡ
void SeqListPrint(SL* ps) {
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		cout << ps->a[i] << "   ";
	}
	cout << endl;
}

//�������
void SeqListCheckCapacity(SL* ps) {
	assert(ps);
	//���������Ҫ����
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;//����һ��������
		//����ʹ��realloc
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			cout << "����ʧ�ܣ�" << endl;
			exit(-1);
		}
	}
}

//ʵ��β�壬�ĸ��ӿ�
void SeqListPushBack(SL* ps, SLDataType x) {
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}
//βɾ
void SeqListPopBack(SL* ps) {
	assert(ps);
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}
//ͷ��
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
//ͷɾ
void SeqListPopFront(SL* ps) {
	assert(ps);
	SeqListCheckCapacity(ps);

	for (size_t i = 0; i < ps->size - 1 ; i++)
	{ 
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//����λ�õĲ���
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
//����λ�õ�ɾ��
void SeqListErase(SL* ps, int pos) {
	assert(ps);
	SeqListCheckCapacity(ps);

	for (size_t i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
