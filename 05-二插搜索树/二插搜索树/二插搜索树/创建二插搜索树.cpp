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

//��������������
void insert(Tree* tree, int val){
	//��val�����һ����
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
				//������
				if (temp->left == NULL) {
					temp->left = node;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				//������
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

//ǰ�����򣬺������
void preorder(Node* node) {
	if (node != nullptr) {
		cout << node->data << endl;
		preorder(node->left);
		preorder(node->right);
	}
}
//�����ĸ߶�
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

//������һ���������ֵ(����val������0)
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
	cout << "�߶�Ϊ��" << get_height(tree->root) << endl;
	cout << "���ֵΪ��" << getMax(tree->root) << endl;
	return 0;
}