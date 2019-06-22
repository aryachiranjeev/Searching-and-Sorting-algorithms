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
		if(a==-1){
			temp->next=NULL;
		}

	}

	return head;
} 

Node * insertion(Node* head,int val ,int pos){
	Node*temp=head;
	Node* newnode=new Node();
	newnode->data=val;

	
	for(int i=0;i<=pos;i++){
		

		if(pos==0){
		newnode->next=temp;
		head=newnode;
		}

		else if(i==pos-1){
				Node *hello=temp->next;
				temp->next=newnode;
				newnode->next=hello;

		}
		
		temp=temp->next;

	}

    
	return head;
}

Node* deletion(Node* head,int pos){

	Node* temp=head;

	for (int i=0;i<=pos;i++){
		if(pos==0){
			head=head->next;
		}

		Node* prev=temp;
		temp=temp->next;
		if(i==pos-1){
			prev->next=temp->next;
			delete(temp);
		}
	}
	return head;
}

Node* RecursiveDeletion(Node* head, int pos){

	if(pos==0){
		head=head->next;
		return head;
	}
	Node *smallans=RecursiveDeletion(head->next,pos-1);
	head->next=smallans;
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
	cout<<endl;
	cout<<"Printing Linked List:"<<endl;
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main(){
	Node* head;

	head=createlinkedlist();
	PrintingLinkedList(head);
	head=RecursiveInsertion(head,10,2);
	PrintingLinkedList(head);
	head=insertion(head,20,5);
	PrintingLinkedList(head);
	head=deletion(head,3);
	PrintingLinkedList(head);
	head=RecursiveDeletion(head,4);
	PrintingLinkedList(head);
}