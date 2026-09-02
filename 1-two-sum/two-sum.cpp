#include <vector>
#include <unordered_map>
//Amit Deshmukh
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store value and its corresponding index
        std::unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If the complement is found, return the indices
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            
            // Otherwise, store the current value and index
            seen[nums[i]] = i;
        }
        
        // Return empty vector if no solution is found (per constraints, this won't happen)
        return {};
    }
};
