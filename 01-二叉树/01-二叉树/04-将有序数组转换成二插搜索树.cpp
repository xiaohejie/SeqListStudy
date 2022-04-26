#include <iostream>
using namespace std;
/*
	将有序数组转换成一棵高度平衡的二插搜索树
	二插搜索树：根节点的值大于其左子树中任意一个节点的值，小于其右节点中任意一节点的值，
					这一规则适用于二叉查找树中的每一个节点。
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};