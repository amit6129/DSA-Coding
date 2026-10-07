#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

class Solution {
private:
    bool isValid(const std::string& str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        if (s.empty()) return {""};

        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(s);

        bool foundMinimumRemovals = false;

        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                std::string current = q.front();
                q.pop();

                if (isValid(current)) {
                    result.push_back(current);
                    foundMinimumRemovals = true;
                }

                if (foundMinimumRemovals) continue;

                for (int j = 0; j < current.length(); ++j) {
                    if (current[j] != '(' && current[j] != ')') continue;

                    std::string nextState = current.substr(0, j) + current.substr(j + 1);

                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }

            if (foundMinimumRemovals) break;
        }

        return result;
    }
};
