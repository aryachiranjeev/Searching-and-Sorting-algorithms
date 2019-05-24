#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
                swap(&arr[min_index],&arr[i]);     
            }
        }
    }
}
void print_array(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main() {
    int arr[100],n;
    cout<<"enter size of array:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"printing initial array:\n";
    print_array(arr,n);
    selection_sort(arr,n);
    cout<<"\nprinting sorted array:";
    print_array(arr,n);
}
/*
Output
enter size of array:
printing initial array:
10 9 8 11 13 1 
printing sorted array:1 8 9 10 11 13 

Input
6
10 9 8 11 13 1 

*/
