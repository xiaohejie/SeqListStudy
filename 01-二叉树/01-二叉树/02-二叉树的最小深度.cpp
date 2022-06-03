#include<iostream>
using namespace std;
/*
	给定一个二叉树，找出其最小深度
		最小深度是指：从根节点到最近叶子结点的最短路径上的节点数量
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
    int minDepth(TreeNode* root) {
        int minLen = INT_MAX;
        if (root == nullptr) {
            return 0;
        }
        if (root->right == nullptr && root->left == nullptr) {
            return 1;
        }
        if (root->right != nullptr) {
            minLen = min(minLen, minDepth(root->right));
        }
        if (root->left != nullptr) {
            minLen = min(minLen, minDepth(root->left));
        }
        return minLen + 1;
    }
};