#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        // Sort the array in non-decreasing order
        std::sort(nums.begin(), nums.end());
        
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
