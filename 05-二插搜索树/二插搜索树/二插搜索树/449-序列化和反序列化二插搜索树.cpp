#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
/*
	���л��ͷ����л�������������
		���������������л�Ϊ�ַ���
		���ַ��������л��ɶ���������
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
	//ǰ���������������
	void preorder(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		vec.push_back(root->val);
		preorder(root->left, vec);
		preorder(root->right, vec);
	}
	//��ǰ��õ���ǰ������Ľ�ת�����ַ���
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
	//���л�������������������ַ���
	string serialize(TreeNode* root) {
		vector<int> vec;
		preorder(root, vec);
		return vectorToString(vec);
	}
	//�����л������ַ�����ɶ���������
	//�Ƚ��ַ���ת����vector
	void split(string data, vector<int>& vec) {
		int i = 0, idx = 0; 
		while (i < data.size()) {
			if (data[i] == ',') {
				//��ȡ�ַ���
				string tmp = data.substr(idx, i - idx);
				vec.push_back(atoi(tmp.c_str()));
				idx = i + 1;
			}
			i++;
		}
		//������
		string tmp = data.substr(idx + 1);
		vec.push_back(atoi(tmp.c_str()));
	}
	TreeNode* deserialize(string data) {
		if (data == "") {
			return nullptr;
		}
		vector<int> vec;
		//���ַ������
		split(data, vec);
		//��������������
		TreeNode* node = new TreeNode(vec[0]);
		//�����������ҳ������ݴ�С
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