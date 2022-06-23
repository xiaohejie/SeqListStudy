#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
/*
	二叉树的层序遍历：
		
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
	//使用队列
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}
		queue<TreeNode*> que;
		//将根节点放进去
		que.push(root);

		while (!que.empty()) {
			vector<int> res;
			int count = que.size();	//记录改成一共有多少个结点
			while (count--) {
				TreeNode* newNode = que.front();
				//将队列的头放进去
				res.push_back(newNode->val);
				//出队列
				que.pop();
				//将该节点的左右结点放进去
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