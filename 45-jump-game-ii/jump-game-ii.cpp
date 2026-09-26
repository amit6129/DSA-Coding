#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We do not need to process the last element because once we 
        // reach or pass it, we are already at the destination.
        for (int i = 0; i < n - 1; ++i) {
            // Update the maximum reach possible from the current position
            farthest = std::max(farthest, i + nums[i]);
            
            // If we have reached the end of the current jump's range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // Optimization: If the current range already covers the last index, break early
                if (current_end >= n - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};
