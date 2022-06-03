#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
	序列化和反序列化搜索二叉树：
		将二插搜索树序列化为字符串
		将字符串反序列化成二插搜索树
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
	string vectorToString(vector<int>& res) {

	}
	TreeNode* deserialize(string data) {

	}
};