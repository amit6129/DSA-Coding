class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // If the current element is greater than the remaining target, no need to proceed further
            if (candidates[i] > target) break;
            
            // Skip duplicates at the same level of recursion
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // Include the candidate and move forward
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Backtrack to explore other combinations
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sorting is crucial for handling duplicates and optimizing with a break condition
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
