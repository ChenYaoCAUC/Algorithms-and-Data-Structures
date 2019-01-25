#include<iostream>
using namespace std;
template <typename T>
class BinaryTreeNode {
private:
	T Data;
	BinaryTreeNode *left, *right;
public:
	BinaryTreeNode():left(NULL), right(NULL) {}
	BinaryTreeNode(T Data)
		:Data(Data), left(NULL), right(NULL) {}
		BinaryTreeNode(T Data,BinaryTreeNode *left,BinaryTreeNode *right):Data(Data),left(left),right(right){}
	T getData() {
		return Data;
	}
	BinaryTreeNode*& getLeft() {
		return left;
	}
	BinaryTreeNode*& getRight() {
		return right;
	}
};
template <typename T>
class BinaryTree {
private:
	BinaryTreeNode<T> *root;
	void in(BinaryTreeNode<T> *root) {
		if (root) {
			this->in(root->getLeft());
			cout << root->getData();
			this->in(root->getRight());
		}
	}
	void createBinaryTree(BinaryTreeNode<T>* &root) {
		root = NULL;
		T input;
		cin >> input;
		if (input != '#') {
			root = new BinaryTreeNode<T>(input);
			this->createBinaryTree(root->getLeft());
			this->createBinaryTree(root->getRight());
		}
	}
	void deleteBinaryTree(BinaryTreeNode<T> *&root) {
		if (root == NULL) {
			return;
		}
		this->deleteBinaryTree(root->getLeft());
		this->deleteBinaryTree(root->getRight());
	}
public:
	BinaryTree() {
		createBinaryTree(root);
	}
	~BinaryTree() {
		deleteBinaryTree(root);
	}
	void inOrderTravel() {
		in(root);
	}
};

int main() {
	BinaryTree<char> BT;
	BT.inOrderTravel();
}
