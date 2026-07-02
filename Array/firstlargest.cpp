#include<iostream>
#include <algorithm>//sort function
#include <climits>
using namespace std;

// to solve to find first largest in array the brute force
// sort the array and extract last element that will be the largest
//time complexity of this will be Ologn for sorting when you use effiecient like merge sort
//extra space complexity will be O(1)
int findlargestsort(int arr[],int n){
    sort(arr,arr+n);
    return arr[n-1];
}
//optimal approach this will lead time complexity O(n) and space O(1)
// approach is simple we assume first a our max or we can use int min as our assumed first max 
//then iterate over the array if the current element is greater than max update the max by this 

int findLargestLinear(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int main(){
    int arr[5]={1,3,2,5,9};
    int large=findlargestsort(arr,5);
    int Large=findLargestLinear(arr,5);
    cout<<"The largest element in the array is:"<<Large;
}
