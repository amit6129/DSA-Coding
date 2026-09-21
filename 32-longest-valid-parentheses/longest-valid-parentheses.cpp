#include <string>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.length();
        int max_len = 0;
        int left = 0, right = 0;

        // First pass: Left to Right
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = std::max(max_len, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;

        // Second pass: Right to Left
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = std::max(max_len, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return max_len;
    }
};
