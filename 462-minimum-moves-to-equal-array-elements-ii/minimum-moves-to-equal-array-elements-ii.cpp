#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        // Step 1: Sort the array to easily find the median
        std::sort(nums.begin(), nums.end());
        
        // Step 2: The median is at the middle index
        int median = nums[nums.size() / 2];
        
        // Step 3: Calculate the total moves required to reach the median
        int moves = 0;
        for (int num : nums) {
            moves += std::abs(num - median);
        }
        
        return moves;
    }
};
