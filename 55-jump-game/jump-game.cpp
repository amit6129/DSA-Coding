#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int max_reachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current index is beyond the maximum reachable index, 
            // it means we got stuck at a 0 earlier and cannot proceed.
            if (i > max_reachable) {
                return false;
            }
            
            // Update the furthest index we can reach from the current position
            max_reachable = std::max(max_reachable, i + nums[i]);
            
            // Optimization: If we can already reach or pass the last index, return true
            if (max_reachable >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
