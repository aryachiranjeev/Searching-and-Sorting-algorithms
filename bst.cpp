#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

};

node* NewNode(int val){
	node* newnode=new node();
	newnode->data=val;
	newnode->left=newnode->right=NULL;
	return newnode;
	}

node* insert(node* Node,int data){

	if(Node==NULL)
		return NewNode(data);
	
	else if(data < Node->data)
		Node->left=insert(Node->left,data);
	
	

	else if(data > Node->data)
		Node->right=insert(Node->right,data);
	
	

	return Node;
}

void InOrder(node* root){

	if(root!=NULL){
		InOrder(root->left);
		cout<<root->data<<" ";
		InOrder(root->right);
	}

} 

void PreOrder(node* root){
	
	if(root!=NULL){
		cout<<root->data<<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}

} 

void PostOrder(node* root){
	
	if(root!=NULL){
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<" ";
	}

} 



int main(){
	node* root=NULL;
	root=insert(root,4);
	insert(root,10);
	insert(root,1);
	insert(root,0);
	insert(root,6);
	insert(root,5);
	insert(root,3);
	cout<<"InOrder:\n";
	InOrder(root);
	cout<<"\nPreOrder:\n";
	PreOrder(root);
	cout<<"\nPostOrder:\n";
	PostOrder(root);
	return 0;
}

