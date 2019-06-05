// merge two sorted arrays
#include<iostream>
//arr1 is first array of size1
//arr2 is first array of size2
//ans is result array of size1+size2
void merge(int arr1[], int size1, int arr2[], int size2, int ans[]){

   int i = 0 , j = 0 , k = 0;

   while(i < size1 && j <size2){

       if(arr1[i] < arr2[j]){
           ans[k] = arr1[i];
           i++; k++;
       }

       else{
           ans[k] = arr2[j];
           j++; k++;
       }

   } 

   while(i<size1){
       ans[k] = arr1[i];
       i++; k++;
   }

   while(j<size2){
       ans[k] = arr2[j];
       j++; k++;
   }
   
}

/*
input:
5
1 3 4 7 11
4
2 4 6 13

output:

1 2 3 4 4 6 7 11 13 
*/

