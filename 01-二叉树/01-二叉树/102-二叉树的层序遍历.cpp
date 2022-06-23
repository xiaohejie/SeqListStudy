#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
/*
	�������Ĳ��������
		
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
	//ʹ�ö���
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}
		queue<TreeNode*> que;
		//�����ڵ�Ž�ȥ
		que.push(root);

		while (!que.empty()) {
			vector<int> res;
			int count = que.size();	//��¼�ĳ�һ���ж��ٸ����
			while (count--) {
				TreeNode* newNode = que.front();
				//�����е�ͷ�Ž�ȥ
				res.push_back(newNode->val);
				//������
				que.pop();
				//���ýڵ�����ҽ��Ž�ȥ
				if (newNode->left) { que.push(newNode->left);
				}
				if (newNode->right) { que.push(newNode->right);
				}
			}
			
			ans.push_back(res);
		}
		return ans;
	}
};