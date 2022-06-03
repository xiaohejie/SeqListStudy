#include<iostream>
#include<vector>
using namespace std;
/*
	��ͬ�Ķ�����������
		
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
			//����ڵ�����ҽڵ㣬�ͷ��ؿ�
			return { nullptr };
		}
		vector<TreeNode*> ans;
		//ö�����п��еĸ��ڵ�
		for (int i = left; i <= right; i++) {
			//������п��е�����������
			vector<TreeNode*> lNodes = helper(left, i - 1);
			//������п��е��������ļ���
			vector<TreeNode*> rNodes = helper(i + 1, right);
			//ö�����п��������������ϣ�ƴ�ӵ����ڵ��ϣ����һ����
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