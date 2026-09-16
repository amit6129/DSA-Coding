#include <vector>
#include <string>

class Solution {
private:
    void backtrack(std::vector<std::string>& result, std::string& current, int open_count, int close_count, int n) {
        // Base case: If the current string is complete, store it
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Rule 1: Add an opening parenthesis if we haven't reached 'n'
        if (open_count < n) {
            current.push_back('(');
            backtrack(result, current, open_count + 1, close_count, n);
            current.pop_back(); // Undo choice (backtrack)
        }

        // Rule 2: Add a closing parenthesis if it matches an open one
        if (close_count < open_count) {
            current.push_back(')');
            backtrack(result, current, open_count, close_count + 1, n);
            current.pop_back(); // Undo choice (backtrack)
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
