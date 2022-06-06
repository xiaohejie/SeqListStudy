#include<iostream>
#include<string>
#include<vector>
#include<cstring>
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
	//前序遍历二插搜索树
	void preorder(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		vec.push_back(root->val);
		preorder(root->left, vec);
		preorder(root->right, vec);
	}
	//将前面得到的前序遍历的解转化成字符串
	string vectorToString(vector<int>& res) {
		string ans = "";
		if (res.size() == 0) {
			return ans;
		}
		for (int i = 0; i < res.size() - 1; i++) {
			ans += to_string(res[i]);
			ans += ",";
		}
		ans += to_string(res[res.size() - 1]);
		return ans;
	}
	//序列化：将二插搜索树变成字符串
	string serialize(TreeNode* root) {
		vector<int> vec;
		preorder(root, vec);
		return vectorToString(vec);
	}
	//反序列化：将字符串变成二插搜索树
	//先将字符串转化成vector
	void split(string data, vector<int>& vec) {
		int i = 0, idx = 0; 
		while (i < data.size()) {
			if (data[i] == ',') {
				//截取字符串
				string tmp = data.substr(idx, i - idx);
				vec.push_back(atoi(tmp.c_str()));
				idx = i + 1;
			}
			i++;
		}
		//最后加上
		string tmp = data.substr(idx + 1);
		vec.push_back(atoi(tmp.c_str()));
	}
	TreeNode* deserialize(string data) {
		if (data == "") {
			return nullptr;
		}
		vector<int> vec;
		//将字符串拆解
		split(data, vec);
		//构建二插搜索树
		TreeNode* node = new TreeNode(vec[0]);
		//将左右子树找出：根据大小
		vector<int>lVec, rVec;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] < vec[0]) {
				lVec.push_back(vec[i]);
			}
			else if (vec[i] > vec[0]) {
				rVec.push_back(vec[i]);
			}
		}
		node->left  = deserialize(vectorToString(lVec));
		node->right = deserialize(vectorToString(rVec));
		return node;
	}
};