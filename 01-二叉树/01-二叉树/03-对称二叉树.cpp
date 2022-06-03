#include <iostream>
using namespace std;
/*
	对称二叉树：
		（1）根节点的左右子树都为空，返回true
		（2）根节点的左右子树只有一个为空，返回false
		（2）左右子树的val相等，并且递归：helper(p->left, q->right) && helper(p->right, q->left)
*/