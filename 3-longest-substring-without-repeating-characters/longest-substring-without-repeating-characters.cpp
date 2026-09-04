#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Map to store the last seen index of each character.
        // Initialize all positions to -1 (not seen yet).
        // Using 256 size covers all standard ASCII characters.
        std::vector<int> char_map(256, -1);
        
        int max_length = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); ++end) {
            // If the character was seen before and is inside our current window
            if (char_map[s[end]] >= start) {
                start = char_map[s[end]] + 1;
            }
            
            // Record/update the index of the current character
            char_map[s[end]] = end;
            
            // Calculate window size and update max_length
            max_length = std::max(max_length, end - start + 1);
        }
        
        return max_length;
    }
};
