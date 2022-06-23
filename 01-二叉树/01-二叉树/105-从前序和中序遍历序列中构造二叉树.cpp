#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	105-从前序和中序遍历序列中构造二叉树
		前序序列的头结点是二叉树的根节点
		可以根据根节点和中序遍历，划分左右子树
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
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if (pl > pr || il > ir) {
			return nullptr;
		}
		//记录以preorder[pl]为根节点的二叉树，左子树有多少元素
		int count = map[preorder[pl]] - il;
		//创建二叉树
		TreeNode* root = new TreeNode(preorder[pl]);
		root->left = build(preorder, inorder, pl + 1, pl + count, il, il + count - 1);
		root->right = build(preorder, inorder, pl + count + 1, pr, il + count + 1, ir);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		len = preorder.size();
		for (int i = 0; i < len; i++) {
			//记录以该节点为根节点的左子树的个数
			map[inorder[i]] = i;
		}
		//创建二叉树
		return build(preorder, inorder, 0, len - 1, 0, len - 1);
	}
};