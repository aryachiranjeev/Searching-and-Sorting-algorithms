#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int arr[],int n){
    for (int j=0;j<n-1;j++){
        for(int i=0;i<n-j-1;i++){
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
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
    bubble_sort(arr,n);
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
