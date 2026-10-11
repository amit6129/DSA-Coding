#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentSubset;
        
        // Start backtracking from index 0
        backtrack(0, nums, currentSubset, result);
        
        return result;
    }

private:
    void backtrack(int index, const std::vector<int>& nums, 
                   std::vector<int>& currentSubset, 
                   std::vector<std::vector<int>>& result) {
        
        // Every state we reach is a valid subset, so add it to the result
        result.push_back(currentSubset);
        
        // Try adding the remaining elements one by one
        for (int i = index; i < nums.size(); ++i) {
            // Include the current element
            currentSubset.push_back(nums[i]);
            
            // Move to the next element
            backtrack(i + 1, nums, currentSubset, result);
            
            // Backtrack: remove the element to try other paths
            currentSubset.pop_back();
        }
    }
};
