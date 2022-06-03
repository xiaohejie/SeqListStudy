#include<iostream>
#include<vector>
using namespace std;
/*
	������������������ȣ�
		��root��p��q�Ĺ������ȣ�
			��1��p��q��root�������У��ҷ�����root������
			��2��p=root����q��root�������������
			��3��q=root����p��root�������������

*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//��rootΪ�ա�p��qΪroot����˵������������Ⱦ���root
		if (root == nullptr || root == p || root == q) {
			return root;
		}
		//�ֱ������������p��q
		TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		//���leftΪ�գ�˵��p��q�����������У��ͷ���������
		if (left == nullptr) {
			return right;
		}
		////���rightΪ�գ�˵��p��q�����������У��ͷ���������
		if (right == nullptr) {
			return left;
		}
		//��left��right����Ϊ�գ���˵�����������ж�����p��q����һ�������ͷ���root
		return root;
	}
};