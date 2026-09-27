#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<int> openBrackets;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                openBrackets.push(i);
            } 
            else if (s[i] == ')') {
                int start = openBrackets.top();
                openBrackets.pop();
                // Reverse the substring between the matching pair
                std::reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        
        // Construct the result by skipping the brackets
        std::string result = "";
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }
        
        return result;
    }
};
