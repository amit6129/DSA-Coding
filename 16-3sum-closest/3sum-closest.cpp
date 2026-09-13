#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to efficiently apply the two-pointer technique
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize closestSum with the sum of the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            // Optional optimization: skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If an exact match is found, return it immediately
                if (currentSum == target) {
                    return currentSum;
                }
                
                // Update closestSum if the current loop's sum is closer to target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on the sum relative to the target
                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return closestSum;
    }
};
