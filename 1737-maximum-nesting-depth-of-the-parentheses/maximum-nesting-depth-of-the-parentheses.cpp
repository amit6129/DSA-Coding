#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxDepth(std::string s) {
        int current_depth = 0;
        int max_depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                current_depth++;
                max_depth = std::max(max_depth, current_depth);
            } else if (c == ')') {
                current_depth--;
            }
        }
        
        return max_depth;
    }
};
