#include<iostream>
#include<climits>
using namespace std;

void swap(int *a,int*b);
class MaxHeap{
private:
	int *harr;
	int capacity;
	int  heap_size;
public:
	
	MaxHeap(int cap){
		heap_size=0;
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

	void InsertKey(int k);
	void DeleteKey(int i);
	int Extract_max_element();
	void DecreaseKey(int i ,int new_val);
	int GetMax(){
		return harr[0];
	}
	void MaxHeapify(int i);
};

void swap(int *a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void MaxHeap :: MaxHeapify(int i){
	int left=left_child(i);
	int right=right_child(i);
	int largest=i;

	if(left<heap_size && harr[left] > harr[largest]){
		largest=left;
	}

	if(right<<heap_size && harr[right] > harr[largest]){
		largest=right;

	}

	if(largest!=i){
		swap(&harr[largest],&harr[i]);
		MaxHeapify(largest);
	}
}

void MaxHeap :: InsertKey(int k){
	if (capacity==heap_size){
		cout<<"OVERFLOW CONDITION OCCURED\n";
		
	}

	heap_size++;
	int i=heap_size-1;
	harr[i]=k;
	while(i!=0 && harr[parent(i) < harr[i]]){
		swap(&harr[i],&harr[parent(i)]);
		i=parent(i);
	}	
 
}

void MaxHeap :: DecreaseKey(int i,int new_val){
	harr[i]=new_val;
	while(i!=0 && harr[parent(i)] < harr[i]){
		swap(&harr[parent(i)], &harr[i]);
		i=parent(i);
	}
}

int MaxHeap :: Extract_max_element(){
	if(heap_size<0){
		return INT_MIN;
	}

	else if(heap_size==1){
		heap_size--;
		return harr[heap_size];
	}

	int element_to_removed=harr[0];
	harr[0]=harr[heap_size-1];
	heap_size--;
	MaxHeapify(0);
	return element_to_removed;
}

void MaxHeap :: DeleteKey(int i){
	DecreaseKey(i,INT_MAX);
	Extract_max_element();
}

int main(){
	MaxHeap h(11);
    h.InsertKey(3); 
    h.InsertKey(2); 
    h.DeleteKey(1); 
    h.InsertKey(15); 
    h.InsertKey(5); 
    h.InsertKey(4); 
    h.InsertKey(45); 
    cout << h.Extract_max_element() << " "; 
    cout << h.GetMax() << " "; 
    h.DecreaseKey(2, 1); 
    cout << h.GetMax(); 
	return 0;
}