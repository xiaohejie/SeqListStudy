#include <iostream>
using namespace std;
/*
    判断是否是平衡二叉树：每个节点的两个子树的高数差的绝对值不超过1
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
    //求结点的最高高度
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
            //还要对子树进行平衡比较
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->right) && isBalanced(root->left);
        }
    }
};