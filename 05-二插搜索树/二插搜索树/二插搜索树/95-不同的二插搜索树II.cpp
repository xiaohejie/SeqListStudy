#include<iostream>
#include<vector>
using namespace std;
/*
	不同的二插搜索树：
		
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
	vector<TreeNode*> generateTrees(int n) {
		return helper(1, n);
	}
	vector<TreeNode*> helper(int left, int right) {
		if (left > right) {
			//当左节点大于右节点，就返回空
			return { nullptr };
		}
		vector<TreeNode*> ans;
		//枚举所有可行的根节点
		for (int i = left; i <= right; i++) {
			//获得所有可行的左子树集合
			vector<TreeNode*> lNodes = helper(left, i - 1);
			//获得所有可行的右子树的集合
			vector<TreeNode*> rNodes = helper(i + 1, right);
			//枚举所有可行左右子树集合，拼接到根节点上，组成一棵树
			for (int m = 0; m < lNodes.size(); m++) {
				for (int n = 0; n < rNodes.size(); n++) {
					TreeNode* node = new TreeNode(i);
					node->left = lNodes[m];
					node->right = rNodes[n];
					ans.push_back(node);
				}
			}
		}
		return ans;
	}
};