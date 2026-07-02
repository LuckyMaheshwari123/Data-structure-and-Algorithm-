#include<iostream>
#include <algorithm>//sort function
#include <climits>
using namespace std;

//first approach using sort function as we know as element is largest 
// but for second large we have to check lineary does it is equal to 
//first large or not if not then this is second large
//the worst time complexity overall will be O(logn) for sorting + O(n) for comparing

int slargesort(int arr[], int n) {
    if (n < 2) return INT_MIN; // or handle error

    sort(arr, arr + n);

    int largest = arr[n - 1];
    int secondmax = INT_MIN;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != largest) {
            secondmax = arr[i];
            break;
        }
    }

    return secondmax;
}

// second approach will be first find the first max using linear approach
// on the  do second pass  and compare first max will current element if it is less than 
//first max then store as second max
// over all time complexity will be O(2N)
int findslargest2pass(int arr[],int n){
     if (n < 2) return INT_MIN;
    int maxval=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxval){
            maxval=arr[i];
        }
    }
   //second pass 
   int secondMax=INT_MIN;
   for(int i=0;i<n;i++){
       if(arr[i]>secondMax && arr[i]<maxval){
        secondMax=arr[i];
       }
   }
    return secondMax;
}

// This is optimal approach this will find second max in O(n) time complexity
// approach we are taking of both first max and second max at a time 
// combine above 2 passes in single pass
int slargestoptimal(int arr[],int n){
    if(n<2) return INT_MIN;
    int maxval=arr[0];
    
    int smax=INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>maxval){
            smax=maxval;
            maxval=arr[i];
        }
        else if(arr[i]<maxval && arr[i]>smax){
            smax=arr[i];
        }
    }
    return smax;
}

int main(){
    int arr[5]={1,3,2,5,9};
    int slarge=slargestoptimal(arr,5);
    cout<<"The second largest element in the array is:"<<slarge;
}


