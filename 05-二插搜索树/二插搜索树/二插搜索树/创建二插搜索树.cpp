#include <iostream>
using namespace std;
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;
typedef struct{
	Node* root;
}Tree;

//创建二插搜索树
void insert(Tree* tree, int val){
	//将val打包成一棵树
	Node* node = (Node*)malloc(sizeof(Node));
	node->data  = val;
	node->left  = NULL;
	node->right = NULL;

	if (tree->root == NULL) {
		tree->root = node;
	}
	else {
		Node* temp = tree->root;
		while (temp != NULL) {
			if (val < temp->data) {
				//向左移
				if (temp->left == NULL) {
					temp->left = node;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				//向右移
				if (temp->right == NULL) {
					temp->right = node;
					return;
				}
				else {
					temp = temp->right; 
				}
			}
		}
	}
}

//前序，中序，后序遍历
void preorder(Node* node) {
	if (node != nullptr) {
		cout << node->data << endl;
		preorder(node->left);
		preorder(node->right);
	}
}
//求树的高度
int get_height(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	else{
		int left_h = get_height(node->left);
		int right_h = get_height(node->right);
		int max = left_h;
		if (right_h > max) {
			max = right_h;
		}
		return max + 1;
	}
}

//求任意一棵树的最大值(假设val都大于0)
int getMax(Node* node){
	if (node == NULL) {
		return -1;
	}
	int leftMax = getMax(node->left);
	int rightMax = getMax(node->right);
	int max = node->data;
	if (max < leftMax) {
		max = leftMax;
	}
	if(max < rightMax){
		max = rightMax;
	}
	return max;
}
int main() {
	int arr[] = { 6,3,8,2,5,1,7 };
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	for (int i = 0; i < 7; i++) {
		insert(tree, arr[i]);
	}
	preorder(tree->root);
	cout << "高度为：" << get_height(tree->root) << endl;
	cout << "最大值为：" << getMax(tree->root) << endl;
	return 0;
}