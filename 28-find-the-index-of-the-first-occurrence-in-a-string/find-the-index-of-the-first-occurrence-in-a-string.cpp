#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        
        // Loop through haystack only up to where the needle can physically fit
        for (int i = 0; i <= hLen - nLen; ++i) {
            // Compare a substring of length nLen starting at index i
            if (haystack.substr(i, nLen) == needle) {
                return i;
            }
        }
        
        return -1;
    }
};
