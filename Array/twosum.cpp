#include <bits/stdc++.h>
using namespace std;

//in brute foce approach will use one outer loop and one inner 
//check every pairs does it equal to target if we found then return true and break
//if not after complete iteration return false
// time complexity will be O(n^2) and space O(1)
bool solvebrute(vector<int> &nums,int target){
     for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                return true;
            }
        }
     }
     return false;
}


//int optimal approach we will use the hash map to store previous element 
//approach is simple we check current element and how much it require
// if it is avaiable in hash map that is the answer else
// we stored current element in hashmap if no found return empty

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) { //check whether required element present
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    
}

// Optimal Approach:
// First, sort the array.
// Use two pointers: one starting from the beginning (left)
// and the other from the end (right).
// Calculate the sum of the two elements.
// - If the sum equals the target, return true.
// - If the sum is greater than the target, move the right pointer left.
// - Otherwise, move the left pointer right.
// If no such pair is found, return false.
// time complexity will be O(nlogn) for sorting + logn for left right pointer


bool solveoptimal(vector<int>arr,int target){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int left=0;
    int right=n-1;
   while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum > target)
            right--;
        else
            left++;
    }

    
    return false;
}


int main(){
   
    vector<int>nums={1,3,5,9,2};
     int target=80;
    bool ans=solvebrute(nums,target);
    vector<int> answer=twoSum(nums,target);
  
    cout<<endl;
    cout << "Brute Force: " << (ans ? "True" : "False") << endl;
       if(ans){
        cout<<"indices:";
      for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}


}
