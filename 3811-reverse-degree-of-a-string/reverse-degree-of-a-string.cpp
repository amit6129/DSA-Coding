#include <string>

class Solution {
public:
    int reverseDegree(std::string s) {
        int totalDegree = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Calculate the 1-indexed position in the string
            int stringPos = i + 1;
            
            // Calculate position in the reversed alphabet ('a'=26, 'b'=25, ..., 'z'=1)
            int reversedAlphabetPos = 26 - (s[i] - 'a');
            
            // Add the product to the total degree
            totalDegree += reversedAlphabetPos * stringPos;
        }
        
        return totalDegree;
    }
};
