//second largest
// arr - input array
// n - size of array

#include<iostream>
#include<limits.h>
using namespace std;
//INT_MIN=-2147483648 or e^-31
// arr - input array
// n - size of array
int FindSecondLargest(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
 int largest= INT_MIN;
 int second_largest=INT_MIN;
 int i;       
    if(n<=1) return INT_MIN;
    
    else if(n==2 && arr[0]==arr[1]) return INT_MIN;
    
    else{
        largest=arr[0];
        
        for(i=1;i<n;i++){
            if(largest<arr[i]){
                second_largest=largest;
                largest=arr[i];
            }
            if(second_largest<arr[i] && arr[i]!=largest){
                second_largest=arr[i];
            }
            else continue;
        }
        return second_largest;
    }
}

int main(){
int arr[100],n;
cout<<"enter number of elements"<<endl;
cin>>n;
cout<<"enter elements of an array :"<<endl;
for (int i=0;i<n;i++){
cin>>arr[i];
}

int second_largest=FindSecondLargest(arr, n);
cout<<"second_largest:"<<second_largest;
return 0;
}
/*
output:
enter number of elements
8
enter elements of an array :
2 13 4 1 3 6 28 14
second_largest:14
*/
