#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Precompute the minimums from the right (suffix minimums)
        std::vector<int> min_right(n);
        min_right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_right[i] = std::min(nums[i], min_right[i + 1]);
        }

        // Step 2: Iterate from left to right, maintaining the prefix maximum
        int max_left = nums[0];
        for (int i = 0; i < n; ++i) {
            max_left = std::max(max_left, nums[i]);

            // Step 3: Check the stability score
            if (max_left - min_right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
