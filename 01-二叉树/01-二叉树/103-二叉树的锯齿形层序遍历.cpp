#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
	103-二叉树的锯齿形层序遍历
		在层序遍历的基础上，对二叉树的奇偶性进行判断
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

	}
};