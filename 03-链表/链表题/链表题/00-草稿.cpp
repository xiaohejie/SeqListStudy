#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
	206. 反转链表
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* curNext = head->next;

		//翻转链表
		while (cur) {
			cur->next = pre;
			pre = cur;
			cur = curNext;
			if (curNext) {
				curNext = curNext->next;
			}
		}
		return cur->next;
	}
};