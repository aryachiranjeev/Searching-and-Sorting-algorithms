// BINARY SEARCH

// arr - input array
// n - size of array
// val - element to be searched
#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int val){
	// Write your code here
    int start=0;
    int end=n-1;
    int mid;
    
    while(start<=end){
        
        mid=(start+end)/2;
        
        if(arr[mid]==val){
            return mid;
            
        }
        
        else if(arr[mid]<val){
            
            start=mid+1;
        }
        
        else if(arr[mid]>val){
            
            end=mid-1;
        }
        
    }
    
    return -1;

}


int main(){
int val,arr[100],n;
cout<<"enter number of elements"<<endl;
cin>>n;
cout<<"enter elements of an array :"<<endl;
for (int i=0;i<n;i++){
cin>>arr[i];
}

cout<<"enter element to be searched:"<<endl;
cin>>val;

int index=BinarySearch(arr, n, val);
cout<<val<<"found at:"<<index;
return 0;
}


/*
output:

enter number of elements
6
enter elements of an array :
1 4 5 6 7 8
enter element to be searched:
6
6found at:3
*/
