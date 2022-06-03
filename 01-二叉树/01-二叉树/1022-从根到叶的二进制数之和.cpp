#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*1022. 从根到叶的二进制数之和*/
class Solution {
public:
    //遍历每个节点
    int helper(TreeNode* root, vector<int>& vec, int i) {
        if (root == nullptr) {
            return 0;
        }
        i = (i << 1) | root->val;       //这里直接转换成十进制了已经
        if (root->left == nullptr && root->right == nullptr) {
            vec.push_back(i);
            return i;
        }
        else {
            return helper(root->left, vec, i) + helper(root->right, vec, i);
        }

    }
    /*int toTen(int num) {
        int res = 0;
        while () {

        }
    }*/
    int sumRootToLeaf(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return  root->val;
        }
        vector<int> vec;        //用来存储每个节点
        int res = helper(root, vec, 0);
        for (auto& num : vec) {
            cout << num << "  ";
        }
        return res;
    }
};