#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            // Either continue the existing subarray or start a new one from the current element
            current_sum = std::max(nums[i], current_sum + nums[i]);
            max_sum = std::max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};
