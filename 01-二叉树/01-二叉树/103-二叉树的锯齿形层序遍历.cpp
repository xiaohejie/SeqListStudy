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
	103-�������ľ���β������
		�ڲ�������Ļ����ϣ��Զ���������ż�Խ����ж�
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

	}
};