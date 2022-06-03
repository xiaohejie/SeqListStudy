#include<iostream>
#include<vector>
using namespace std;
/*
	二叉树的最近公共祖先：
		若root是p和q的公共祖先：
			（1）p和q在root的子树中，且分列在root的两侧
			（2）p=root，且q在root的左或右子树中
			（3）q=root，且p在root的左或右子树中

*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//当root为空、p或q为root，则说明最近公共祖先就是root
		if (root == nullptr || root == p || root == q) {
			return root;
		}
		//分别从左右子树找p和q
		TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		//如果left为空，说明p和q不在左子树中，就返回右子树
		if (left == nullptr) {
			return right;
		}
		////如果right为空，说明p和q不在右子树中，就返回左子树
		if (right == nullptr) {
			return left;
		}
		//若left和right都不为空，就说明左右子树中都存在p和q（各一个），就返回root
		return root;
	}
};