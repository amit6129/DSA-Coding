#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Sort the strings lexicographically
        std::sort(strs.begin(), strs.end());
        
        std::string first = strs.front();
        std::string last = strs.back();
        
        int i = 0;
        // Compare characters of the first and last string
        while (i < first.length() && i < last.length() && first[i] == last[i]) {
            i++;
        }
        
        return first.substr(0, i);
    }
};
