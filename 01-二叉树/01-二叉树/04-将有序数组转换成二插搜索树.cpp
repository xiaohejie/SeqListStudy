#include <iostream>
using namespace std;
/*
	����������ת����һ�ø߶�ƽ��Ķ���������
	���������������ڵ��ֵ������������������һ���ڵ��ֵ��С�����ҽڵ�������һ�ڵ��ֵ��
					��һ���������ڶ���������е�ÿһ���ڵ㡣
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};