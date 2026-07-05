// # Intuition
// Since the majority element appears more than `⌊n / 2⌋` times, we can count the frequency of each element and then find the one whose frequency exceeds `n / 2`.

// # Approach
// - Use an `unordered_map` to store the frequency of each element.
// - Traverse the array and increment the count of each number in the map.
// - Compute `n / 2`.
// - Iterate through the map and return the element whose frequency is greater than `n / 2`.
// - The problem guarantees that a majority element always exists.

// # Complexity
// - Time complexity:
//   - **O(n)**, where `n` is the size of the array.

// - Space complexity:
//   - **O(n)**, for storing the frequency of elements in the hash map.

// # Code
// ```cpp []
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        n = n / 2;

        for (auto x : m) {
            if (x.second > n) {
                return x.first;
            }
        }

        return 0;
    }
};
```
