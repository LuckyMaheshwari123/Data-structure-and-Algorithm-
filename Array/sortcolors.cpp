
#include <bits/stdc++.h>
using namespace std;
// Intuition
// Since the array contains only 0, 1, and 2, we can treat it as a normal unsorted array and sort it using a simple comparison-based sorting technique. Selection sort works by repeatedly placing the smallest element at the correct position.

// Approach
// Iterate through the array.
// For each position i, find the minimum element in the remaining unsorted part.
// Swap it with the element at position i.
// Repeat this process until the entire array is sorted.
// This is a direct implementation of Selection Sort.

// Complexity
// Time complexity: O(n 
// 2
// )
// We use two nested loops to find the minimum element for each position.

// Space complexity: O(1)
// Sorting is done in-place without using extra space.



    void sortColors(vector<int>& nums) {
    int n = nums.size
    ();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // find minimum element in remaining array
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        // swap if a smaller element is found
        if (minIndex != i) {
            swap(nums[i], nums[minIndex]);
        }
    }
    }

    //second approach is as we know array contain only 0 1 and 2 so 
    // first count 0 and 1 and 2 then place how many ocurrences of element starting from 0
    // time complexity will be O(2n) on for counting and second for placing
    //space complexity is O(1);

    void sortcolorsbetter(vector<int>&nums){
        int zc=0;
        int oc=0;
        int tc=0;
        //counting occurences
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zc++;
            else if(nums[i]==1) oc++;
            else{
                tc++;
            }
        }
        
        //placing elements
        for(int i=0;i<zc;i++){
            nums[i]=0;
        }
        for(int i=zc;i<zc+oc;i++){
            nums[i]=1;
        }
        for(int i=zc+oc;i<nums.size();i++){
            nums[i]=2;
        }

    }
// optimal apporoach use dutch National Flag (DNF) Algorithm 

void sortcolorOptimal(vector<int> &nums){
    int low=0;
    int mid=0;
    int n=nums.size();
    int high=n-1;

        while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }

}

// this is not proper possible wrt to high in standrad and have to build from scratch 
//working on it 
// void sortcolorOptimalh(vector<int> & nums){
//       int low=0;
//       int mid=0;
//       int n=nums.size();
//       int high=n-1;
//       while(mid<=high)
//       if(nums[high]==0){
//          swap(nums[high],nums[low]);
//          low++;
//          high--;
//       }
//       else if(nums[high]==1){
//         swap(nums[high],nums[mid]);
//         mid++;
//       }
//       else{
//           high--;
          
//       }

// }

int main(){
    vector<int> nums={1,2,0,0,1,2,1,0,2,1,1,2,1};
    //sortColors(nums);
    //sortcolorsbetter(nums);
    sortcolorOptimal(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}
