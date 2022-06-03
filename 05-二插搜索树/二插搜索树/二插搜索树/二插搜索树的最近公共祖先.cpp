#include<iostream>
#include <vector>
using namespace std;
/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。（还有一个二叉树的最近公共祖先）
百度百科中最近公共祖先的定义为
	“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
	满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	//找出根节点到当前节点的路径
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
	//找出值相等的结点
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
		helper(root, p, routeP);	//找到根节点到p的路径
		helper(root, q, routeQ);	//找到根节点到q的路径
		//找出相同的最后一个结点
		int i = 0;
		for (; i < max(routeP.size(), routeQ.size()); i++) {
			if (routeP[i] != routeQ[i]) {
				break;
			}
		}
		return findNode(root, routeP[i - 1]);
    }
};