#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	508-出现次数最多的子树元素和
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
	vector<int> findFrequentTreeSum(TreeNode* root) {

	}
};