#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	二叉树的所有路径：
		给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	void helper(TreeNode* root, string path, vector<string>& ans) {
		if (root == nullptr) {
			return;
		}	
		path += to_string(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			//左右子节点都为空
			ans.push_back(path);
		}
		else {
			path += "->";
			helper(root->left, path, ans);
			helper(root->right, path, ans);
		}
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		helper(root, "", ans);
		return ans;
	}
};