#include <string>
#include <algorithm>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        int score = 0;
        int depth = 0;
        
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // If the previous char was '(', we found "()" at current depth
                if (s[i - 1] == '(') {
                    score += (1 << depth); // equivalent to 2^depth
                }
            }
        }
        
        return score;
    }
};
