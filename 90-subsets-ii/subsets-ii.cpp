#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        result.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicate elements at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        // Sort the array to group duplicates together
        std::sort(nums.begin(), nums.end());
        backtrack(nums, 0, path, result);
        return result;
    }
};
