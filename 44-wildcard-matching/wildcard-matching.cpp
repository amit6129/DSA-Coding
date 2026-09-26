#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int matchIdx = 0;
        int starIdx = -1;
        
        int sLen = s.length();
        int pLen = p.length();
        
        while (sIdx < sLen) {
            // Case 1: Characters match, or pattern has '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Pattern has '*', record the checkpoint
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++; // Move pattern pointer past '*' to try matching empty sequence first
            }
            // Case 3: Last pattern pointer was '*', backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1; // Reset pattern pointer to position right after '*'
                matchIdx++;         // Consume one character from string to match the '*'
                sIdx = matchIdx;    // Reset string pointer to the next candidate position
            }
            // Case 4: No match, and no '*' checkpoint exists
            else {
                return false;
            }
        }
        
        // Check for remaining trailing '*' characters in the pattern
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }
        
        // If we reached the end of the pattern, it's a complete match
        return pIdx == pLen;
    }
};
