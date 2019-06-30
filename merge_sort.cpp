#include<iostream>
using namespace std;


void merge(int arr[],int l,int m,int r){

	int size1=m-l+1;
	int size2=r-m;

	int arr1[size1];
	int arr2[size2];

	for (int i=0;i<size1;i++){
		arr1[i]=arr[l+i];
	}

	for (int j=0;j<size2;j++){
		arr2[j]=arr[m+1+j];
	}

	int i=0;
	int j=0;
	int k=l;

	while(i<size1 && j<size2){

		if(arr1[i]<=arr2[j]){
			arr[k]=arr1[i];
			i++;
			k++;
		}

		else{

			arr[k]=arr2[j];
			j++;
			k++;
		}
	}

	while(i<size1){
		arr[k]=arr1[i];
		i++;
		k++;
	}

	while(j<size2){
		arr[k]=arr2[j];
		j++;
		k++;
	}


}

void mergesort(int arr[],int l,int r){

	if(l<r){
		int m=l+(r-l)/2;

		mergesort(arr,l,m);
		mergesort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}


void PrintArray(int arr[],int size){

	for (int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}

}


int main(){

	    int arr[] = {12, 11, 13, 5, 6, 7}; 
	    int size=sizeof(arr)/sizeof(arr[0]);

	    cout<<"print array: "<<endl;
	    PrintArray(arr,size);
	    mergesort(arr,0,size-1);
	    cout<<"\nprint sorted array: "<<endl;
	    PrintArray(arr,size);
	    return 0;
}









