#include<iostream>
#include<vector>
using namespace std;
/*
	814. ¶þ²æÊ÷¼ôÖ¦
		Ê¹ÓÃµÝ¹é
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
	TreeNode* pruneTree(TreeNode* root) {
	}
};