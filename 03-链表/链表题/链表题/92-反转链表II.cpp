#include<iostream>
using namespace std;
/*
	��ת����II��
		ֻҪ��ǰ���������������ȡ����
		�м������ٽ��з�ת
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
	//�������������
	void helper(ListNode* head) {
		ListNode* pre = NULL;
		pre->next = head;
		ListNode* cur = head;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
	}
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		//��ȡ����
		ListNode* dummyNode = new ListNode(0);		//�ڱ��ڵ�
		dummyNode->next = head;
		ListNode* frontNode = head;
		ListNode* betwNode = head;
		ListNode* backNode = head;
		//��ʼ��������н�ȡ
		ListNode* pre = dummyNode;
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}
		ListNode* tmpNode = pre;
		for (int i = 0; i < right - left + 1; i++) {
			tmpNode = tmpNode->next;
		}
		betwNode = pre->next;	//��߽��߽�
		backNode = tmpNode->next;	//�ұ߽ڵ�߽�
		//�������жϿ�
		pre->next = nullptr;
		tmpNode->next = nullptr;
		//���м����������ת
		helper(betwNode);
		//����֮���ٽ�������������
		pre->next = tmpNode;
		betwNode->next = backNode;
		return dummyNode->next;
	}
};