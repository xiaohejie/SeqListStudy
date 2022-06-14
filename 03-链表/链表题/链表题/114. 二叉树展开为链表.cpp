#include<iostream>
#include<vector>
using namespace std;
/*
	114. 二叉树展开为链表（使用O(1)的额外空间）:
			先判断该节点的左子树有没有结点
				有的话，找出左子树节点的最右结点
				将最右节点的的右子树连上当前节点的右子树
				当前节点的右子树变为左子树节点
				当前节点的左子树置为空
			然后在将当前节点变为前一个节点的右节点（左子树已经置为空）
		
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
	void preorder(TreeNode* root, vector<TreeNode*>& vec) {
		if (root == nullptr) {
			return;
		}
		vec.push_back(root);
		preorder(root->left, vec);
		preorder(root->right, vec);
	}
	void flatten(TreeNode* root) {
		vector<TreeNode*> vec;		//用来装节点
		//进行先序遍历
		preorder(root, vec);		//将结点按照先序遍历存储起来
		//然后在重新构建链表
		for (int i = 1; i < vec.size(); i++) {
			TreeNode* prev = vec.at(i - 1), * curr = vec.at(i);
			prev->left = nullptr;
			prev->right = curr;
		}
	}
};