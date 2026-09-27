#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        
        // Sort first to start from the smallest permutation
        std::sort(nums.begin(), nums.end());
        
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        
        return result;
    }
};
