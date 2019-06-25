#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node*left;
	Node* right;
};

Node* NewNode(int data){
	Node* newnode=new Node();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;

	return newnode;
}

int main(){

	Node* root=NewNode(1);
	root->left=NewNode(2);
	root->right=NewNode(3);

	root->left->left=NewNode(4);
	root->left->left->right=NewNode(5);
	return 0;
}
