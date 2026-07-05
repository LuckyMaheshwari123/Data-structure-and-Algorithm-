// # Intuition
// Each person's height is unique, so we can map every height to its corresponding name. After sorting the heights in descending order, we can rebuild the answer by retrieving the names associated with the sorted heights.

// # Approach
// - Store the mapping from each height to its corresponding name using a hash map.
// - Sort the `heights` array in descending order.
// - Traverse the sorted heights and replace each position in the `names` array with the name mapped to that height.
// - Return the reordered `names` array.

// # Complexity
// - Time complexity:
//   - **O(n log n)**, where sorting the heights takes `O(n log n)` and the hash map operations take `O(n)`.

// - Space complexity:
//   - **O(n)**, for storing the height-to-name mapping.

// # Code
// ```cpp []
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> mapping;

        for (int i = 0; i < n; ++i) {
            mapping[heights[i]] = names[i];
        }

        sort(heights.rbegin(), heights.rend());

        for (int i = 0; i < n; ++i) {
            names[i] = mapping[heights[i]];
        }

        return names;
    }
};
```
