#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // This pointer tracks the position for non-val elements
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is not the target value
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move it to the front
                k++;               // Increment the count of valid elements
            }
        }
        
        return k; // k is the number of elements not equal to val
    }
};
