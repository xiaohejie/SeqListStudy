#include<iostream>
#include<queue>
using namespace std;
/*
	919. 完全二叉树插入器
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class CBTInserter {
private:
	TreeNode* root;
	queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
		this->root = root;

		queue<TreeNode*> qu;
		qu.push(root);

		while (!qu.empty()) {
			TreeNode* node = qu.front();
			qu.pop();
			if (node->left) {
				qu.push(node->left);
			}
			if (node->right) {
				qu.push(node->right);
			}
			if (!(node->left&&node->right)) {
				q.push(node);
			}
		}
    }

    int insert(int val) {
		TreeNode* child = new TreeNode(val);
		TreeNode* node = q.front(); 
		int ret = node->val;
		if (!node->left) {
			node->left = child;
		}
		else {
			node->right = child;
			q.pop();
		}
		q.push(child);
		return ret;
    }

    TreeNode* get_root() {
		return root;
    }
};