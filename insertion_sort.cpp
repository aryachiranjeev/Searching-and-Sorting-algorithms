//insertion sort
// arr - input array
// n - size of array
#include<iostream>
void InsertionSort(int arr[], int n){
	// Write your code here
int i,temp,j;
for(i=1;i<n;i++){
    
    temp=arr[i];
    j=i-1;
    
    while(j>=0 && arr[j]>temp){
        
        arr[j+1]=arr[j];
        j=j-1;
     }
    arr[j+1]=temp;
}    
}

