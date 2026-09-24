#include <vector>

class Solution {
private:
    void backtrack(int index, int target, std::vector<int>& candidates, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if the target is met, save the current combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Explore choices starting from the current index to avoid duplicate combinations
        for (int i = index; i < candidates.size(); ++i) {
            // Pruning: if the candidate exceeds the remaining target, stop exploring this branch
            if (candidates[i] > target) {
                continue;
            }
            
            // Include the current candidate
            current.push_back(candidates[i]);
            
            // Recurse with the reduced target. We pass 'i' again since elements can be reused.
            backtrack(i, target - candidates[i], candidates, current, result);
            
            // Backtrack to explore other possibilities
            current.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Optional: Sorting allows breaking the loop early for efficient pruning
        // std::sort(candidates.begin(), candidates.end());
        
        backtrack(0, target, candidates, current, result);
        return result;
    }
};
