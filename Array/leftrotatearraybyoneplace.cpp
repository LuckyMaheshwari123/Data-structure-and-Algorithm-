#include<bits/stdc++.h>
using namespace std;

//brute force approach
// first we create temp array and store shift element by one place
// then it add first element at last of temp array and print this 
// time compelxity O(N) and space complexity O(N) for temp array


// Function to solve and shift array elements left by one position
void solve(int arr[], int n) {
    int temp[n];  // Create a temporary array to store the shifted elements

    // Shift the elements to the left by one position
    for (int i = 1; i < n; i++) {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];  // The first element moves to the last position

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " "; 
    }
    cout << endl;
}
// in optimal approach work will be in the array 
//we take first element and stored in a variable and left shift the other elements
// and store the first element at last
//this will not need no extra space and space complexity will be O(1) and time O(n)
void rotateoptimal(int arr[],int n){
     int temp=arr[0];
     for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
     }
     arr[n-1]=temp;

}

int main() {
    int n = 5;  
    int arr[] = {1, 2, 3, 4, 5};  

    solve(arr, n);  // Call the solve function to rotate and print the result

    return 0;
}
