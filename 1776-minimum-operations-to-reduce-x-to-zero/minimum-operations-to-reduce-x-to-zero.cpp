#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // The remaining elements inside the array must sum up to target
        long long target = total_sum - x;
        
        // If the sum of all elements is less than x, it's impossible
        if (target < 0) return -1;
        // If the sum equals x, we must remove all elements
        if (target == 0) return nums.size();
        
        int max_len = -1;
        long long current_sum = 0;
        int left = 0;
        
        // Sliding window to find the longest subarray that sums to target
        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];
            
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            if (current_sum == target) {
                max_len = std::max(max_len, right - left + 1);
            }
        }
        
        // If no valid subarray is found, return -1; otherwise, return remaining elements count
        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};
