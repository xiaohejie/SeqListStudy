#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	105-��ǰ���������������й��������
		ǰ�����е�ͷ����Ƕ������ĸ��ڵ�
		���Ը��ݸ��ڵ�����������������������
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
	unordered_map<int, int> map;
	int len;
public:
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if (pl > pr || il > ir) {
			return nullptr;
		}
		//��¼��preorder[pl]Ϊ���ڵ�Ķ��������������ж���Ԫ��
		int count = map[preorder[pl]] - il;
		//����������
		TreeNode* root = new TreeNode(preorder[pl]);
		root->left = build(preorder, inorder, pl + 1, pl + count, il, il + count - 1);
		root->right = build(preorder, inorder, pl + count + 1, pr, il + count + 1, ir);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		len = preorder.size();
		for (int i = 0; i < len; i++) {
			//��¼�Ըýڵ�Ϊ���ڵ���������ĸ���
			map[inorder[i]] = i;
		}
		//����������
		return build(preorder, inorder, 0, len - 1, 0, len - 1);
	}
};