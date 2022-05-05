#include<iostream>
using namespace std;
/*
	反转链表II：
		只要将前面链表，后面链表截取下来
		中间链表再进行反转
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
	//将链表进行逆置
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
		//截取链表
		ListNode* dummyNode = new ListNode(0);		//哨兵节点
		dummyNode->next = head;
		ListNode* frontNode = head;
		ListNode* betwNode = head;
		ListNode* backNode = head;
		//开始将链表进行截取
		ListNode* pre = dummyNode;
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}
		ListNode* tmpNode = pre;
		for (int i = 0; i < right - left + 1; i++) {
			tmpNode = tmpNode->next;
		}
		betwNode = pre->next;	//左边结点边界
		backNode = tmpNode->next;	//右边节点边界
		//将结点进行断开
		pre->next = nullptr;
		tmpNode->next = nullptr;
		//将中间链表进行逆转
		helper(betwNode);
		//逆置之后，再将链表链接起来
		pre->next = tmpNode;
		betwNode->next = backNode;
		return dummyNode->next;
	}
};