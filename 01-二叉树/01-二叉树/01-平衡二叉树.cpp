#include <iostream>
using namespace std;
/*
    �ж��Ƿ���ƽ���������ÿ���ڵ�����������ĸ�����ľ���ֵ������1
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
    //�������߸߶�
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        else {
            return max(height(root->right), height(root->left)) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        else {
            //��Ҫ����������ƽ��Ƚ�
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->right) && isBalanced(root->left);
        }
    }
};