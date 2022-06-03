#include<iostream>
#include <vector>
using namespace std;
/*
����һ������������, �ҵ�����������ָ���ڵ������������ȡ�������һ��������������������ȣ�
�ٶȰٿ�������������ȵĶ���Ϊ
	�������и��� T ��������� p��q������������ȱ�ʾΪһ����� x��
	���� x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ���
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	//�ҳ����ڵ㵽��ǰ�ڵ��·��
	void helper(TreeNode* root, TreeNode* p, vector<int>& route) {
		if (p->val == root->val) {
			route.push_back(root->val);
			return;
		}
		else {
			if (p->val < root->val) {
				route.push_back(root->val);
				helper(root->left, p, route);
			}
			else {
				route.push_back(root->val);
				helper(root->right, p, route);
			}
		}
	}
	//�ҳ�ֵ��ȵĽ��
	TreeNode* findNode(TreeNode* root, int val) {
		if (root->val == val) {
			return root;
		}
		else {
			if (val < root->val) {
				return  findNode(root->left, val);
			}
			else {
				return findNode(root->right, val);
			}
		}
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<int> routeP;
		vector<int> routeQ;
		helper(root, p, routeP);	//�ҵ����ڵ㵽p��·��
		helper(root, q, routeQ);	//�ҵ����ڵ㵽q��·��
		//�ҳ���ͬ�����һ�����
		int i = 0;
		for (; i < max(routeP.size(), routeQ.size()); i++) {
			if (routeP[i] != routeQ[i]) {
				break;
			}
		}
		return findNode(root, routeP[i - 1]);
    }
};