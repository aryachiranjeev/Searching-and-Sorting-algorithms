#include<iostream>
using namespace std;


//SATCK USING ARRAY

#define max 1000

class Stack{
private:
	int top;
public:
	int a[max]; //maximum size of stack
	Stack(){
		top= -1;

	}
	static int count;

	bool push(int x);
	int pop();
	int peek();
	bool isempty();
	void printstack();

};
int Stack::count=0;

bool Stack :: push(int x){

	if(top>=max-1){
		cout<<"stack overflow\n";
		return false;

	}

	else{
		a[++top]=x;
		cout<<x<<"  is pushed into satck ===> ";
		count++;
		cout<<"count:"<<count<<endl;
		return true;
	}
}
int Stack :: pop(){

	count--;
	cout<<"popped ===>  ";
	cout<<"count: "<<count<<endl;
	if(top<0){
		cout<<"stack underflow\n";
		return 0;
	}
	else{
		int x=a[top--];
		return x;
	}
}

int Stack :: peek(){
	if(top<0){
		cout<<"stack is empty\n";
		return 0;

	}

	else{
		int x=a[top];
		return x;
	}
}

bool Stack :: isempty(){
	return (top<0);
}

void Stack :: printstack(){
	for(int i=0;i<count;i++){
		cout<<a[i]<<" ";
	}
}
/*
int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(5);
	s.push(10);
	s.push(190);
	s.pop();
	s.push(2000);
	cout<<s.isempty()<<"\n";
	s.pop();
	cout<<"element at top is:"<<s.peek()<<endl;
	s.pop();
	s.pop();
	cout<<"element at top is:"<<s.peek()<<endl;
	cout<<s.isempty()<<endl;
	s.push(100000);
	s.printstack();

}
*/

//STACK USING LINKED LIST

class StackNode{
public:
	int data;
	StackNode * next;
	//void printstack(StackNode** head);
};



void printstack(StackNode** head){
	StackNode *temp=*head;
	cout<<"printing stack elements:  "<<endl;
	while(temp!=NULL){
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
	}
}


StackNode* newNode(int val) 
{ 
    StackNode* stackNode = new StackNode(); 
    stackNode->data = val; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(StackNode* head) 
{ 
    return !head; 
} 
  
void push(StackNode** head, int val) 
{ 
    StackNode* stackNode = newNode(val); 
    stackNode->next = *head; 
    *head = stackNode; 
    cout << val << " is pushed into stack\n"; 
} 
  
int pop(StackNode **head){
	
	if(isEmpty(*head)){
		cout<<"stack underflow"<<endl;
		return 0;
	}

	StackNode* temp=*head;
	*head=(*head)->next;
	int x=temp->data;
	delete(temp);
	return x;
}

int peek(StackNode *head){
	if(isEmpty(head)){
		cout<<"empty stack"<<endl;
		return 0;
	}
	return head->data;
}

int main(){

	cout<<"STACK USING ARRAY"<<endl;

	Stack s;
	s.push(1);
	s.push(2);
	s.push(5);
	s.push(10);
	s.push(190);
	s.pop();
	s.push(2000);
	cout<<s.isempty()<<"\n";
	s.pop();
	cout<<"element at top is:"<<s.peek()<<endl;
	s.pop();
	s.pop();
	cout<<"element at top is:"<<s.peek()<<endl;
	cout<<s.isempty()<<endl;
	s.push(100000);
	s.printstack();

cout<<"\n\n\nSTACK USING LINKED LIST"<<endl;

StackNode* head=NULL;
push(&head,10);
//printstack(&head);
push(&head,20);
push(&head,1001);
push(&head,50);
printstack(&head);
cout << "Top element is " << peek(head) << endl; 
cout << pop(&head) << "  is popped from stack\n"; 
printstack(&head);
cout << pop(&head) << "  is popped from stack\n"; 
printstack(&head);
cout << "Top element is " << peek(head) << endl; 
cout << pop(&head) << "  is popped from stack\n"; 
printstack(&head);
cout << "Top element is " << peek(head) << endl; 
cout << pop(&head) << "  is popped from stack\n"; 
printstack(&head);
cout << "Top element is " << peek(head) << endl; 

}