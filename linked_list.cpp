#include<iostream>
using namespace std;
 
class Node{
public:
	int data;
	Node *next;
};

Node* createlinkedlist(){

	int a;
	Node* head;

	Node *newnode = new Node(); 
	cin>>a;
	if(a==-1) {cout<<"no insertion";return NULL;};

	newnode->data=a;
	head = newnode;
	Node* temp = head;
	cin>>a;
	while(a!=-1){

		Node* newnode2= new Node();
		newnode2->data=a;
		temp->next=newnode2;
		temp=temp->next;
		cin>>a;

	}

	return head;
} 

Node * RecursiveInsertion(Node * head, int val, int pos){
	if(pos==0){
		Node *newnode=new Node();
		newnode->data=val;
		newnode->next=head;

		return newnode;
	} 

	Node *smallans=RecursiveInsertion(head->next,val,pos-1);
	head->next=smallans;
	return head;
}

void PrintingLinkedList(Node* head){

	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main(){
	Node* head;
	head=createlinkedlist();
	head=RecursiveInsertion(head,10,2);
	PrintingLinkedList(head);
	
}