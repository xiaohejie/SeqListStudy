#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

/*
	106-从中序和后序遍历序列构造二叉树：
		类似于从前序和中序构造二叉树，没差别
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
	unordered_map<int, int> map;
	int len;
public:
	TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pol, int por) {
	
	}
};