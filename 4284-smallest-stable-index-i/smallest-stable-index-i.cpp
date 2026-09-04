#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Precompute suffix minimums
        // min_suffix[i] stores the minimum value in nums[i..n-1]
        std::vector<int> min_suffix(n);
        min_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = std::min(nums[i], min_suffix[i + 1]);
        }

        // Step 2: Traverse from left to right to find the first stable index
        int current_max = nums[0];
        for (int i = 0; i < n; ++i) {
            current_max = std::max(current_max, nums[i]);
            
            // Cast to long long to prevent integer overflow since nums[i] <= 10^9
            long long instability_score = (long long)current_max - min_suffix[i];
            
            // Return the very first index that meets the requirement
            if (instability_score <= k) {
                return i;
            }
        }

        return -1;
    }
};

