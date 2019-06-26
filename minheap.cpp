#include<iostream>
#include<climits>
using namespace std;

void swap(int* a,int* b);

class MinHeap{
private:
	int *harr;
	int capacity;
	int heap_size;
public:
	MinHeap(int cap){
		heap_size=0;
		int capacity=cap;
		harr=new int[cap];
	}
	int parent(int i){
		return (i-1)/2;
	}

	int left_child(int i){
		return (2*i)+1;
	}

	int right_child(int i){
		return (2*i)+2;
	}

	// to heapify a subtree with the root at given index 

	void MinHeapify(int i);

	int Extract_min_element();

	// Decreases key value of key at index i to new_val 
	void DecreaseKey(int i,int new_val);

	// Returns the minimum key (key at root) from min heap
	int GetMin(){
		return harr[0];
	}

	// Deletes a key stored at index i 
	void DeleteKey(int i);

	// Insert a new key 'k'
	void InsertKey(int k);


};


void swap(int *a,int *b){
 	int temp=*a;
 	*a=*b;
 	*b=temp;
}

//Inserting element in heap
void MinHeap :: InsertKey(int k){
	if(heap_size==capacity){
		cout<<"OVERFLOW CONDITION OCCURED"<<endl;
	}

	heap_size++;
	//insert element at last element of heap
	int i=heap_size-1;
	harr[i]=k;

	while(i!=0 && harr[parent(i)] > harr[i]){
		swap(&harr[parent(i)],&harr[i]);
		i=parent(i);
	}

}

void MinHeap :: MinHeapify(int i){
	int left=left_child(i);
	int right=right_child(i);
	int smallest=i;

	if(left<heap_size && harr[left]<harr[i]){
		smallest=i;
	}

	if(right<heap_size && harr[right]<harr[smallest]){
		smallest=right;
	}

	if(smallest!=i){
		swap(&harr[smallest],&harr[i]);
		MinHeapify(smallest);
	}
}

void MinHeap :: DecreaseKey(int i,int new_val){
	harr[i]=new_val;

	while(i!=0 && harr[parent(i)] > harr[i]){
		swap(&harr[parent(i)],&harr[i]);
		i=parent(i);
	}

}

int MinHeap :: Extract_min_element(){

	if(heap_size<=0){
		return INT_MAX;
	}

	if(heap_size==1){
		heap_size--;
		return harr[0];
	}

	int element_to_be_removed=harr[0];
	harr[0]=harr[heap_size-1];
	heap_size--;
	MinHeapify(0);
	return element_to_be_removed; 
} 

void MinHeap :: DeleteKey(int i){
	DecreaseKey(i,INT_MIN);
	Extract_min_element();
}

int main(){
	
    MinHeap h(11); 
    h.InsertKey(3); 
    h.InsertKey(2); 
    h.DeleteKey(1); 
    h.InsertKey(15); 
    h.InsertKey(5); 
    h.InsertKey(4); 
    h.InsertKey(45); 
    cout << h.Extract_min_element() << " "; 
    cout << h.GetMin() << " "; 
    h.DecreaseKey(2, 1); 
    cout << h.GetMin(); 
    return 0;
}
