#include <iostream>
#include<string>
using namespace std;

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
	string tree2str(TreeNode* root) {
		if (root == NULL) {
			return "";
		}
		if (root->left == nullptr && root->right == nullptr) {
			return to_string(root->val);
		}
		//如果右子树为空，就可以直接访问左子树
		if (root->right == nullptr) {
			return to_string(root->val) + "(" + tree2str(root->left) + ")";
		}
		//但是左子树为空的话，不能直接访问右子树，因为中间要加上()，这样就和左右子树都不为空一样，所以两者合并
		return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
	}
};