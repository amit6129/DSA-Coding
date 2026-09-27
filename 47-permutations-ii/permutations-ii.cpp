#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, std::vector<bool>& visited, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the element is already used in the current path
            if (visited[i]) continue;
            
            // Critical Skip Condition:
            // Skip if the current element is a duplicate of the previous one AND
            // the previous one has not been visited yet in this layer.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            visited[i] = true;
            current.push_back(nums[i]);
            
            backtrack(nums, visited, current, result);
            
            // Undo the choice (Backtrack)
            current.pop_back();
            visited[i] = false;
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> visited(nums.size(), false);
        
        // Essential step to bring duplicates next to each other
        std::sort(nums.begin(), nums.end());
        
        backtrack(nums, visited, current, result);
        return result;
    }
};
