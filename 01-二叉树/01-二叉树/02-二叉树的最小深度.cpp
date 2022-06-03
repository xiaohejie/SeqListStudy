#include<iostream>
using namespace std;
/*
	����һ�����������ҳ�����С���
		��С�����ָ���Ӹ��ڵ㵽���Ҷ�ӽ������·���ϵĽڵ�����
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