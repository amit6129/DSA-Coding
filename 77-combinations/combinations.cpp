#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base Case: If the combination is complete
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Optimization/Pruning: 
        // Ensure there are enough elements left to choose from to reach size 'k'
        for (int i = start; i <= n - (k - current.size()) + 1; ++i) {
            current.push_back(i);             // Choose the element
            backtrack(i + 1, n, k, current, result); // Recurse with the next elements
            current.pop_back();              // Undo choice (backtrack)
        }
    }
};
