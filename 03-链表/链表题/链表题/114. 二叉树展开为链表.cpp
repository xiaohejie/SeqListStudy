#include<iostream>
#include<vector>
using namespace std;
/*
	114. ������չ��Ϊ����ʹ��O(1)�Ķ���ռ䣩:
			���жϸýڵ����������û�н��
				�еĻ����ҳ��������ڵ�����ҽ��
				�����ҽڵ�ĵ����������ϵ�ǰ�ڵ��������
				��ǰ�ڵ����������Ϊ�������ڵ�
				��ǰ�ڵ����������Ϊ��
			Ȼ���ڽ���ǰ�ڵ��Ϊǰһ���ڵ���ҽڵ㣨�������Ѿ���Ϊ�գ�
		
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
	void preorder(TreeNode* root, vector<TreeNode*>& vec) {
		if (root == nullptr) {
			return;
		}
		vec.push_back(root);
		preorder(root->left, vec);
		preorder(root->right, vec);
	}
	void flatten(TreeNode* root) {
		vector<TreeNode*> vec;		//����װ�ڵ�
		//�����������
		preorder(root, vec);		//����㰴����������洢����
		//Ȼ�������¹�������
		for (int i = 1; i < vec.size(); i++) {
			TreeNode* prev = vec.at(i - 1), * curr = vec.at(i);
			prev->left = nullptr;
			prev->right = curr;
		}
	}
};