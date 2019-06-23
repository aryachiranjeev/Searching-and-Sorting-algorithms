#include<iostream>
using namespace std;

//Queue using array
class Queue{
public:
	int rear,front;
	int capacity;
	int *arr;

	Queue(int c){
		front=rear=0;
		capacity=c;
		arr=new int;
	}

	int enque(int val);
	int dequeue();
	void printQueue();
	~Queue(){
	 
	 	delete[] arr;
	 }
};

int Queue :: enque(int val){
	if (capacity==rear)
		{
			cout<<"Queue is full"<<endl;
			return 0;
		}

	else{
		arr[rear]=val;
		rear++;
	}
	return 0;
}

int Queue :: dequeue(){
	if(front==rear){
		cout<<"Queue is empty"<<endl;
		return 0;
	}
	else{
		for (int i=0;i<rear-1;i++){
			arr[i]=arr[i+1];
		}
		rear--;
	}
	return 0;
}

void Queue :: printQueue(){
	if(front==rear){
		cout<<"Queue is empty\n";
	}

	else{
		for(int i=0;i<rear;i++){
			cout<<arr[i]<<" ";
		}
	}

}

int main(){
	Queue q(5);
	q.enque(5);
	q.enque(6);
	q.enque(7);
	q.enque(8);
	q.enque(9);
	q.printQueue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.printQueue();
	q.dequeue();
	q.dequeue();
	q.printQueue();
	  
	return 0;

}


