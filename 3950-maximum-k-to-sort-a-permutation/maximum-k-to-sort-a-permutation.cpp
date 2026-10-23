#include <vector>

class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        for (int i = 0; i < n; ++i) {
            // Check if the element is out of its sorted position
            if (nums[i] != i) {
                if (k == -1) {
                    k = nums[i]; // Initialize k with the first displaced element
                } else {
                    k &= nums[i]; // Bitwise AND with subsequent displaced elements
                }
            }
        }

        // If the array was already sorted, k remains -1, return 0
        return (k == -1) ? 0 : k;
    }
};
