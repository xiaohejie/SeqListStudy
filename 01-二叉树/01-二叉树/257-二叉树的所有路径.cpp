#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	������������·����
		����һ���������ĸ��ڵ� root ���� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·����
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
			//�����ӽڵ㶼Ϊ��
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