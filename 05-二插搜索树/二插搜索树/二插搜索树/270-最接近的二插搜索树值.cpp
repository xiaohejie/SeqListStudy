#include<iostream>
using namespace std;
/*
	��ӽ��Ķ���������ֵ��
		ʹ��dfs������ÿ���ڵ�
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val): val(val){}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int res = -1;
	double minN = INT_MAX;
	void dfs(TreeNode* root, double target) {
		if (root == nullptr) {
			return;
		}
		double diff = abs(target - root->val);
		if (diff < minN) {
			res = root->val;
			minN = diff;
		}
		dfs(root->left, target);
		dfs(root->right, target);
	}
	int closestValue(TreeNode* root, int target) {
		dfs(root, target);
		return res;
	}
}