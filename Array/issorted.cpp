#include <bits/stdc++.h>
using namespace std;
//brute force time complexity will lead to O(n^2) space O(1)
// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If any element is smaller than the previous one, return false
            if (arr[j] < arr[i]) 
                return false;
        }
    }

    return true; // Return true if no unsorted elements are found
}

//optimal approach 
// as we know from previous approach if any element is smaller then previous then return false
//so we can do this linearly with O(n) time complexity
bool issortedoptimal(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {11, 2, 3, 4, 5}, n = 5;
    bool ans = issortedoptimal(arr, n);
    
    // Output result
    if (ans) cout << "True" << endl;
    else cout << "False" << endl;
    
    return 0;
}
