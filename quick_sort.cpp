#include<iostream>
using namespace std;


void swap(int *a,int *b){

	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int *a,int s,int e){

	int i=s-1;
	int j=s;
	int pivot=e;

	for (j=s;j<e;j++){

		if(a[j]<=a[pivot]){
			i++;
			swap(&a[i],&a[j]);
		}
	}

	swap(&a[i+1],&a[e]);

	return i+1;
}


void QuickSort(int *a,int s,int e){
	
	if(s>=e){
		return ;
	}

	int p = partition(a,s,e);

	QuickSort(a,s,p-1);
	QuickSort(a,p+1,e);


}

int main(){
	int a[] = {3,4,6,12,2,0,1,5};

	int n=sizeof(a)/sizeof(a[0]);

	QuickSort(a,0,n-1);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}